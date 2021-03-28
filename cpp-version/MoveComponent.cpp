// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "MoveComponent.h"
#include "Entity.h"
#include "Util.h"
#include "Planet.h"

MoveComponent::MoveComponent(Planet *owner, int updateOrder)
    : Component(owner, updateOrder),
      mAngularSpeed(0.0f),
      mOrbitSpeed(0.0f)
{
}

void MoveComponent::Update(float deltaTime)
{
  if (!Util::NearZero(mAngularSpeed))
  {
    float angle = mAngularSpeed * deltaTime;
    mOwner->SetRotZ(mOwner->GetRotZ() + angle);
  }
  if (!Util::NearZero(mOrbitSpeed))
  {
    float orbitalAngle = ((Planet *)mOwner)->GetOrbitAngle() + mOrbitSpeed * deltaTime;
    ((Planet *)mOwner)->SetOrbitAngle(orbitalAngle);
    float radius = ((Planet *)mOwner)->GetOrbitRadius();
    mOwner->SetPosition(glm::vec3(Constants::ORIGIN_X + radius * glm::cos(orbitalAngle), 0, Constants::ORIGIN_Z + radius * glm::sin(orbitalAngle)));
  }
}
