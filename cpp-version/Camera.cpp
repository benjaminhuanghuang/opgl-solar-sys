#include <iostream>
#include "Camera.h"
#include "Renderer.h"
#include "Util.h"

Camera::Camera(Renderer *renderer)
    : mYaw(0.0f), mPitch(0.0f), mRenderer(renderer),
      mPosition(glm::vec3(Constants::ORIGIN_X, 0, Constants::R_SUN + 400))
{
}

Camera::~Camera()
{
}

void Camera::Update()
{
  if (InputHandler::isKeyPressed(GLFW_KEY_LEFT_CONTROL))
  {
    float dx = SUPER_VELOCITY * glm::sin(mYaw);
    float dy = SUPER_VELOCITY * mPitch;
    float dz = SUPER_VELOCITY * glm::cos(mYaw);

    if (InputHandler::isKeyPressed(GLFW_KEY_W))
    {
      mPosition.x += dx;
      mPosition.y -= dy;
      mPosition.z -= dz;
    }
    if (InputHandler::isKeyPressed(GLFW_KEY_S))
    {
      mPosition.x -= dx;
      mPosition.y += dy;
      mPosition.z += dz;
    }
    if (InputHandler::isKeyPressed(GLFW_KEY_D))
    {
      mPosition.x += dz;
      mPosition.z += dx;
    }
    if (InputHandler::isKeyPressed(GLFW_KEY_A))
    {
      mPosition.x -= dz;
      mPosition.z -= dx;
    }

    if (InputHandler::isKeyPressed(GLFW_KEY_LEFT_SHIFT))
      mPosition.y -= SUPER_VELOCITY;
    if (InputHandler::isKeyPressed(GLFW_KEY_SPACE))
      mPosition.y += SUPER_VELOCITY;
  }
  else
  {
    float dx = VELOCITY * glm::sin(mYaw);
    float dy = VELOCITY * mPitch;
    float dz = VELOCITY * glm::cos(mYaw);

    if (InputHandler::isKeyPressed(GLFW_KEY_W))
    {
      mPosition.x += dx;
      mPosition.y -= dy;
      mPosition.z -= dz;
    }
    if (InputHandler::isKeyPressed(GLFW_KEY_S))
    {
      mPosition.x -= dx;
      mPosition.y += dy;
      mPosition.z += dz;
    }
    if (InputHandler::isKeyPressed(GLFW_KEY_D))
    {
      mPosition.x += dz;
      mPosition.z += dx;
    }
    if (InputHandler::isKeyPressed(GLFW_KEY_A))
    {
      mPosition.x -= dz;
      mPosition.z -= dx;
    }

    if (InputHandler::isKeyPressed(GLFW_KEY_LEFT_SHIFT))
      mPosition.y -= VELOCITY;
    if (InputHandler::isKeyPressed(GLFW_KEY_SPACE))
      mPosition.y += VELOCITY;
  }

  if (InputHandler::isKeyPressed(GLFW_KEY_UP))
    mPitch -= VELOCITY / 100.0f;
  if (InputHandler::isKeyPressed(GLFW_KEY_DOWN))
    mPitch += VELOCITY / 100.0f;
  if (InputHandler::isKeyPressed(GLFW_KEY_LEFT))
    mYaw -= VELOCITY / 100.0f;
  if (InputHandler::isKeyPressed(GLFW_KEY_RIGHT))
    mYaw += VELOCITY / 100.0f;

  glm::mat4 view = Util::CreateViewMatrix(mPosition, mPitch, mYaw);
  mRenderer->SetViewMatrix(view);
}

void Camera::SetTarget(float x, float y, float z)
{
  SetPosition(glm::vec3(x, y, z));
  mPitch = 0.0f;
  mYaw = 0.0f;
}
