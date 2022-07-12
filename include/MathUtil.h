/**
 * Ax Math Helpers.
 *
 * This code is loosely based around the adapter pattern
 * and aims to be written in such a way that its inner
 * library can be swapped out for another one easily.
 */
#pragma once

#include "Types.h"


/**
 * Get a random integer value.
 *
 * @param float from
 * @param float to
 *
 * @return float
 */
int GetRandInt(int from, int to);

/**
 * Print a mat4 variable for debugging.
 *
 * @param mat4 m
 *
 * @return void
 */
void PrintMat4(mat4 m);


f32 get_delta_time();
