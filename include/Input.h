/**
 * A single location for adding Input.
 */
#ifndef AX_INPUT_H
#define AX_INPUT_H

#include "Types.h"

static void KeyInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
    {
        printf("E Presed \n");
    }
}

void SetInput(Window* window)
{
    glfwSetKeyCallback(window->handle, KeyInputCallback);
}


#endif
