#pragma once

#include "Display.h"
#include "Gui.h"
#include "Camera.h"

class SolarSystem {

public:
    SolarSystem();
    ~SolarSystem();

    void update();
    void render();

    Display *getDisplay() const;

private:
    //std::vector<Entity*> planets;

    Display* display = nullptr;
    Gui* gui = nullptr;

    // Loader* loader = nullptr;
    // SunShader* sunShader = nullptr;
    // PlanetShader* planetShader = nullptr;
    // RegularShader* regularShader = nullptr;
    // Renderer* renderer = nullptr;


    // Light* sunLight = nullptr;
    // Sun* sun = nullptr;

    // Mercury* mercury = nullptr;
    // Venus* venus = nullptr;
    // Earth* earth = nullptr;
    // Mars* mars = nullptr;
    // Jupiter* jupiter = nullptr;
    // Saturn* saturn = nullptr;
    // SaturnRings* saturnRings = nullptr;
    // Uranus* uranus = nullptr;
    // Neptune* neptune = nullptr;


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
