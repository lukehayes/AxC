
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

float yaw = 0.0f;
float pitch = 0.0f;
float lastX = 400.0f;
float lastY = 300.0f;
float xPos = 0.0f;
float yPos = 0.0f;
double mouseX = 0.0f;
double mouseY = 0.0f;
float mouseSensitivity = 0.5f;
vec3 cameraPosition = {0,0,3.0f};
vec3 cameraDir = {0,0,-1.0f};
vec3 cameraUp = {0,1.0f,0};

#define MAX 1000

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

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_W && action == GLFW_PRESS)
    {
        xPos += 1;
    }

    if (key == GLFW_KEY_S && action == GLFW_PRESS)
    {
        xPos -= 1;
    }
}

void mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
    printf("@ \n");
    float xOffset = xPos - lastX;
    float yOffset = lastY - yPos; // Y reversed, co-ordinates from bottom to top.
    lastX = xPos;
    lastY = yPos;

    xOffset *= mouseSensitivity;
    yOffset *= mouseSensitivity;

    yaw += xOffset;
    pitch += yOffset;

    // Constrain the PITCH (UP and DOWN)
    if(pitch > 89.0f)
      pitch =  89.0f;
    if(pitch < -89.0f)
      pitch = -89.0f;
        
    vec3 front = {0,0,0};
    front[0] = cos(glm_rad(yaw)) * cos(glm_rad(pitch));
    front[1] = sin(glm_rad(pitch));
    front[2] = sin(glm_rad(yaw)) * cos(glm_rad(pitch));

    cameraDir[0] = front[0];
    cameraDir[1] = front[1];
    cameraDir[2] = front[2];

    /*memset(cameraDir, glm_vec3_norm(front), sizeof(vec3));*/
    /*cameraDir = glm_vec3_norm(front);*/
}

int main(int argc, char *argv[])
{
    Window window = CreateWindow(engine.width,engine.height, engine.title);

    /*glfwSetInputMode(window.handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);*/

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
    
    /*vec3 cameraCombined;*/
    /*glm_vec3_add(cameraPosition, cameraDir, cameraCombined);*/

    /*glm_lookat(cameraPosition,*/
            /*cameraDir,*/
            /*cameraUp,*/
            /*view);*/

    mat4 model;
    glm_mat4_identity(model);

    glm_translate(model, position);

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

    glfwSetKeyCallback(window.handle, key_callback);
    glfwSetCursorPosCallback(window.handle, mouse_callback);

    while (!glfwWindowShouldClose(window.handle))
    {
        c+= 0.01;
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);

        now = glfwGetTime();
        previousTime = now;

    /*vec3 cameraDir = {0,0,0};*/
    
    /*glm_vec3_add(cameraPosition, cameraDir, cameraCombined);*/

        /*cameraPosition[0] = cameraPosition[0] + xPos;*/

        /*printf("yaw: %f \n", yaw);*/
        /*printf("pitch: %f \n", pitch);*/

        /*cameraPosition[0] = xPos;*/
        /*cameraPosition[1] = sin(glm_rad(pitch));*/
        /*cameraPosition[2] = sin(glm_rad(pitch))  * cos(glm_rad(yaw));*/

        glm_lookat(cameraPosition,
                cameraDir,
                cameraUp,
                view);

        /* Poll for and process events */
        glfwPollEvents();

        glm_rotate(model, glm_rad(sin(c)), (vec3){0,0,1});

        ShaderUniformMat4(shader, "projection", projection);
        ShaderUniformMat4(shader, "view", view);
        ShaderUniformMat4(shader, "model", model);

        glm_mat4_print(model, stderr);

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

    glfwDestroyWindow(window.handle);
    glfwTerminate();

    return 0;
}

