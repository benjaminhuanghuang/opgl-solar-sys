#include "SolarSystem.h"

int main()
{
  SolarSystem solarSystem;

  bool success = solarSystem.Initialize();
	if (success)
	{
		solarSystem.RunLoop();
	}
	solarSystem.Shutdown();
	return 0;
}
