// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Planet.h"
#include "MeshComponent.h"
#include "MoveComponent.h"
#include "SolarSystem.h"
#include "Renderer.h"

Planet::Planet(SolarSystem *solar) : Entity(solar)
{
  // Initialize to random position/orientation

  // MeshComponent
  MeshComponent *mesh = new MeshComponent(this);
  mesh->SetVertexArray(GetSolarSystem()->GetRenderer()->GetVertexArray("obj/sphere.obj"));

  // Create a move component, and set  speed
  MoveComponent *move = new MoveComponent(this);
  move->SetAngularSpeed(5.0f);
  move->SetOrbitSpeed(5.0f);
}

Planet::~Planet()
{
  GetSolarSystem()->RemoveEntity(this);
}
