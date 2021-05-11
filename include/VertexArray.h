/**
 * Vertex Array abstraction.
 */
#ifndef AX_VTXARRAY_H
#define AX_VTXARRAY_H

static GLuint vertexArrayID;

typedef struct VertexArray {
    GLuint id;
} VertexArray;


/**
 * Bind the vertex array.
 *
 * @param VertexArray* vertexArray
 *
 * @return void
 */
void BindVertexArray(VertexArray* vertexArray)
{
    glBindVertexArray(vertexArray->id);
}

/**
 * Unbind the vertex array - Accepts a VertexArray object
 * but this is irrelevant as the function simply calls
 * glBindVertexArray(0). This argument makes it 
 * easier to read and understand in the code.
 *
 * @param VertexArray* vertexArray
 *
 * @return void
 */
void UnbindVertexArray(VertexArray* vertexArray)
{
    glBindVertexArray(0);
}

/**
 * Create and bind a vertex array object.
 */
VertexArray CreateVertexArray()
{
    VertexArray vertexArray;

    glGenVertexArrays(1, &vertexArray.id);
    glBindVertexArray(vertexArray.id);

    return vertexArray;
}


#endif
