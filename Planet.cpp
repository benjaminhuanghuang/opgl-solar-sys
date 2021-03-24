#include "Planet.h"
Planet::Planet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star *parent, GLfloat rgbColor[3]) 
  : Star(radius, distance, speed, selfSpeed, parent)
{
  rgbaColor[0] = rgbColor[0];

  rgbaColor[1] = rgbColor[1];

  rgbaColor[2] = rgbColor[2];

  rgbaColor[3] = 1.0f;
}

void Planet::drawPlanet()
{
  GLfloat mat_ambient[] = {0.0f, 0.0f, 0.5f, 1.0f};

  GLfloat mat_diffuse[] = {0.0f, 0.0f, 0.5f, 1.0f};

  GLfloat mat_specular[] = {0.0f, 0.0f, 1.0f, 1.0f};

  GLfloat mat_emission[] = {rgbaColor[0], rgbaColor[1], rgbaColor[2], rgbaColor[3]};

  GLfloat mat_shininess = 90.0f;

  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); //设置材质属性，接下来进行的绘制使用的都是使用指定的材质属性

  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

  glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
}