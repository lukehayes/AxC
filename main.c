#include <stdio.h> 
#include <time.h>
#include "Types.h"
#include "Render.h"
#include "Input.h"
#include "Global.h"
#include "Types.h"

#define MAX 10

int main(int argc, char *argv[])
{
    srand(time(NULL));

	render_init();

	while (!glfwWindowShouldClose(global.window))
	{
		glfwPollEvents();

		/*printf("Delta: %f \n", get_delta_time());*/

		render_begin(GRAY);
		render_quad(0,0, 10, DARKGRAY );
		render_quad(320,240,1, DARKGRAY);
		render_end();
	}

	DestroyShader(gl_state.default_shader);

    return 0;
}
