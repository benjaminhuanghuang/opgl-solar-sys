// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------
#include "Renderer.h"
#include "Planet.h"
#include "MeshComponent.h"
#include "MoveComponent.h"
#include "SolarSystem.h"


Planet::Planet(SolarSystem *solar) : Entity(solar)
{
  // Initialize to random position/orientation

  // MeshComponent
  MeshComponent *mesh = new MeshComponent(this);
  mesh->SetVertexArray(GetSolarSystem()->GetRenderer()->GetVertexArray("objs/sphere.obj"));
  mesh->SetTexture(GetSolarSystem()->GetRenderer()->GetTexture("images/earthTexture.jpeg"));

  // Create a move component, and set  speed
  MoveComponent *move = new MoveComponent(this);
  move->SetAngularSpeed(0.1f);
  move->SetOrbitSpeed(0.0f);
}

Planet::~Planet()
{
  GetSolarSystem()->RemoveEntity(this);
}
