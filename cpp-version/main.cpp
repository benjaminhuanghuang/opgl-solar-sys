#include "SolarSystem.h"
#include "AudioMaster.h"
#include "AudioSource.h"

int main()
{
  SolarSystem solarSystem;

  while (solarSystem.getDisplay()->isRunning())
  {
    solarSystem.update();
    solarSystem.render();
  }
}
