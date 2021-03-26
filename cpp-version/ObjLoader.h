#pragma once
#include "RawModel.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

class OBJLoader
{

public:
  static Mesh* LoadMesh(const std::string &fileName);

private:
  static void processVertex(std::vector<std::string> const &vertexData,
                            std::vector<glm::vec3> const &positions,
                            std::vector<glm::vec2> const &texCoords,
                            std::vector<glm::vec3> const &normals,
                            std::vector<GLfloat>& vertices,
                            std::vector<GLuint>& indices);
};