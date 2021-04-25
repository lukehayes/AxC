#include "Vec2.h"

int main(int argc, char *argv[])
{
    V2 v = {1,1};
    PrintV2(&v);
    printf("X: %f Y: %f \n", v.x, v.y);
    AxNormalizeV2(v);
    
    return 0;
}
