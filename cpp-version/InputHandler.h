#pragma once

#include <GLFW/glfw3.h>

class InputHandler
{
public:
    static bool isKeyPressed(unsigned int key);
    static bool isMouseButtonPressed(unsigned int mousebutton);

    static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
    static void cursorPositionCallback(GLFWwindow *window, double xpos, double ypos);

    static int getMouseX();
    static int getMouseY();
};
