#pragma once

/**
 * Global state and variables for the game.
 */
typedef struct global
{
   int       width;
   int       height;
   const_str title;

} Global;

extern Global global;
