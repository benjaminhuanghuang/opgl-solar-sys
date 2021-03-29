
#pragma once
#include "Entity.h"
#include <string>

class Planet : public Entity
{
public:
  Planet(class SolarSystem *solar, const std::string& texture);
  ~Planet();

  float GetOrbitRadius() const
  {
    return mOrbitRadius;
  }

  void SetOrbitRadius(float orbitRadius)
  {
    mOrbitRadius = orbitRadius;
  }

  float GetOrbitAngle() const
  {
    return mOrbitAngle;
  }

  void SetOrbitAngle(float orbitAngle)
  {
    mOrbitAngle = orbitAngle;
  }

private:
  float mOrbitRadius;
  float mOrbitAngle = 0.0f;
};
