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
void RenderQuad() {}
void RenderEnd() {}

