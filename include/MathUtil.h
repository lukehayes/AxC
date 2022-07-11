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
 * Wrapper for managing delta time.
 */
typedef struct math_utils
{
	f32 delta;
	f32 now;
	f32 previousTime;
	f32 FPS;

} MathUtils;

extern MathUtils math_utils;

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


void delta_init();

f32 get_delta_time();
