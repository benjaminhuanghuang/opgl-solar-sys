#pragma once

#include "InputHandler.h"
#include "Constants.h"
#include "Renderer.h"
#include <glm/glm.hpp>

class Camera
{

public:
  static constexpr float SUPER_VELOCITY = 7.0f;
  static constexpr float VELOCITY = 1.0f;

  Camera(class Renderer *renderer);
  virtual ~Camera();

  void Update();

  float GetPitch() const
  {
    return mPitch;
  }
  float GetYaw() const
  {
    return mYaw;
  }
  float GetRoll() const
  {
    return mRoll;
  }

  glm::vec3 GetPosition() const
  {
    return mPosition;
  }

  void SetPosition(const glm::vec3 position)
  {
    mPosition = position;
  }

  void SetTarget(float x, float y, float z);

private:
  glm::vec3 mPosition;
  float mPitch;
  float mYaw;
  float mRoll;
  class Renderer *mRenderer;
};
