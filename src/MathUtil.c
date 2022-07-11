#include "MathUtil.h"

MathUtils math_utils = {0};


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

void delta_init()
{
	math_utils.delta = 0.0;
	math_utils.now = 0.0;
	math_utils.previousTime = 0.0;
	math_utils.FPS = 60.0;
}


