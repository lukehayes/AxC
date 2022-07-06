/**
 * Window/GLFW Window abstraction.
 */
#pragma once

#include "Types.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

typedef struct Window 
{
    s16 width;
    s16 height;
    const_str title;
    GLFWwindow* handle;
} Window;

/**
 * Setup GLFW and initialize OpenGL with hints to
 * the core profile and version 3.3+.
 */
void InitGLFW();

/**
 * Create a window.
 *
 * @param s16 width
 * @param s16 height
 * @param const char* title
 *
 * @return Window
 */
Window* CreateWindow(s16 width, s16 height, const_str title);

/**
 * Destroy the window and GLFW window handle. Optionally
 * terminate GLFW if passing to second argument.
 *
 * @param Window* window
 * @param int terminate_glfw     call glfwTerminate() if true.
 *
 * @return void
 */
void DestroyWindow(Window* window, int terminate_glfw);
