#include "Star.h"

#include <cmath>

#define PI 3.1415926535

Star::Star(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star *parent) : radius(radius),
                                                                                               selfSpeed(selfSpeed),
                                                                                               distance(distance),
                                                                                               alphaSelf(0),
                                                                                               alpha(0)

{

  for (int i = 0; i < 4; i++)
  {
    this->rgbaColor[i] = 1.0f;
  }
  this->parentStar = parent;

  if (speed > 0)

  {
    this->speed = 360.0f / speed;
  }
  else
  {
    this->speed = 0.0f;
  }
}

void Star::drawStar()
{
  glEnable(GL_LINE_SMOOTH); //设置绘制直线的时候平滑处理
  glEnable(GL_BLEND);       //设置颜色叠加模式，假如没有这个设置alpha不透明度是没有效果的，也就不会出现半透明颜色叠加效果
  int n = 1440;

  glPushMatrix(); //弹入矩阵，默认弹入的是单位矩阵，接下来的glRotatef，glTranslatef都会在堆栈顶部的矩阵的基础上进行，最后的glPopMatrix();是可选的，弹出矩阵后弹出的矩阵就消失了，接下来是在堆栈顶部的一个新的矩阵的基础上进行调整，也就是弹出矩阵下面的矩阵
  {
    if (parentStar != 0 && parentStar->distance > 0)
    {
      glRotatef(parentStar->alpha, 0, 0, 1);

      glTranslatef(parentStar->distance, 0.0, 0.0);
    }

    glBegin(GL_LINES);

    for (int i = 0; i < n; ++i)

      glVertex2f(distance * cos(2 * PI * i / n),

                 distance * sin(2 * PI * i / n));

    glEnd();

    glRotatef(alpha, 0, 0, 1);

    glTranslatef(distance, 0.0, 0.0);

    glRotatef(alphaSelf, 0, 0, 1);

    glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);

    glutSolidSphere(radius, 40, 32); //在调整过的几何变换矩阵基础上进行绘制球体，三个参数是半径，经度线的条数，和纬度线的条数
  }

  glPopMatrix();
}

void Star::update(long timeSpan)
{
  alpha += timeSpan * speed;
  alphaSelf += selfSpeed;
}
