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


/*float verticies[] = {*/
    /*-0.1, 0.5, 0.0f,*/
    /*-0.5, -0.5, 0.0f,*/
    /*0.5, 0.5, 0.0f,*/
    /*0.5, -0.5, 0.0f*/
/*};*/

float verticies[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f
};

extern Engine engine;
#define MAX 100

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

    /*glfwSetInputMode(window.handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);*/

    Shader* shader = CreateShader(
        "assets/shaders/passthru-vsh.glsl",
        "assets/shaders/passthru-fsh.glsl"
    );

    VertexArray vao = CreateVertexArray();

    VertexBuffer buffer = CreateVertexBuffer(0,3, 12,verticies);

    float c = 0.0;

    f32 delta = 0.0;
    f32 now = 0.0;
    f32 previousTime = glfwGetTime();
    f32 FPS = 60.0;

    vec3 position = {0.0,0,0};

    vec3 positions[MAX];

    for (int i = 0; i < MAX; i++) 
    {
        vec3 v = {
            rand() % 100 - 50,
            rand() % 100 - 50,
            rand() % 100 - 50
        };

        memcpy(positions[i], v, sizeof(v));
    }

    mat4 model;
    glm_mat4_identity(model);

    while (!glfwWindowShouldClose(window.handle))
    {
        c+= 0.01;
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);

        now = glfwGetTime();
        previousTime = now;

        /* Poll for and process events */
        glfwPollEvents();

        for (int i = 0; i < MAX; ++i) {
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

    DestroyShader(shader);
    glfwDestroyWindow(window.handle);
    glfwTerminate();

    return 0;
}

