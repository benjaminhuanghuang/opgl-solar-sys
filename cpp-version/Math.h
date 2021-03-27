#pragma once

#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Math {

public:
    static glm::mat4 CreateTransformationMatrix(const glm::vec3& translation, float rx, float ry, float rz, float scale);
    static glm::mat4 CreateViewMatrix(glm::vec3 cameraPos, float cameraPitch, float cameraYaw);
    static glm::mat4 CreateSimpleViewProj(float width, float height);
};
