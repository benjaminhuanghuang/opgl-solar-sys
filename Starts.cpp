#include"Stars.h"

#include<cmath>

 

#define PI3.1415926535

 

Star::Star(GLfloatradius, GLfloat distance,

           GLfloat speed,  GLfloat selfSpeed,

           Star* parent) {
    this->radius = radius;

    this->selfSpeed = selfSpeed;

    this->alphaSelf = this->alpha = 0;

    this->distance = distance;

 

    for (int i = 0; i < 4; i++)

        this->rgbaColor[i] = 1.0f;

 

    this->parentStar = parent;

    if (speed > 0)

        this->speed = 360.0f / speed;

    else

        this->speed = 0.0f;

}

 

voidStar::drawStar() {
 

    glEnable(GL_LINE_SMOOTH);//设置绘制直线的时候平滑处理

    glEnable(GL_BLEND);//设置颜色叠加模式，假如没有这个设置alpha不透明度是没有效果的，也就不会出现半透明颜色叠加效果

 

    int n = 1440;

 

    glPushMatrix();//弹入矩阵，默认弹入的是单位矩阵，接下来的glRotatef，glTranslatef都会在堆栈顶部的矩阵的基础上进行，最后的glPopMatrix();是可选的，弹出矩阵后弹出的矩阵就消失了，接下来是在堆栈顶部的一个新的矩阵的基础上进行调整，也就是弹出矩阵下面的矩阵

 

    {
        if (parentStar != 0 &&parentStar->distance > 0) {
            glRotatef(parentStar->alpha, 0,0, 1);

           glTranslatef(parentStar->distance, 0.0, 0.0);

        }

        glBegin(GL_LINES);

        for(int i=0; i<n; ++i)

            glVertex2f(distance * cos(2 * PI * i /n),

                       distance * sin(2 * PI *i / n));

        glEnd();

        glRotatef(alpha, 0, 0, 1);

        glTranslatef(distance, 0.0, 0.0);

 

        glRotatef(alphaSelf, 0, 0, 1);

 

        glColor3f(rgbaColor[0], rgbaColor[1],rgbaColor[2]);

        glutSolidSphere(radius, 40, 32);//在调整过的几何变换矩阵基础上进行绘制球体，三个参数是半径，经度线的条数，和纬度线的条数

    }

    glPopMatrix();

}

 

voidStar::update(long timeSpan) {
    alpha += timeSpan * speed;

    alphaSelf += selfSpeed;

}

 

 

Planet::Planet(GLfloatradius, GLfloat distance,

               GLfloat speed,  GLfloat selfSpeed,

               Star* parent, GLfloatrgbColor[3]) :

Star(radius,distance, speed, selfSpeed, parent) {
    rgbaColor[0] = rgbColor[0];

    rgbaColor[1] = rgbColor[1];

    rgbaColor[2] = rgbColor[2];

    rgbaColor[3] = 1.0f;

}

 

void Planet::drawPlanet(){
    GLfloat mat_ambient[]  = {0.0f, 0.0f, 0.5f, 1.0f};

    GLfloat mat_diffuse[]  = {0.0f, 0.0f, 0.5f, 1.0f};

    GLfloat mat_specular[] = {0.0f, 0.0f, 1.0f,1.0f};

    GLfloat mat_emission[] = {rgbaColor[0],rgbaColor[1], rgbaColor[2], rgbaColor[3]};

    GLfloat mat_shininess  = 90.0f;

 

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);//设置材质属性，接下来进行的绘制使用的都是使用指定的材质属性

    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);

    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);

    glMaterialfv(GL_FRONT, GL_EMISSION,  mat_emission);

    glMaterialf (GL_FRONT, GL_SHININESS,mat_shininess);

}

 

LightPlanet::LightPlanet(GLfloatradius,    GLfloat distance, GLfloatspeed,

                         GLfloat selfSpeed,Star* parent,   GLfloat rgbColor[3]) :

Planet(radius,distance, speed, selfSpeed, parent, rgbColor) {
    ;

}

 

void LightPlanet::drawLight() {
 

   GLfloat light_position[] = {0.0f, 0.0f, 0.0f, 1.0f};//这里是设定光源属性，一旦设定了光源属性，那么之后绘制的集合图形都会沿用这个设定，除非重新调用onDisplay(),在onDisplay()调用了glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);

glClearColor(.7f, .7f,.7f, .1f);清除了缓冲区，也就是把屏幕上的东西清除干净了，貌似把所有的设定也都清除干净了

    GLfloat light_ambient[]  = {0.0f, 0.0f, 0.0f, 1.0f};

    GLfloat light_diffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};

    GLfloat light_specular[] = {1.0f, 1.0f,1.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION,light_position);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);

    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);

    glLightfv(GL_LIGHT0, GL_SPECULAR,light_specular);//

}
