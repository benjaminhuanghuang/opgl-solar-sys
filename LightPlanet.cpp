#include "LightPlanet.h"

LightPlanet::LightPlanet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star *parent, GLfloat rgbColor[3])
    : Planet(radius, distance, speed, selfSpeed, parent, rgbColor)
{
}

void LightPlanet::drawLight()
{

  GLfloat light_position[] = {0.0f, 0.0f, 0.0f, 1.0f}; //这里是设定光源属性，一旦设定了光源属性，那么之后绘制的集合图形都会沿用这个设定，除非重新调用onDisplay(),在onDisplay()调用了glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);

  glClearColor(.7f, .7f, .7f, .1f);

  GLfloat light_ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};

  GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};

  GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};

  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}
