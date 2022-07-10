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

void render_begin();

void render_quad();

/**
 * Swap buffers and blit the screen.
 */
void render_end();

// ----------------------------------------------------------------------------
// OpenGL Render Functions 
// ----------------------------------------------------------------------------

// VAOS etc are stored here.
typedef struct gl_state
{
	GLuint quad_vao;
} GLState;

extern GLState gl_state;

/**
 * Initialize a quad for OpenGL
 */
void render_init_quad();
