#include "Engine.h"

/**
 * Engine struct constructor.
 */
Engine CreateEngine()
{
    Engine engine;
    engine.width =  800;
    engine.height =  600;
    
    return engine;
}

Engine engine = {
    .width  = 800, 
    .height = 600,
    .title = "Ax Window"
};
