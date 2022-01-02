#ifndef AX_MODEL_H
#define AX_MODEL_H

#include "Types.h"

/**------------------------------------------------------------------------------
 * Structs
 ------------------------------------------------------------------------------*/
typedef struct Model
{
    vec3 position;
    mat4 model;

} Model;


/**------------------------------------------------------------------------------
 * Functions
 ------------------------------------------------------------------------------*/
/**
 * Create a model struct on the heap.
 *
 * @return Model*/
Model* CreateModel(vec3 position);

/**
 * Delete a model from memory.
 *
 * @param Model* model
 *
 * @return void
 */
void DestroyModel(Model* model);

#endif

