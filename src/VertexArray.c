#include "VertexArray.h"

void BindVertexArray(VertexArray* vertexArray)
{
    glBindVertexArray(vertexArray->id);
}

void UnbindVertexArray(VertexArray* vertexArray)
{
    glBindVertexArray(0);
}

VertexArray* CreateVertexArray(Shader* shader)
{
    VertexArray* vertexArray = malloc(sizeof(VertexArray));

    glGenVertexArrays(1, &vertexArray->id);
    glBindVertexArray(vertexArray->id);

    vertexArray->shader = shader;

    return vertexArray;
}

void DestroyVertexArray(VertexArray* vertexArray)
{
    free(vertexArray);
}
