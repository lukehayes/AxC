#include <stdio.h>
#include <time.h>
#include "Types.h"
#include "Render.h"
#include "Input.h"
#include "Global.h"
#include "Shader.h"

#define MAX 10

int main(int argc, char *argv[])
{
    srand(time(NULL));

	render_init();
	render_init_quad();

	Shader* shader = CreateShader(
				    "assets/shaders/passthru-vsh.glsl",
				    "assets/shaders/passthru-fsh.glsl"
					);

    // Loop Timing
    f32 delta = 0.0;
    f32 now = glfwGetTime();
    f32 previousTime = now;
    f32 FPS = 60.0;

	while (!glfwWindowShouldClose(global.window))
	{
		glfwPollEvents();

		now = glfwGetTime();
		delta = now - previousTime;
		previousTime = now;


		render_clear(sin(delta) * 100.0,0.2,0.25);
		UseShader(shader);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		render_end();
	}

	DestroyShader(shader);

    return 0;
}

