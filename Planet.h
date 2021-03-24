#ifndef PLANET_H
#define PLANET_H

#include "Star.h"


class Planet : public Star
{
public:
  Planet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star *parent, GLfloat rgbColor[3]);
  
  void drawPlanet();
  
  void draw() override
  {
    drawPlanet();
    drawStar();
  }
};

#endif /* PLANT_H */