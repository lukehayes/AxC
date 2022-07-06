#pragma once
#include "Types.h"
#include "Shader.h"

void RenderClear(float r, float g, float b);

void RenderDrawBasic(Shader* shader, int indices);

void RenderBegin();
void RenderQuad();
void RenderEnd();

