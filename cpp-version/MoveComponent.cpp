// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "MoveComponent.h"
#include "Entity.h"

MoveComponent::MoveComponent(Entity *owner, int updateOrder)
    : Component(owner, updateOrder), mAngularSpeed(0.0f), mForwardSpeed(0.0f)
{
}

void MoveComponent::Update(float deltaTime)
{

  if (!glm::ne(mAngularSpeed))
  {
    Quaternion rot = mOwner->GetRotation();
    float angle = mAngularSpeed * deltaTime;
    // Create quaternion for incremental rotation
    // (Rotate about up axis)
    Quaternion inc(Vector3::UnitZ, angle);
    // Concatenate old and new quaternion
    rot = Quaternion::Concatenate(rot, inc);
    mOwner->SetRotation(rot);
  }

  float orbitalAngle += orbitSpeed * deltaTime;
  float radius = mOwner-> 
  setPosition(glm::vec3(Constants::ORIGIN_X + radius * glm::cos(orbitalAngle), 0, Constants::ORIGIN_Z + radius * glm::sin(orbitalAngle)));
}
