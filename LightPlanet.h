#ifndef LIGHT_PLANET_H
#define LIGHT_PLANET_H

#include "Planet.h"

class LightPlanet : public Planet
{
public:
  LightPlanet(GLfloat Radius, GLfloat Distance, GLfloat Speed, GLfloat SelfSpeed, Star *Parent, GLfloat rgbColor[]);
  void drawLight();

  void draw() override
  {
    drawLight();
    drawPlanet();
    drawStar();
  }
};

#endif /* LIGHT_PLANET_H */