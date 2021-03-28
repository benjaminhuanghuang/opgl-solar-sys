// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "MoveComponent.h"
#include "Entity.h"
#include "Math.h"
#include "Planet.h"

MoveComponent::MoveComponent(Planet *owner, int updateOrder)
    : Component(owner, updateOrder),
      mAngularSpeed(0.0f),
      mOrbitSpeed(0.0f)
{
}

void MoveComponent::Update(float deltaTime)
{
  if (!Math::NearZero(mAngularSpeed))
  {
    float angle = mAngularSpeed * deltaTime;
    mOwner->setRotZ(mOwner->getRotZ() + angle);
  }
  if (!Math::NearZero(mOrbitSpeed))
  {
    float orbitalAngle = ((Planet *)mOwner)->getOrbitAngle() + mOrbitSpeed * deltaTime;
    ((Planet *)mOwner)->setOrbitAngle(orbitalAngle);
    float radius = ((Planet *)mOwner)->getOrbitRadius();
    mOwner->setPosition(glm::vec3(Constants::ORIGIN_X + radius * glm::cos(orbitalAngle), 0, Constants::ORIGIN_Z + radius * glm::sin(orbitalAngle)));
  }
}
