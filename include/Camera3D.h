#ifndef CAMERA3D_H
#define CAMERA3D_H

#include "Types.h"

typedef struct Camera3D
{
    vec3 position;
    vec3 eye;
    vec3 front;
    vec3 up;
    mat4 projection;
    mat4 model;
    mat4 view;

} Camera3D;


Camera3D* CreateCamera3D()
{
    Camera3D* camera = malloc(sizeof(Camera3D));

    glm_mat4_identity(camera->model);
    glm_perspective(glm_rad(45.0f), (800.0f/600.0f), 0.1f, 1000.0f, camera->projection);
    glm_mat4_identity(camera->view);

    printf("%i \n", sizeof(camera->eye));

    memcpy(camera->eye,  (vec3){0,0,-3.0f}, sizeof(camera->eye));
    memcpy(camera->front,(vec3){0,0,-1.0f}, sizeof(camera->front));
    memcpy(camera->up,   (vec3){0,1.0f,0.0f},  sizeof(camera->up));

    return camera;
}


void Camera3DUpdate(Camera3D* camera, float dt)
{
    static float c = 0.0;

    camera->eye[2] = sin(c) * 100;
    // TODO Implement Camera3D update.
    glm_lookat(
            camera->eye,
            camera->front,
            camera->up,
            camera->view
            );

    c+= 0.1;
}

void DestroyCamera3D(Camera3D* camera)
{
    if(camera != NULL)
    {
        free(camera);
    }else
    {
        printf("Camera was NULL! Cannot be freed again. \n");
    }
}

#endif
