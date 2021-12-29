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
#include "Model.h"
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

    Model* model = CreateModel();

    /*glfwSetInputMode(window.handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);*/

    Shader* shader = CreateShader(
            "assets/shaders/passthru-vsh.glsl",
            "assets/shaders/passthru-fsh.glsl"
            );

    VertexArray vao = CreateVertexArray();
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
        c+= 0.01;
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);

        now = glfwGetTime();
        previousTime = now;

        Camera3DUpdate(camera, delta);

        /* Poll for and process events */
        glfwPollEvents();

        ShaderUniformMat4(shader, "projection", camera->projection);
        ShaderUniformMat4(shader, "view", camera->view);
        ShaderUniformMat4(shader, "model", model->model);

        UseShader(shader);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        /* Swap front and back buffers */
        glfwSwapBuffers(window->handle);
    }

    DestroyModel(model);
    DestroyShader(shader);
    DestroyCamera3D(camera);
    DestroyWindow(window,1);

    return 0;
}

