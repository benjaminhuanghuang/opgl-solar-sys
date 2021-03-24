#ifndef STAR_H
#define STAR_H

#include <GL/glew.h>

class Star
{
public:
  GLfloat radius, speed, selfSpeed;
  GLfloat distance;
  GLfloat rgbaColor[4];
  Star *parentStar;

  Star(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star *parent);
  virtual ~Star();
  
  void drawStar();
  virtual void draw() { drawStar(); }
  virtual void update(long timeSpan);
protected:
  GLfloat alphaSelf, alpha;
};

#endif /* STAR_H */