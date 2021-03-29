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
  GLfloat cube_vertices[] = {
      // Back
      -0.5, 0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 1.0,  // Back Top Left
      -0.5, -0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, // Back Bottom Left
      0.5, -0.5, -0.5, 0.0, 0.0, 0.0, 1.0, 0.0,  // Back Bottom Right
      0.5, 0.5, -0.5, 0.0, 0.0, 0.0, 1.0, 1.0,   // Back Top Right
      // Front
      -0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0,  // Front Top Left
      -0.5, -0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, // Front Bottom Left
      0.5, -0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 0.0,  // Front Bottom Right
      0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 1.0,   // Front Top Right
      // Right
      0.5, 0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 1.0,  // Right Top Left
      0.5, -0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, // Right Bottom Left
      0.5, -0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 0.0,  // Right Bottom Right
      0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 1.0,   // Right Top Right

      // Left
      -0.5, 0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 1.0,  // Left Top Left
      -0.5, -0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, // Left Bottom Left
      -0.5, -0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 0.0,  // Left Bottom Right
      -0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 1.0,   // Left Top Right

      // Top
      -0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0,  // Top Top Left
      -0.5, 0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, // Top Bottom Left
      0.5, 0.5, -0.5, 0.0, 0.0, 0.0, 1.0, 0.0,  // Top Bottom Right
      0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 1.0,   // Top Top Right
      // Bottom
      -0.5, -0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0,  // Bottom Top Lefts
      -0.5, -0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, // Bottom Bottom Lefts
      0.5, -0.5, -0.5, 0.0, 0.0, 0.0, 1.0, 0.0,  // Bottom Bottom Rights
      0.5, -0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 1.0,   // Bottom Top Rights
  };

  GLuint cube_indexes[] = {
      //Back face
      0, 1, 3,
      3, 1, 2,

      //Front face
      4, 5, 7,
      7, 5, 6,

      //Right face
      8, 9, 11,
      11, 9, 10,

      //Left face
      12, 13, 15,
      15, 13, 14,

      //Top face
      16, 17, 19,
      19, 17, 18,

      //Bottom face
      20, 21, 23,
      23, 21, 22};

  VertexArray* va = new VertexArray(cube_vertices, sizeof(cube_vertices) / 8 / sizeof(GLfloat), cube_indexes, sizeof(cube_indexes)/sizeof(GLuint));
  mesh->SetVertexArray(va);
  mesh->SetTexture(GetSolarSystem()->GetRenderer()->GetTexture("images/wood.png"));
}

Cube::~Cube()
{
  GetSolarSystem()->RemoveEntity(this);
}
