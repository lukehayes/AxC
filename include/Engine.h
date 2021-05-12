/**
 * Engine struct that holds general information
 * about the engine or function pointers to 
 * change functionality.
 */
#ifndef AX_ENGINE_H
#define AX_ENGINE_H

#include "Types.h"

typedef struct Engine {
    s16 width;
    s16 height;
    const_str title;

    void (*update)(float dt);
    
} Engine;

/**
 * Engine struct constructor.
 */
Engine CreateEngine();


#endif
