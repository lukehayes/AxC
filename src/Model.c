#include "Model.h"

Model* CreateModel(vec3 position)
{
    Model* model = malloc(sizeof(Model));

    memcpy(model->position, position, sizeof(model->position));
    glm_mat4_identity(model->model);

    return model;
}

void DestroyModel(Model* model)
{
    free(model);
}
