#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

class Renderer
{
public:
  Renderer(class SolarSystem *solar);
  ~Renderer();

  bool Initialize(int screenWidth, int screenHeight, const std::string &title);
  void Shutdown();
  void UnloadData();

  void Draw();

  void AddSprite(class SpriteComponent *sprite);
  void RemoveSprite(class SpriteComponent *sprite);

  void AddMeshComp(class MeshComponent *mesh);
  void RemoveMeshComp(class MeshComponent *mesh);

  class Texture *GetTexture(const std::string &fileName);
  class VertexArray *GetVertexArray(const std::string &fileName);

  void SetViewMatrix(const glm::mat4 &view) { mView = view; }

  const glm::vec3 &GetAmbientLight() const { return mAmbientLight; }

  void SetAmbientLight(const glm::vec3 &ambient) { mAmbientLight = ambient; }

  // DirectionalLight &GetDirectionalLight() { return mDirLight; }

  // const std::vector<class PointLightComponent *> &GetPointLights() const {
  //   return mPointLights;
  // }

  glm::vec3 Unproject(const glm::vec3 &screenPoint) const;

  // Gets start point and direction of screen vector
  void GetScreenDirection(glm::vec3 &outStart, glm::vec3 &outDir) const;

  GLFWwindow *getWindow() const { return mWindow; }
  float GetScreenWidth() const { return mScreenWidth; }
  float GetScreenHeight() const { return mScreenHeight; }
  
private:
  bool LoadShaders();
  void CreateSpriteVerts();

  // Owner of renderer
  class SolarSystem *mSolarSys;

  // ====== 2D Sprite shader
  // 2D Sprite shader
  class Shader *mSpriteShader;
  // Sprite vertex array
  class VertexArray *mSpriteVerts;

  // ====== 3D Mesh shader
  // Mesh shader
  class Shader *mMeshShader;
  // Mesh shader
  class Shader *mBasicMeshShader;
  // Skinned shader
  class Shader *mSkinnedShader;

  // Map of textures loaded
  std::unordered_map<std::string, class Texture *> mTextures;
  // Map of meshes loaded
  std::unordered_map<std::string, class VertexArray *> mVAs;

  // All the sprite components drawn
  std::vector<class SpriteComponent *> mSprites;

  // All mesh components drawn
  std::vector<class MeshComponent *> mMeshComps;

  // View/projection for 3D shaders
  glm::mat4 mView;
  glm::mat4 mProjection;

  // Lighting data
  glm::vec3 mAmbientLight;
  //DirectionalLight mDirLight;

  // Window
  GLFWwindow *mWindow;

  // Width/height
  int mScreenWidth;
  int mScreenHeight;
};