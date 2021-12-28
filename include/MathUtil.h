/**
 * Ax Math Helpers.
 *
 * This code is loosely based around the adapter pattern
 * and aims to be written in such a way that its inner
 * library can be swapped out for another one easily.
 */
#ifndef AX_MATHUTIL_H
#define AX_MATHUTIL_H

#include <cglm/cglm.h>

/**
 * Create and return a projection matrix.
 */
mat4* PerspectiveProjection(mat4* matrix);

/**
 * Create and return a orthographic matrix.
 */
void OrthographicProjection();


/**
 * Get a random integer value.
 *
 * @param float from
 * @param float to
 *
 * @return float
 */
int GetRandInt(int from, int to);


#endif
