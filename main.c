#include <stdio.h>
#include <time.h>
#include "Types.h"
#include "Render.h"
#include "Input.h"
#include "Global.h"

#define MAX 10

int main(int argc, char *argv[])
{
    srand(time(NULL));

	render_init();
	render_init_quad();

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

		render_begin(0.3,0.3,0.42);
		render_quad();
		render_end();
	}

	DestroyShader(gl_state.default_shader);

    return 0;
}

