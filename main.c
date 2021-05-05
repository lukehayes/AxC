#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "Types.h"
#include "FileIO.h"
#include "Shader.h"


GLuint vao;
GLuint buffer;
float verticies[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
};

void GL()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(GL_ARRAY_BUFFER);

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW );

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

}

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

    GL();
    CreateShader();

    printf("shaderProgram: %i \n", shaderProgram);

    printf("program: %i \n", program.program);

    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        glUseProgram(program.program);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    glfwTerminate();

    return 0;
}

