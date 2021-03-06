#include "Render.h"
#include "render_internal.h"
#include "Global.h"
#include "Shader.h"
#include "Types.h"
#include "utils/colors.h"


void render_clear(float r, float g, float b)
{
    glClearColor(r,g,b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void render_begin(Color color)
{
	glClearColor(
			color.r,
			color.g,
			color.b,
			1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	UseShader(gl_state.default_shader);

	mat4 projection = GLM_MAT4_IDENTITY_INIT;
	glm_mat4_identity(projection);

	// (0,0) is the top left of the screen.
	glm_ortho(
			0, // left
			global.width, // right
			global.height, // bottom
			0, // top
			0.0f,
			10.0f,
			projection);


	ShaderUniformMat4(gl_state.default_shader, "projection", projection);
}

void render_quad(float x, float y, float scale, Color color)
{
	
	mat4 model = GLM_MAT4_IDENTITY_INIT;
	glm_mat4_identity(model);

	glm_translate_x(model, x);
	glm_translate_y(model, y);
	glm_scale_uni(model, scale);

	ShaderSetColor(gl_state.default_shader,"color", color);
	ShaderUniformMat4(gl_state.default_shader, "model", model);

	glBindVertexArray(gl_state.quad_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void render_pixel(float x, float y, Color color)
{
	
	mat4 model = GLM_MAT4_IDENTITY_INIT;
	glm_mat4_identity(model);

	glm_translate_x(model, x);
	glm_translate_y(model, y);

	ShaderUniformMat4(gl_state.default_shader, "model", model);
	ShaderSetColor(gl_state.default_shader,"color", color);

	glBindVertexArray(gl_state.quad_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void render_end() 
{
	glfwSwapBuffers(global.window);
}
