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

    // Loop Timing
    f32 delta = 0.0;
    f32 now = 0.0;
    f32 previousTime = glfwGetTime();
    f32 FPS = 60.0;

	/*while (!glfwWindowShouldClose(global.window))*/
	/*{*/
		/*glfwPollEvents();*/

		/*RenderClear(0.2,0.2,0.3);*/

		/*[>previousTime = now;<]*/
		/*[>now = glfwGetTime();<]*/
		/*[>delta = previousTime - now;<]*/

		/*[>printf("%s \n", global.title);<]*/

		/*[>glfwSwapBuffers(window->handle);<]*/
	/*}*/
	
	/*glfwTerminate();*/
	/*free(global.window);*/


    return 0;
}

