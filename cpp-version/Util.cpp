#include "Util.h"

namespace Util
{
  std::vector<std::string> split(const std::string &s, const char &c)
  {
    std::string buff{""};
    std::vector<std::string> v;

    for (auto n : s)
    {
      if (n != c)
        buff += n;
      else if (n == c && buff != "")
      {
        v.push_back(buff);
        buff = "";
      }
    }
    if (buff != "")
      v.push_back(buff);

    return v;
  }

  glm::mat4 CreateTransformationMatrix(const glm::vec3 &translation, float rx, float ry, float rz, float scale)
  {
    glm::mat4 matrix(1.0f);
    matrix = glm::translate(matrix, translation);
    matrix = glm::rotate(matrix, rx, glm::vec3(1, 0, 0));
    matrix = glm::rotate(matrix, ry, glm::vec3(0, 1, 0));
    matrix = glm::rotate(matrix, rz, glm::vec3(0, 0, 1));
    matrix = glm::scale(matrix, glm::vec3(scale, scale, scale));

    return matrix;
  }

  glm::mat4 CreateViewMatrix(const glm::vec3 &cameraPos, float cameraPitch, float cameraYaw)
  {
    glm::mat4 view(1.0f);
    view = glm::rotate(view, cameraPitch, glm::vec3(1, 0, 0)); // X
    view = glm::rotate(view, cameraYaw, glm::vec3(0, 1, 0));   // Y
    glm::vec3 negativeCameraPos = glm::vec3(-cameraPos.x, -cameraPos.y, -cameraPos.z);
    view = glm::translate(view, negativeCameraPos);

    return view;
  }

  // Create "Simple" View-Projection Matrix for 2D
  glm::mat4 CreateSimpleViewProj(float width, float height)
  {
    float temp[16] =
        {
            2.0f / width, 0.0f, 0.0f, 0.0f,
            0.0f, 2.0f / height, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 1.0f};
    return glm::make_mat4(temp);
  }

  bool NearZero(float val, float epsilon)
  {
    return (fabs(val) <= epsilon);
  }
};
