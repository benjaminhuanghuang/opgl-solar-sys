
#pragma once
#include "Entity.h"
#include <string>

class Planet : public Entity
{
public:
  Planet(class SolarSystem *solar);
  ~Planet();

  float getOrbitRadius() const
  {
    return mOrbitRadius;
  }

  void setOrbitRadius(float orbitRadius)
  {
    mOrbitRadius = orbitRadius;
  }

  float getOrbitAngle() const
  {
    return mOrbitAngle;
  }

  void setOrbitAngle(float orbitAngle)
  {
    mOrbitAngle = orbitAngle;
  }

private:
  float mOrbitRadius;
  float mOrbitAngle = 0.0f;
};
