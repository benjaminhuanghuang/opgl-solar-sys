#pragma once

#include "Renderer.h"
#include "Gui.h"
#include "Camera.h"
#include "Entity.h"

class SolarSystem {
public:
	SolarSystem();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	Renderer *GetRenderer() { return mRenderer; }

private:
	void ProcessInput();
	void Update();

	void Draw();
	void LoadData();
	void UnloadData();


	class Renderer *mRenderer;

	unsigned int mTicksCount;
};