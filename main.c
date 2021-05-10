#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "Types.h"
#include "FileIO.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"

float verticies[] = {
    -0.5, 0.5, 0.0f,
    -0.5, -0.5, 0.0f,
    0.5, 0.5, 0.0f,
    0.5, -0.5, 0.0f
};

int main(int argc, char *argv[])
{
    GLFWwindow* window;

    if(!glfwInit())
    {
        printf("GLFW Failed To Initialize \n");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    Shader* shader = CreateShader();

    CreateVertexArray();

    Buffer buffer = CreateBufferObject(0,12,verticies);

    float c = 0.0;

    while (!glfwWindowShouldClose(window))
    {
        c+= 0.01;
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Poll for and process events */
        glfwPollEvents();

        ShaderUniform2f(shader, "test", sin(c), cos(c));

        UseShader(shader);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}

