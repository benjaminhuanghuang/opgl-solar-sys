#pragma once

#include "Shader.h"
#include "Camera.h"
#include "Math.h"
#include "Light.h"

class PlanetShader : public Shader {

public:
    PlanetShader();

    void bindAttributes() override;
    void getAllUniformLocations() override;

    void loadTransformMatrix(const glm::mat4& matrix);
    void loadProjectionMatrix(const glm::mat4& matrix);
    void loadViewMatrix(Camera* camera);
    void loadLight(Light* light);
    void loadShineVariables(float damper, float reflectivity);

private:
    GLint locationTransform;
    GLint locationProjection;
    GLint locationView;
    GLint locationLightPosition;
    GLint locationLightColor;
    GLint locationShineDamper;
    GLint locationReflectivity;

};
