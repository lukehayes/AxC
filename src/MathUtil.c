#include "MathUtil.h"
#include <string.h>

/**
 * Wrapper for managing delta time.
 */
typedef struct math_utils
{
	f32 delta;
	f32 now;
	f32 previousTime;
	f32 FPS;

} MathUtils;

static MathUtils math_utils = {0};


int GetRandInt(int from, int to)
{
    return rand() % (from - to + 1) + from;
}

void PrintMat4(mat4 m)
{
    for(int i = 0; i <= 3; i++)
    {
        for(int j = 0; j <= 3; j++)
        {
            int v = m[i][j];

            // Check if number is less than zero because
            // negative numbers mess up formatting.
            if(v < 0 )
            {
                printf("|%i ", v);
            }else
            {
                printf("| %i ", v);
            }

        }
        printf("| \n");
    }
     
    printf("\n");
    printf("\n");
}

f32 get_delta_time()
{
	math_utils.now = glfwGetTime();
	math_utils.delta = math_utils.now - math_utils.previousTime;
	math_utils.previousTime = math_utils.now;

	return math_utils.delta;
}

