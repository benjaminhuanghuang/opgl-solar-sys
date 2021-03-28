#pragma once

#include "SolarSystem.h"
#include "Model.h"
#include "Camera.h"
#include "Component.h"

#include <glm/glm.hpp>

/*
  Base class of stars, sprites...
  Define position, scale, rotation of entity
*/
class Entity
{

public:
  Entity(SolarSystem *sys);
  virtual ~Entity();

  // Add/remove components
	void AddComponent(class Component *component);
	void RemoveComponent(class Component *component);

  // Update function called from SolarSystem (not overridable)
  void Update(float deltaTime);
  // Updates all the components attached to the actor (not overridable)
  void UpdateComponents(float deltaTime);

  const glm::vec3 &getPosition() const
  {
    return mPosition;
  }
  void setPosition(const glm::vec3 &pos)
  {
    mPosition = pos;
  }

  float getRotX() const
  {
    return mRotX;
  }
  void setRotX(float rotX)
  {
    mRotX = rotX;
  }

  float getRotY() const
  {
    return mRotY;
  }
  void setRotY(float rotY)
  {
    mRotY = rotY;
  }

  float getRotZ() const
  {
    return mRotX;
  }
  void setRotZ(float rotZ)
  {
    mRotZ = rotZ;
  }

  float getScale() const
  {
    return mScale;
  }
  void setScale(float scale)
  {
    mScale = scale;
  }

  float getOrbitRadius() const {
    return mOrbitRadius;
  }

  void setOrbitRadius(float orbitRadius){
    mOrbitRadius = orbitRadius;
  }

    float getOrbitAngle() const {
    return mOrbitAngle;
  }

  void setOrbitRadius(float orbitAngle){
    mOrbitAngle = orbitAngle;
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

  float mOrbitRadius;
  float mOrbitAngle = 0.0f;
};
