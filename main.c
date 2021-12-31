#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "Types.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Window.h"
#include "Engine.h"
#include "Camera3D.h"
#include "Input.h"
#include "Model.h"
#include <time.h>

float verticies[] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f,  1.0f, 0.0f
};

extern Engine engine;
#define MAX 10


int main(int argc, char *argv[])
{
    srand(time(NULL));
    Window* window = CreateWindow(engine.width,engine.height, engine.title);

    SetInput(window);

    Model* model = CreateModel((vec3){0,0,0});

    /*glfwSetInputMode(window.handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);*/

    Shader* shader = CreateShader(
            "assets/shaders/passthru-vsh.glsl",
            "assets/shaders/passthru-fsh.glsl"
            );

    VertexArray* vao = CreateVertexArray(shader);
    VertexBuffer buffer = CreateVertexBuffer(0,3, 9,verticies);

    Camera3D* camera = CreateCamera3D();

    float c = 0.0;

    // Loop Timing
    f32 delta = 0.0;
    f32 now = 0.0;
    f32 previousTime = glfwGetTime();
    f32 FPS = 60.0;


    while (!glfwWindowShouldClose(window->handle))
    {

        /* Poll for and process events */
        glfwPollEvents();

        c+= 0.01;
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        now = glfwGetTime();
        previousTime = now;

        Camera3DUpdate(camera, delta);

        ShaderUniformMat4(shader, "projection", camera->projection);
        ShaderUniformMat4(shader, "view", camera->view);
        ShaderUniformMat4(shader, "model", model->model);

        UseShader(vao->shader);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        /* Swap front and back buffers */
        glfwSwapBuffers(window->handle);
    }

    DestroyModel(model);
    DestroyShader(shader);
    DestroyVertexArray(vao);
    DestroyCamera3D(camera);
    DestroyWindow(window,1);

    return 0;
}

