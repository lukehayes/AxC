/**
 * A single location for adding Input.
 */
#pragma once

#include "Types.h"

static void KeyInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
    {
        printf("E Presed \n");
    }
}

void SetInput(GLFWwindow* window)
{
    glfwSetKeyCallback(window, KeyInputCallback);
}

