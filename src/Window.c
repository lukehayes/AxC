#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

/**
 * Setup GLFW and initialize OpenGL with hints to
 * the core profile and version 3.3+.
 */
void InitGLFW()
{
    if(!glfwInit())
    {
        printf("GLFW Failed To Initialize \n");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}

/**
 * Create a window.
 *
 * @param s16 width
 * @param s16 height
 * @param const char* title
 *
 * @return Window
 */
Window* CreateWindow(s16 width, s16 height, const_str title)
{
    InitGLFW();

    Window* window = malloc(sizeof(window));
    window->width = width;
    window->height = height;
    window->title = title;
    window->handle = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!window->handle)
    {
        printf("Window couldn't be created.\n");
        printf("Destroying Window.\n");
        free(window);
        printf("Terminating GLFW.\n");
        glfwTerminate();
    }

    glfwMakeContextCurrent(window->handle);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    return window;
}

/**
 * Destroy the window and GLFW window handle. Optionally
 * terminate GLFW if passing to second argument.
 *
 * @param Window* window
 * @param int terminate_glfw     call glfwTerminate() if true.
 *
 * @return void
 */
void DestroyWindow(Window* window, int terminate_glfw)
{
        glfwDestroyWindow(window->handle);
        free(window);

        if(terminate_glfw)
        {
            glfwTerminate();
        }
}
