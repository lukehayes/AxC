#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "Types.h"
#include "FileIO.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Window.h"
#include "Engine.h"

float verticies[] = {
    -0.5, 0.5, 0.0f,
    -0.5, -0.5, 0.0f,
    0.5, 0.5, 0.0f,
    0.5, -0.5, 0.0f
};

extern Engine engine;

// MAIN UPDATE AND RENDER FUNCTIONS
void update(float dt)
{
    printf("dt: %f \n", dt);
    engine.update(dt);
}

void render()
{
    printf("Rendering \n");
}


int main(int argc, char *argv[])
{
    Window window = CreateWindow(engine.width,engine.height, engine.title);

    Shader* shader = CreateShader();

    VertexArray vao = CreateVertexArray();

    VertexBuffer buffer = CreateVertexBuffer(0,3, 12,verticies);

    float c = 0.0;

    f32 delta = 0.0;
    f32 now = 0.0;
    f32 previousTime = glfwGetTime();
    f32 FPS = 60.0;

    vec3 position = {0.0,0,0};

    mat4 projection;
    glm_mat4_identity(projection);
    glm_perspective( glm_rad(90.0f), 800.0f/600.0f, 0.1f, 100.0f, projection );

    mat4 view;
    glm_mat4_identity(view);
    vec3 eye = {0,0,3.0f};
    vec3 center = {0,0,0};
    vec3 up = {0,1.0f,0};
    glm_lookat(eye, center,up,view);



    mat4 model;
    glm_mat4_identity(model);

    glm_translate(model, position);

    vec3 positions[10] = {
        {0,0,-10.0f},
        {3,0,-10.0f},
        {3,3,-10.0f},
        {1,3,-10.0f},
        {10,3,-10.0f},
        {-10,3,-10.0f},
        {-3,23,-20.0f},
        {-29,-13,-20.0f},
        {12,-16,-20.0f},
        {-20,33,-4.0f}
    };

    while (!glfwWindowShouldClose(window.handle))
    {
        c+= 0.001;
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);

        now = glfwGetTime();
        previousTime = now;

        /* Poll for and process events */
        glfwPollEvents();

        glm_rotate(model, glm_rad(sin(c)), (vec3){0,0,1});

        ShaderUniform2f(shader, "test", sin(c), cos(c));

        ShaderUniformMat4(shader, "projection", projection);
        ShaderUniformMat4(shader, "view", view);
        ShaderUniformMat4(shader, "model", model);

        for (int i = 0; i < 10; ++i) {
            mat4 model;
            glm_mat4_identity(model);

            glm_translate(model, positions[i]);

            ShaderUniformMat4(shader, "model", model);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        }

        UseShader(shader);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        /* Swap front and back buffers */
        glfwSwapBuffers(window.handle);
    }

    glfwDestroyWindow(window.handle);
    glfwTerminate();

    return 0;
}

