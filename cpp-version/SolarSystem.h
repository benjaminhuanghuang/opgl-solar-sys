#pragma once

#include "Display.h"
#include "Gui.h"
#include "Camera.h"
#include "Entity.h"

class SolarSystem {

public:
    SolarSystem();
    ~SolarSystem();

    void update();
    void render();

    Display *getDisplay() const;

private:
    std::vector<Entity*> planets;

    Display* display = nullptr;
    Gui* gui = nullptr;

    // SunShader* sunShader = nullptr;
    // PlanetShader* planetShader = nullptr;
    // RegularShader* regularShader = nullptr;
    // Renderer* renderer = nullptr;


    // Light* sunLight = nullptr;
    // Sun* sun = nullptr;


    Earth* earth = nullptr;
    


    Camera* camera = nullptr;
    // Skybox* skybox = nullptr;

  
    void initWindow();
    void initShaders();
    void initRenderer();
    void initEntities();
    void initCameraAndSkybox();

    void updatePlanetAroundSunRotation(float time);
    void updatePlanetSelfRotation(float time);

    void updateCameraPosition();

    void renderRegularEntities();
    void renderSun();
    void renderPlanetsAndMoons();
    void updateAndRenderGui();
};
