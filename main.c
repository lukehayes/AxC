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

	while (!glfwWindowShouldClose(global.window))
	{
		glfwPollEvents();

		printf("Delta: %f \n", get_delta_time());

		render_begin(0.3,0.3,0.42);
		render_quad();
		render_end();
	}

	DestroyShader(gl_state.default_shader);

    return 0;
}

