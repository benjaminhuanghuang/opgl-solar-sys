#pragma once

#include "lib/imgui/imgui.h"
#include "lib/imgui/imgui_impl_glfw.h"
#include "lib/imgui/imgui_impl_opengl3.h"

#include <string>
#include "Renderer.h"

enum class FocusState
{
  NONE,
  SUN,
  MERCURY,
  VENUS,
  EARTH,
  MARS,
  JUPITER,
  SATURN,
  URANUS,
  NEPTUNE
};

class Gui
{
public:
  Gui(Renderer *renderer);
  virtual ~Gui();

  void Draw();


  FocusState getFocusState() const;

  float getVolumeScale() const;
  float getTimeScale() const;
  float getLightIntensityScale() const;

  const float *getColors() const;

private:
  bool freePressed;

  bool sunPressed;
  bool mercuryPressed;
  bool venusPressed;
  bool earthPressed;
  bool marsPressed;
  bool jupiterPressed;
  bool saturnPressed;
  bool uranusPressed;
  bool neptunePressed;

  float volumeScale = 1.0f;
  float timeScale = 1.0f;
  float lightIntensityScale = 1.0f;
  float colors[3] = {1, 1, 1};

  FocusState focusState = FocusState::NONE;
  void button(const std::string &label, const std::string &info, bool *value);
  void displayCameraWindow();
  void displaySettingsWindow();
  void displayInfoWindow();
};
