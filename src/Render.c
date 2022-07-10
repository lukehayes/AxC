#include "Render.h"
#include "Global.h"

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


void RenderBegin() {}
void RenderQuad() {}
void RenderEnd() {}
void render_end() 
{
	glfwSwapBuffers(global.window);
}

