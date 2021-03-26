// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Mesh.h"
#include <GL/glew.h>

Mesh::Mesh(const void *verts, unsigned int numVerts, const unsigned int *indices, unsigned int numIndices)
    : mNumVerts(numVerts), mNumIndices(numIndices)
{
  // Create vertex array
  glGenVertexArrays(1, &mVertexArray);
  glBindVertexArray(mVertexArray);

  unsigned vertexSize = 8 * sizeof(float);

  // Create vertex buffer
  glGenBuffers(1, &mVertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, numVerts * vertexSize, verts, GL_STATIC_DRAW);

  // Create index buffer
  glGenBuffers(1, &mIndexBuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(unsigned int), indices, GL_STATIC_DRAW);

  // Position is 3 floats
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, 0);
  // Normal is 3 floats
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertexSize,
                        reinterpret_cast<void *>(sizeof(float) * 3));
  // Texture coordinates is 2 floats
  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, vertexSize,
                        reinterpret_cast<void *>(sizeof(float) * 6));
}

Mesh::~Mesh()
{
  glDeleteBuffers(1, &mVertexBuffer);
  glDeleteBuffers(1, &mIndexBuffer);
  glDeleteVertexArrays(1, &mVertexArray);
}

void Mesh::SetActive()
{
  glBindVertexArray(mVertexArray);
}