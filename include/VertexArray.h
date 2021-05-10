/**
 * Vertex Array abstraction.
 */
#ifndef AX_VTXARRAY_H
#define AX_VTXARRAY_H

static GLuint vertexArrayID;

/**
 * Create and bind a vertex array object.
 */
void CreateVertexArray()
{
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);
}


#endif
