#pragma once
#include "Camera.h"
#include "Component.h"
#include <vector>
#include <glm/glm.hpp>

/*
  Base class of stars, sprites...
  Define position, scale, rotation of entity
*/
class Entity
{

public:
  Entity(class SolarSystem *sys);
  virtual ~Entity();

  // Add/remove components
	void AddComponent(class Component *component);
	void RemoveComponent(class Component *component);

  // Update function called from SolarSystem (not overridable)
  void Update(float deltaTime);
  // Updates all the components attached to the actor (not overridable)
  void UpdateComponents(float deltaTime);

  SolarSystem *GetSolarSystem() { return mSolarSys; }

  const glm::vec3 &GetPosition() const
  {
    return mPosition;
  }
  void SetPosition(const glm::vec3 &pos)
  {
    mPosition = pos;
  }

  float GetRotX() const
  {
    return mRotX;
  }
  void SetRotX(float rotX)
  {
    mRotX = rotX;
  }

  float GetRotY() const
  {
    return mRotY;
  }
  void SetRotY(float rotY)
  {
    mRotY = rotY;
  }

  float GetRotZ() const
  {
    return mRotX;
  }
  void SetRotZ(float rotZ)
  {
    mRotZ = rotZ;
  }

  float GetScale() const
  {
    return mScale;
  }
  void SetScale(float scale)
  {
    mScale = scale;
  }

	void ComputeWorldTransform();
	const glm::mat4 &GetWorldTransform() const
	{
		return mWorldTransform;
	}

protected:
  SolarSystem *mSolarSys;
  glm::vec3 mPosition;
  float mRotX, mRotY, mRotZ;
  glm::mat4 mWorldTransform;
  float mScale;
  std::vector<class Component *> mComponents;
};
