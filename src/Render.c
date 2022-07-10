#include "Render.h"
#include "Global.h"

GLState gl_state = {0};

void render_init(void)
{
	global.width  = 640;
	global.height = 480;
	global.title  = "Game";

	// Initialize GLFW
	if(!glfwInit())
	{
		printf("GLFW Failed To Initialize \n");
	}

	// Set OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	global.window = glfwCreateWindow(
						global.width,
						global.height,
						global.title,
						NULL,
						NULL);

	glfwMakeContextCurrent(global.window);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

}


void render_clear(float r, float g, float b)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(r,g,b, 1.0f);
}


void render_begin() {}
void render_quad() {}

void render_end() 
{
	glfwSwapBuffers(global.window);
}

// ----------------------------------------------------------------------------
// OpenGL Render Functions 
// ----------------------------------------------------------------------------

void render_init_quad()
{
	GLuint vbo;

	glGenVertexArrays(1, &gl_state.quad_vao);
	glBindVertexArray(gl_state.quad_vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	const float verticies[] = {
	   -1.0f, -1.0f, 0.0f,
	   1.0f, -1.0f, 0.0f,
	   0.0f,  1.0f, 0.0f,
	};

	glBufferData(
			GL_ARRAY_BUFFER,
			sizeof(verticies),
			verticies,
			GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
}
