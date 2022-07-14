#pragma once

#include "Types.h"

/**
 * Global state and variables for the game.
 */
typedef struct global
{
   float         width;
   float         height;
   const_str   title;

   GLFWwindow* window;

} Global;

extern Global global;
