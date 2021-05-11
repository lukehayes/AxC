#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "Types.h"
#include "FileIO.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Window.h"

float verticies[] = {
    -0.5, 0.5, 0.0f,
    -0.5, -0.5, 0.0f,
    0.5, 0.5, 0.0f,
    0.5, -0.5, 0.0f
};

int main(int argc, char *argv[])
{
    Window window = CreateWindow(800,600, "Ax Window");

    Shader* shader = CreateShader();

    VertexArray vao = CreateVertexArray();

    VertexBuffer buffer = CreateVertexBuffer(0,12,verticies);

    float c = 0.0;

    while (!glfwWindowShouldClose(window.handle))
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
        glfwSwapBuffers(window.handle);
    }

    glfwDestroyWindow(window.handle);
    glfwTerminate();

    return 0;
}

