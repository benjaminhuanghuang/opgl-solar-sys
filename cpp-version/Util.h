#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Util
{
  std::vector<std::string> split(const std::string &s, const char &c);
  

  glm::mat4 CreateTransformationMatrix(const glm::vec3 &translation, float rx, float ry, float rz, float scale);
  
  glm::mat4 CreateViewMatrix(glm::vec3 cameraPos, float cameraPitch, float cameraYaw);
  

  // Create "Simple" View-Projection Matrix for 2D
  glm::mat4 CreateSimpleViewProj(float width, float height);
  
  bool NearZero(float val, float epsilon = 0.001f);
};
