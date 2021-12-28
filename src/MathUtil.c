#include "MathUtil.h"



/**
 * Create and return a projection matrix.
 */
mat4* PerspectiveProjection(mat4* matrix)
{
    glm_perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f, *matrix);
    return matrix;

}
/**
 * Create and return a orthographic matrix.
 */
void OrthographicProjection()
{
    // TODO Implement orthographic projection.
}

/**
 * Get a random float value.
 *
 * @param float from
 * @param float to
 *
 * @return float
 */
int GetRandInt(int from, int to)
{
    return rand() % (from - to + 1) + from;
}
