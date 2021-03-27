#include <iostream>

#include "SolarSystem.h"
#include "InputHandler.h"

SolarSystem::SolarSystem() : mRenderer(nullptr)
{
}

bool SolarSystem::Initialize()
{
  // Create the renderer
  mRenderer = new Renderer(this);
  if (!mRenderer->Initialize(1280, 720, "OpenGL Salor Syatem"))
  {
    std::cout << "Failed to initialize renderer" << std::endl;
    delete mRenderer;
    mRenderer = nullptr;
    return false;
  }

  mTicksCount = glfwGetTime();

  return true;
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

  // Update(deltaTime);
}

void SolarSystem::Draw()
{
  mRenderer->Draw();
}

void SolarSystem::LoadData()
{
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

