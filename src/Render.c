#include "Render.h"

void RenderClear(float r, float g, float b)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(r,g,b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void RenderDrawBasic(Shader* shader, int indices)
{
    UseShader(shader);
    glDrawArrays(GL_TRIANGLES, 0, indices);
}

void RenderBegin() {}
void RenderQuad() {
    GLuint vao;
    GLuint vbo;

    float verticies[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,

        -1.0f, 0.5f, 0.0f,
        1.0f,  0.5f, 0.0f,
        0.0f,  1.0f, 0.0f
    };

    glGenVertexArrays(1, &vao);
    glBindVertexArray(GL_ARRAY_BUFFER, vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 18, verticies, GL_STATIC_DRAW );
    glVertexAttribPointer(0, 6, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);
}
void RenderEnd() {}

