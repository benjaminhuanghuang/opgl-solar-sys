#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <GL/glew.h>

#include "Star.h"
#include "Planet.h"
#include "LightPlanet.h"

#define STARS_NUM 10

class SolarSystem
{
public:
  SolarSystem();
  ~SolarSystem();
  void onDisplay();
  void onUpdate();
  void onKeyboard(int key, int action);

private:
  Star *stars[STARS_NUM];
  // shoule be glm::vec3
  GLdouble viewX, viewY, viewZ;
  GLdouble centerX, centerY, centerZ;
  GLdouble upX, upY, upZ;
};

#endif

