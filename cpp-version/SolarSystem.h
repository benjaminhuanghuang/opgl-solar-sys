#pragma once

#include <vector>


class SolarSystem {
public:
	SolarSystem();
	bool Initialize();
	void RunLoop();
	void Shutdown();

  void AddEntity(class Entity *entity);
	void RemoveEntity(class Entity *engity);

	class Renderer *GetRenderer() { return mRenderer; }

private:
	void ProcessInput();
	void Update();

	void Draw();
	void LoadData();
	void UnloadData();

  	// All the entity(stars, sprite...) in the game
	std::vector<class Entity *> mEntities;
	class Renderer *mRenderer;

	unsigned int mTicksCount;
};