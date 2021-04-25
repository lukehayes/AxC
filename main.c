#include <stdio.h>
#include <GLFW/glfw3.h>

int main(int argc, char *argv[])
{
    GLFWwindow* window;

    if(!glfwInit())
    {
        printf("GLFW Failed To Initialize \n");
    }

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);


    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        /*glClear(GL_COLOR_BUFFER_BIT);*/

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
