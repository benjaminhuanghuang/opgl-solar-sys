#include <iostream>

#include "SolarSystem.h"
#include "InputHandler.h"
#include "Planet.h"
#include "Renderer.h"
#include "Gui.h"
#include "SpriteComponent.h"

SolarSystem::SolarSystem() : mRenderer(nullptr)
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
  Planet *a = new Planet(this);


  Entity *rader = new Entity(this);
	rader->SetPosition(glm::vec3(375.0f, -275.0f, 0.0f));
	rader->SetScale(0.75f);
	SpriteComponent *sc = new SpriteComponent(rader);
	sc->SetTexture(mRenderer->GetTexture("img/Radar.png"));
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
}

