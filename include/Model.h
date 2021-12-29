#ifndef AX_MODEL_H
#define AX_MODEL_H

#include "Types.h"

typedef struct Model
{
    vec3 position;
    mat4 model;

} Model;

Model* CreateModel()
{
    Model* model = malloc(sizeof(Model));

    glm_mat4_identity(model->model);

    return model;
}

void DestroyModel(Model* model)
{
    free(model);
}

#endif

