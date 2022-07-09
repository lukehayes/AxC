#pragma once

#include "Types.h"

/**
 * Global state and variables for the game.
 */
typedef struct global
{
   int         width;
   int         height;
   const_str   title;

   GLFWwindow* window;

} Global;

extern Global global;
