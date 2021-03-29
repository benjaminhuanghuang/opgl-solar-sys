// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------
#include "Renderer.h"
#include "Cube.h"
#include "MeshComponent.h"
#include "MoveComponent.h"
#include "SolarSystem.h"
#include "VertexArray.h"

Cube::Cube(SolarSystem *solar) : Entity(solar)
{
  // Initialize to random position/orientation

  // MeshComponent
  MeshComponent *mesh = new MeshComponent(this);
  mesh->SetVertexArray(GetSolarSystem()->GetRenderer()->GetVertexArray("objs/cube.obj"));
  mesh->SetTexture(GetSolarSystem()->GetRenderer()->GetTexture("images/wood.png"));

  SetRotX(10);
  SetRotY(10);
  SetRotZ(10);

    // Create a move component, and set  speed
  MoveComponent *move = new MoveComponent(this);
  move->SetAngularSpeed(0.50f);
  move->SetOrbitSpeed(0.0f);
}

Cube::~Cube()
{
  GetSolarSystem()->RemoveEntity(this);
}
