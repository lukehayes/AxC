#ifndef CAMERA3D_H
#define CAMERA3D_H

typedef struct Camera3D
{
    vec3 position;

} Camera3D;
 

Camera3D* CreateCamera()
{
    Camera3D* camera = malloc(sizeof(Camera3D));

    return camera;
}


void CameraUpdate(Camera3D* camera, float dt)
{
    // TODO Implement Camera3D update.
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
