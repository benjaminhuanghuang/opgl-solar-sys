#include "SolarSystem.h"

#define REST 700

#define REST_Z(REST)

#define REST_Y(-REST)

//这里猜想是将REST赋值给REST_Z和REST_Y

 

void SolarSystem::onDisplay()//当画面更新的时候执行这个函数，同时也可以手动调用

 {
    glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);//将颜色缓冲区和深度缓冲区清除，以便自己重新更新这两个缓冲区的数值

    glClearColor(.7f, .7f, .7f, .1f);

    glMatrixMode(GL_PROJECTION);//设置接下来将要更改的矩阵，这里把接下来将要更改的矩阵设置为投影矩阵

    glLoadIdentity();//将投影矩阵设置成单位矩阵

    gluPerspective(75.0f, 1.0f, 1.0f,40000000);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    gluLookAt(viewX, viewY, viewZ, centerX,centerY, centerZ, upX, upY, upZ);

 

    glEnable(GL_LIGHT0);

    glEnable(GL_LIGHTING);

    glEnable(GL_DEPTH_TEST);

 

    for (int i=0; i<STARS_NUM; i++)

        stars[i]->draw();

 

    glutSwapBuffers();

}

 

#define TIMEPAST1

voidSolarSystem::onUpdate() {
 

    for (int i=0; i<STARS_NUM; i++)

        stars[i]->update(TIMEPAST);

 

    this->onDisplay();

}

 

#define OFFSET20

voidSolarSystem::onKeyboard(unsigned char key, int x, int y) {
 

    switch (key)    {
        case 'w': viewY += OFFSET; break;

        case 's': viewZ += OFFSET; break;

        case 'S': viewZ -= OFFSET; break;

        case 'a': viewX -= OFFSET; break;

        case 'd': viewX += OFFSET; break;

        case 'x': viewY -= OFFSET; break;

        case 'r':

            viewX = 0; viewY = REST_Y; viewZ =REST_Z;

            centerX = centerY = centerZ = 0;

            upX = upY = 0; upZ = 1;

            break;

        case 27: exit(0); break;//退出程序，27不知道对应的是哪个键

        default: break;

    }

 

}

//设置宏，对应着默认的小行星的一些属性，包括半径，自传速度，公转速度

#defineSUN_RADIUS 48.74

#defineMER_RADIUS  7.32

#defineVEN_RADIUS 18.15

#defineEAR_RADIUS 19.13

#defineMOO_RADIUS  6.15

#defineMAR_RADIUS 10.19

#defineJUP_RADIUS 42.90

#defineSAT_RADIUS 36.16

#defineURA_RADIUS 25.56

#defineNEP_RADIUS 24.78

 

#defineMER_DIS   62.06

#defineVEN_DIS  115.56

#defineEAR_DIS  168.00

#defineMOO_DIS   26.01

#defineMAR_DIS  228.00

#define JUP_DIS  333.40

#defineSAT_DIS  428.10

#define URA_DIS848.00

#define NEP_DIS949.10

 

#defineMER_SPEED   87.0

#defineVEN_SPEED  225.0

#defineEAR_SPEED  365.0

#defineMOO_SPEED   30.0

#defineMAR_SPEED  687.0

#defineJUP_SPEED 1298.4

#defineSAT_SPEED 3225.6

#defineURA_SPEED 3066.4

#defineNEP_SPEED 6014.8

 

#defineSELFROTATE 3

 

enum STARS {Sun,Mercury, Venus, Earth, Moon,

    Mars, Jupiter, Saturn, Uranus, Neptune};

 

#defineSET_VALUE_3(name, value0, value1, value2) \

                   ((name)[0])=(value0),((name)[1])=(value1), ((name)[2])=(value2)

*//这是一种语法，是一种静态模板的写法，将value0,value1,value2赋值给数组name的第一个值，第二个值，第三个值

SolarSystem::SolarSystem(){
 

    viewX = 0;

    viewY = REST_Y;

    viewZ = REST_Z;

    centerX = centerY = centerZ = 0;

    upX = upY = 0;

    upZ = 1;

 

    GLfloat rgbColor[3] = {1, 0, 0};

stars[Sun]     = newLightPlanet(SUN_RADIUS, 0, 0, SELFROTATE, 0, rgbColor);

//Sun是一个枚举，定义在enum STARS {Sun, Mercury, Venus, Earth, Moon,

    Mars, Jupiter,Saturn, Uranus, Neptune};，其值为0

 

 

    SET_VALUE_3(rgbColor, .2, .2, .5);

    stars[Mercury] = new Planet(MER_RADIUS,MER_DIS, MER_SPEED, SELFROTATE, stars[Sun], rgbColor);

 

    SET_VALUE_3(rgbColor, 1, .7, 0);

    stars[Venus]   = new Planet(VEN_RADIUS, VEN_DIS, VEN_SPEED,SELFROTATE, stars[Sun], rgbColor);

 

    SET_VALUE_3(rgbColor, 0, 1, 0);

    stars[Earth]   = new Planet(EAR_RADIUS, EAR_DIS, EAR_SPEED,SELFROTATE, stars[Sun], rgbColor);

 

    SET_VALUE_3(rgbColor, 1, 1, 0);

    stars[Moon]    = new Planet(MOO_RADIUS, MOO_DIS,MOO_SPEED, SELFROTATE, stars[Earth], rgbColor);

 

    SET_VALUE_3(rgbColor, 1, .5, .5);

    stars[Mars]    = new Planet(MAR_RADIUS, MAR_DIS,MAR_SPEED, SELFROTATE, stars[Sun], rgbColor);

 

    SET_VALUE_3(rgbColor, 1, 1, .5);

    stars[Jupiter] = new Planet(JUP_RADIUS,JUP_DIS, JUP_SPEED, SELFROTATE, stars[Sun], rgbColor);

 

    SET_VALUE_3(rgbColor, .5, 1, .5);

    stars[Saturn]  = new Planet(SAT_RADIUS, SAT_DIS, SAT_SPEED,SELFROTATE, stars[Sun], rgbColor);

 

    SET_VALUE_3(rgbColor, .4, .4, .4);

    stars[Uranus]  = new Planet(URA_RADIUS, URA_DIS, URA_SPEED,SELFROTATE, stars[Sun], rgbColor);

 

    SET_VALUE_3(rgbColor, .5, .5, 1);

    stars[Neptune] = new Planet(NEP_RADIUS,NEP_DIS, NEP_SPEED, SELFROTATE, stars[Sun], rgbColor);

 

}

SolarSystem::~SolarSystem()//SolarSystem的析构函数，由于solorsystem只使用到了stars[]这个数组，因此将这个数组释放貌似就行了，不过在C++里面数组的释放貌似不需要我们操心，会自己释放，不过这么写的话显得技术比较高

{
    for(int i = 0; i<STARS_NUM; i++)

        delete stars[i];

}
