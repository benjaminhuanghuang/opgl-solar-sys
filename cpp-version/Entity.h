#pragma once

#include "Model.h"
#include "Camera.h"

#include <glm/glm.hpp>

class Entity
{

public:
  Entity(Model* model, const glm::vec3 &position, float rotX, float rotY, float rotZ, float scale);

  void increatePosition(float dx, float dy, float dz);
  void increateRotation(float dx, float dy, float dz);

  void rotateAroundSun(float time, float orbitSpeed, float radius);

  Model *getModel() const;
  const glm::vec3 &getPosition() const;
  float getRotX() const;
  float getRotY() const;
  float getRotZ() const;
  float getScale() const;

  void setPosition(const glm::vec3 &position);
  void setRotX(float rotX);
  void setRotY(float rotY);
  void setRotZ(float rotZ);
  void setScale(float scale);

protected:
  float orbitalAngle = 0.0f;

  Model *model;
  glm::vec3 position;
  float rotX, rotY, rotZ;
  float scale;
};
