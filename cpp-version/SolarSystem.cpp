#include <iostream>

#include "SolarSystem.h"
#include "InputHandler.h"
#include "Planet.h"
#include "Renderer.h"
#include "Gui.h"
#include "SpriteComponent.h"
#include "Constants.h"
#include "Camera.h"
#include <glm/gtc/constants.hpp>

SolarSystem::SolarSystem() : mRenderer(nullptr), mGui(nullptr), mCamera(nullptr)
{
}

bool SolarSystem::Initialize()
{
  // Create the renderer
  mRenderer = new Renderer(this);
  if (!mRenderer->Initialize(1024, 768, "OpenGL Salor System"))
  {
    std::cout << "Failed to initialize renderer" << std::endl;
    delete mRenderer;
    mRenderer = nullptr;
    return false;
  }

  mTicksCount = glfwGetTime();

  mGui = new Gui(mRenderer);
  mCamera = new Camera(mRenderer);
  LoadData();
  return true;
}

void SolarSystem::AddEntity(Entity *entity)
{
		mEntities.emplace_back(entity);
}

void SolarSystem::RemoveEntity(Entity *entity)
{
	// Is it in actors?
	auto iter = std::find(mEntities.begin(), mEntities.end(), entity);
	if (iter != mEntities.end())
	{
		// Swap to end of vector and pop off (avoid erase copies)
		std::iter_swap(iter, mEntities.end() - 1);
		mEntities.pop_back();
	}
}


void SolarSystem::RunLoop()
{
  while (!glfwWindowShouldClose(mRenderer->getWindow()))
  {
    ProcessInput();

    Update();

    Draw();
  }
}

void SolarSystem::ProcessInput()
{ 
   // every object process input  
}

void SolarSystem::Update()
{
  // 
  float deltaTime = (glfwGetTime() - mTicksCount);
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}
	mTicksCount = glfwGetTime();

  mCamera->Update();

  for (auto entity : mEntities)
	{
		entity->Update(deltaTime);
	}
}

void SolarSystem::Draw()
{
  mRenderer->Draw();
}

void SolarSystem::LoadData()
{
  Planet *sun = new Planet(this, Constants::TEXTURE_SUN);
  sun->SetPosition(glm::vec3(Constants::D_FROM_EARTH_SUN, 0, -25.0));
  sun->SetScale(Constants::R_SUN);


  Planet *earth = new Planet(this, Constants::TEXTURE_EARTH);
  earth->SetPosition(glm::vec3(Constants::D_FROM_EARTH_EARTH, 0, -25.0));
  earth->SetScale(Constants::R_EARTH);

  Planet *jupiter = new Planet(this, Constants::TEXTURE_JUPITER);
  jupiter->SetPosition(glm::vec3(Constants::D_FROM_EARTH_JUPITER, 0, -25.0));
  jupiter->SetScale(Constants::R_JUPITER);


  Planet *mars = new Planet(this, Constants::TEXTURE_MARS);
  mars->SetPosition(glm::vec3(Constants::D_FROM_EARTH_MARS, 0, -25.0));
  mars->SetScale(Constants::R_MARS);

  Planet *mercury = new Planet(this, Constants::TEXTURE_MERCURY);
  mercury->SetPosition(glm::vec3(Constants::D_FROM_EARTH_MERCURY, 0, -25.0));
  mercury->SetScale(Constants::R_MERCURY);

  Planet *neptune = new Planet(this, Constants::TEXTURE_NEPTUNE);
  neptune->SetPosition(glm::vec3(Constants::D_FROM_EARTH_NEPTUNE, 0, -25.0));
  neptune->SetScale(Constants::R_NEPTUNE);

  Planet *saturn = new Planet(this, Constants::TEXTURE_SATURN);
  saturn->SetPosition(glm::vec3(Constants::D_FROM_EARTH_SATURN, 0, -25.0));
  saturn->SetScale(Constants::R_SATURN);

  Planet *venus = new Planet(this, Constants::TEXTURE_VENUS);
  venus->SetPosition(glm::vec3(Constants::D_FROM_EARTH_VENUS, 0, -25.0));
  venus->SetScale(Constants::R_VENUS);

  Planet *nranus = new Planet(this, Constants::TEXTURE_URANUS);
  nranus->SetPosition(glm::vec3(Constants::D_FROM_EARTH_URANUS, 0, -25.0));
  nranus->SetScale(Constants::R_URANUS);

  // Cube *cube = new Cube(this);

  // Show a 2D Radar
  Entity *rader = new Entity(this);
	rader->SetPosition(glm::vec3(375.0f, -275.0f, 0.0f));
	rader->SetScale(0.75f);
	SpriteComponent *sc = new SpriteComponent(rader);
	sc->SetTexture(mRenderer->GetTexture("images/Radar.png"));
}

void SolarSystem::UnloadData()
{
  if (mRenderer)
  {
    mRenderer->UnloadData();
  }
}

void SolarSystem::Shutdown()
{
  UnloadData();
  if (mRenderer)
  {
    mRenderer->Shutdown();
  }
  delete mRenderer;
  delete mGui;
  delete mCamera;
}

