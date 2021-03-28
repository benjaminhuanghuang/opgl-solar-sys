#include <iostream>
#include "Renderer.h"
#include "Math.h"
#include "Shader.h"
#include "Mesh.h"

Renderer::Renderer(SolarSystem *solar) : mSolarSys(solar), mSpriteShader(nullptr), mMeshShader(nullptr)
{
}

Renderer::~Renderer()
{
}

bool Renderer::Initialize(int screenWidth, int screenHeight, const std::string &title)
{
  if (!glfwInit())
  {
    std::cout << "Failed to initialize GLFW." << std::endl;
    return false;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  mWindow = glfwCreateWindow(screenWidth, screenHeight, title.c_str(), NULL, NULL);
  if (!mWindow)
  {
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(mWindow);

  // Initialize GLEW
  glewExperimental = true; // Needed for core profile
  if (glewInit() != GLEW_OK)
  {
    glfwTerminate();
    return false;
  }
  glfwGetFramebufferSize(mWindow, &mScreenWidth, &mScreenHeight);

  glViewport(0, 0, mScreenWidth, mScreenHeight);

  glfwSetKeyCallback(mWindow, InputHandler::keyCallback);
  glfwSetMouseButtonCallback(mWindow, InputHandler::mouseButtonCallback);
  glfwSetCursorPosCallback(mWindow, InputHandler::cursorPositionCallback);

  // Blend
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  //
  glEnable(GL_DEPTH_TEST);
  // On some platforms, GLEW will emit a benign error code,
  // so clear it
  glGetError();

  // Make sure we can create/compile shaders
  // if (!LoadShaders())
  // {
  //   std::cout << "Failed to load shaders.";
  //   return false;
  // }

  // Create quad for drawing sprites
  CreateSpriteVerts();

  return true;
}

void Renderer::Shutdown()
{
  glfwDestroyWindow(mWindow);
  glfwTerminate();
}

void Renderer::UnloadData()
{
}

void Renderer::Draw()
{
  // Set the clear color to light grey
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  // Clear the color buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Draw mesh components
  // Enable depth buffering/disable alpha blend
  glEnable(GL_DEPTH_TEST);
  glDisable(GL_BLEND);
  // Set the mesh shader active
  //mMeshShader->SetActive();
  // Update view-projection matrix
  //mMeshShader->SetMatrixUniform("uViewProj", mView * mProjection);
  // // Update lighting uniforms
  // SetLightUniforms(mMeshShader);
  // for (auto mc : mMeshComps)
  // {
  //   mc->Draw(mMeshShader);
  // }

  // Draw all sprite components
  // Disable depth buffering
  glDisable(GL_DEPTH_TEST);
  // Enable alpha blending on the color buffer
  glEnable(GL_BLEND);
  glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);
  glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);

  // Set shader/vao as active
  //mSpriteShader->SetActive();
  //mSpriteVerts->SetActive();
  // for (auto sprite : mSprites)
  // {
  //   sprite->Draw(mSpriteShader);
  // }

  // Swap the buffers
  glfwSwapBuffers(mWindow);
  glfwPollEvents();
}
void Renderer::AddMeshComp(MeshComponent *mesh)
{
	mMeshComps.emplace_back(mesh);
}

void Renderer::RemoveMeshComp(MeshComponent *mesh)
{
	auto iter = std::find(mMeshComps.begin(), mMeshComps.end(), mesh);
	mMeshComps.erase(iter);
}

Texture *Renderer::GetTexture(const std::string &fileName)
{
	Texture *tex = nullptr;
	auto iter = mTextures.find(fileName);
	if (iter != mTextures.end())
	{
		tex = iter->second;
	}
	else
	{
		tex = new Texture();
		if (tex->Load(fileName))
		{
			mTextures.emplace(fileName, tex);
		}
		else
		{
			delete tex;
			tex = nullptr;
		}
	}
	return tex;
}

Mesh *Renderer::GetMesh(const std::string &fileName)
{
	Mesh *m = nullptr;
	auto iter = mMeshes.find(fileName);
	if (iter != mMeshes.end())
	{
		m = iter->second;
	}
	else
	{
		m = new Mesh();
		if (m->Load(fileName, this))
		{
			mMeshes.emplace(fileName, m);
		}
		else
		{
			delete m;
			m = nullptr;
		}
	}
	return m;
}

bool Renderer::LoadShaders()
{
  //======= 2D shader, view, proj
  mSpriteShader = new Shader();
  if (!mSpriteShader->Load("Shaders/Sprite.vert", "Shaders/Sprite.frag"))
  {
    return false;
  }
  mSpriteShader->SetActive();

  glm::mat4 viewProj = Math::CreateSimpleViewProj(mScreenWidth, mScreenHeight);
  mSpriteShader->SetMatrixUniform("uViewProj", viewProj);

  //======== 3D shader, view, proj
  mMeshShader = new Shader();
  if (!mMeshShader->Load("Shaders/Phong.vert", "Shaders/Phong.frag"))
  {
    return false;
  }

  mMeshShader->SetActive();

  //== Set the view-projection matrix
  mView = glm::lookAt(glm::vec3(0, 0, 0), // eye is at (4,3,3), in World Space
                      glm::vec3(0, 0, 0), // looks at target at origin
                      glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
  );

  // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
  mProjection = glm::perspective(glm::radians(45.0f), (float)mScreenWidth / (float)mScreenHeight, 25.0f, 100.0f);

  mMeshShader->SetMatrixUniform("uViewProj", mView * mProjection);
  return true;
}

/*
	2D sprite verts
*/
void Renderer::CreateSpriteVerts()
{
  float vertices[] = {
      -0.5f, 0.5f, 0.f, 0.f, 0.f, 0.0f, 0.f, 0.f, // top left
      0.5f, 0.5f, 0.f, 0.f, 0.f, 0.0f, 1.f, 0.f,  // top right
      0.5f, -0.5f, 0.f, 0.f, 0.f, 0.0f, 1.f, 1.f, // bottom right
      -0.5f, -0.5f, 0.f, 0.f, 0.f, 0.0f, 0.f, 1.f // bottom left
  };

  unsigned int indices[] = {
      0, 1, 2,
      2, 3, 0};

  mSpriteVerts = new Mesh(vertices, 4, indices, 6);
}
