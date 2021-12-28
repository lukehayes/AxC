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
#include "Camera3D.h"
#include "Input.h"
#include <time.h>

float verticies[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f
};

extern Engine engine;
#define MAX 10

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
    srand(time(NULL));
    Window* window = CreateWindow(engine.width,engine.height, engine.title);

    SetInput(window);

    /*glfwSetInputMode(window.handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);*/

    Shader* shader = CreateShader(
        "assets/shaders/passthru-vsh.glsl",
        "assets/shaders/passthru-fsh.glsl"
    );

    VertexArray vao = CreateVertexArray();
    VertexBuffer buffer = CreateVertexBuffer(0,3, 12,verticies);

    float c = 0.0;

    // Loop Timing
    f32 delta = 0.0;
    f32 now = 0.0;
    f32 previousTime = glfwGetTime();
    f32 FPS = 60.0;


    mat4 model;
    glm_mat4_identity(model);

    mat4 projection;
    /*glm_perspective_default((800.0f/600.0f), projection);*/
    glm_perspective(glm_rad(45.0f), (800.0f/600.0f), 0.1f, 1000.0f, projection);

    vec3 eye = {0,0,-3.0f};
    vec3 front = {0,0,-1.0f};
    vec3 up = {0,1,0};

    mat4 view;
    glm_mat4_identity(view);

    glm_mat4_print(model, stderr);
    glm_mat4_print(model, stdout);

    while (!glfwWindowShouldClose(window->handle))
    {
        c+= 0.01;
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);

        now = glfwGetTime();
        previousTime = now;

    glm_lookat(
            eye,
            front,
            up,
            view
    );


        eye[2] = sin(c) * 100;

        /* Poll for and process events */
        glfwPollEvents();

        ShaderUniformMat4(shader, "projection", projection);
        ShaderUniformMat4(shader, "view", view);
        ShaderUniformMat4(shader, "model", model);

        UseShader(shader);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        /* Swap front and back buffers */
        glfwSwapBuffers(window->handle);
    }

    DestroyShader(shader);
    DestroyWindow(window,1);

    return 0;
}

