#include "MathUtil.h"

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
