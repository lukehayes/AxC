/**
 * Ax Math Helpers.
 *
 * This code is loosely based around the adapter pattern
 * and aims to be written in such a way that its inner
 * library can be swapped out for another one easily.
 */
#ifndef AX_MATH_H
#define AX_MATH_H

#include <cglm/cglm.h>

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


#endif
