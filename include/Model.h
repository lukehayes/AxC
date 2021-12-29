#ifndef AX_MODEL_H
#define AX_MODEL_H

#include "Types.h"


#define Create(TYPE, ...) Create##TYPE(__VA_ARGS__)

typedef struct Model
{
    vec3 position;
    mat4 model;

} Model;


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

