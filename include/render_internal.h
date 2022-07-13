#pragma once
// ----------------------------------------------------------------------------
// OpenGL Initialization Functions 
// ----------------------------------------------------------------------------
#include "Types.h"
#include "Shader.h"

// VAOS etc are stored here.
typedef struct gl_state
{
	GLuint quad_vao;
	Shader* default_shader;
} GLState;

extern GLState gl_state;

/**
 * Initalize globals, GLFW and OpenGL **/
void render_init(void);

/**
 * Initialize a quad for OpenGL
 */
void render_init_quad();

