#include "render_internal.h"
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

	// Initialize basic primitives.
	render_init_quad();
	
	// Initialize default shaders
	gl_state.default_shader = CreateShader(
				    "assets/shaders/default-vsh.glsl",
				    "assets/shaders/default-fsh.glsl"
					);
}

void render_init_quad()
{
	GLuint VBO;
	GLuint EBO;
	GLenum bufferType = GL_ARRAY_BUFFER;

	float verticies[] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};

	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};  

	// Generate and bind vertex array
	glGenVertexArrays(1, &gl_state.quad_vao);
	glBindVertexArray(gl_state.quad_vao);

	// Generate and bind vertex buffer
	glGenBuffers(1, &VBO);
	glBindBuffer(bufferType, VBO);

	glBufferData(
			bufferType,
			sizeof(verticies),
			verticies,
			GL_STATIC_DRAW);


	// Generate and bind index buffer
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 

	
	// Set attribute pointers etc.
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
