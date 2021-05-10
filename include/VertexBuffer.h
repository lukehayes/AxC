/**
 * Vertex Buffer abstraction.
 */
#ifndef AX_VTXBUFFER_H
#define AX_VTXBUFFER_H

static GLuint vertexBufferID;

/**
 * Create and bind a vertex buffer object.
 */
void CreateVertexBuffer()
{
    glGenBuffers(1, &vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
}

void SetBufferData(int attributePosition, int vertexCount, const float verticies[12])
{
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexCount, verticies, GL_STATIC_DRAW );
    glVertexAttribPointer(attributePosition, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(attributePosition);
}


#endif
