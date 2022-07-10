#pragma once
#include "Types.h"

/**
 * Initalize globals, GLFW and OpenGL **/
void render_init(void);

/**
 * Clear the screen with related bit masks and a color.
 *
 * @param float r    Red value from 0.0 to 1.0.
 * @param float g    Green value from 0.0 to 1.0.
 * @param float b    Blue value from 0.0 to 1.0.
 *
 * @return void
 */
void render_clear(float r, float g, float b);

void RenderBegin();
void RenderQuad();
void RenderEnd();

