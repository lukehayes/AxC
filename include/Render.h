#pragma once
#include "render_internal.h"
#include "Types.h"
#include "Shader.h"

/**
 * Clear the screen with related bit masks and a color.
 *
 * @param float r    Red value from 0.0 to 1.0.
 * @param float g    Green value from 0.0 to 1.0.
 * @param float b    Blue value from 0.0 to 1.0.
 *
 * @return void
 */
void render_clear(float r, float g, float b);

/**
 * Clear the screen with related bit masks and a color.
 *
 * @param Color color    The color to clear the screen with.
 *
 * @return void
 */
void render_begin(Color color);

/**
 * Render a quad to the screen.
 *
 * @param float x        X axis position.
 * @param float y        Y axis position.
 * @param float scale    Scale of the quad - all axis.
 * @param Color color    Color of the object.
 *
 * @return void
 */
void render_quad(float x, float y, float scale, Color color);


/**
 * Render a single pixel to the screen.
 *
 * @param float x        X axis position.
 * @param float y        Y axis position.
 * @param Color color    Color of the object.
 *
 * @return void
 */
void render_pixel(float x, float y, Color color);

/**
 * Swap buffers and blit the screen.
 */
void render_end();


