#ifndef star_hpp

#define star_hpp

#include <GL/glut.h>

class Star {
public :

GLfloat radius;

GLfloat speed,selfSpeed;

GLfloat distance;

GLfloat rgbaColor[4];

Star * parentStar;

Star(GLfloat radius,GLfloatdistance,GLfloatspeed,GLfloatselfSpeed,Star*parent);

void drawStar();

virtual void draw() {drawStar();}

virtual void update(longtimeSpan);

protected:

GLfloat alphaSelf,alpha;

};

class Planet :public Star {
public:

   Planet(GLfloat radius, GLfloat distance,

          GLfloat speed,  GLfloat selfSpeed,

          Star* parent,GLfloatrgbColor[3]);

    void drawPlanet();

    virtual void draw() {drawPlanet(); drawStar(); }

};

class LightPlanet :public Planet {
public:

   LightPlanet(GLfloat Radius, GLfloat Distance,

                GLfloat Speed,  GLfloat SelfSpeed,

                Star*Parent, GLfloatrgbColor[]);

    void drawLight();

    virtual void draw() {drawLight(); drawPlanet(); drawStar(); }

};

#endif /* star_hpp */