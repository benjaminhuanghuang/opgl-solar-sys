#include "SolarSystem.h"

int main()
{
  SolarSystem solarSystem;

  while (solarSystem.getDisplay()->isRunning())
  {
    solarSystem.update();
    solarSystem.render();
  }
}
