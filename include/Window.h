/**
 * Window/GLFW Window abstraction.
 */
#ifndef AX_WINDOW_H
#define AX_WINDOW_H

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
Window CreateWindow(s16 width, s16 height, const_str title)
{
    InitGLFW();

    Window window;
    window.width = width;
    window.height = height;
    window.title = title;
    window.handle = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!window.handle)
    {
        printf("Window couldn't be created. Terminating.\n");
        glfwTerminate();
    }

    glfwMakeContextCurrent(window.handle);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    return window;
}
#endif
