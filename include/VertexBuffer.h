/**
 * Vertex Buffer abstraction.
 */
#ifndef AX_VTXBUFFER_H
#define AX_VTXBUFFER_H

typedef struct Buffer {
    GLuint id;
    void (*bind) ();
    void (*unbind) ();
    void (*destroy) ();

} Buffer;


/**
 * Bind the currently bound buffer object.
 *
 * @param Buffer* buffer.
 *
 * @return void
 */
void BindBuffer(Buffer* buffer)
{
    glBindBuffer(GL_ARRAY_BUFFER, buffer->id);
}

/**
 * Unbind the currently bound buffer object.
 */
void UnBindBuffer()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/**
 * Delete a vertex buffer from GPU memory.
 *
 * @return Buffer
 */
void DestroyVertexBuffer(Buffer* buffer)
{
    glDeleteBuffers(1, &buffer->id);
}

/**
 * Create and bind a vertex buffer object.
 */
void CreateVertexBuffer(Buffer* buffer)
{
    glGenBuffers(1, &buffer->id);
    glBindBuffer(GL_ARRAY_BUFFER, buffer->id);
}

/**
 * Added the vertex data to the bound buffer object.
 *
 * @param int attributePosition
 * @param int vertexCount
 * @param float verticies[]
 *
 * @return Buffer*
 */
void SetBufferData(s32 attributePosition, s32 vertexCount, const float verticies[12])
{
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexCount, verticies, GL_STATIC_DRAW );
    glVertexAttribPointer(attributePosition, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(attributePosition);
}


/**
 * Create a Buffer struct.
 *
 * @return Buffer
 */
Buffer CreateBufferObject(s32 attributePosition, s32 vertexCount, const float verticies[12]) 
{
    Buffer buffer;
    buffer.bind = &BindBuffer;
    buffer.unbind = &UnBindBuffer;
    buffer.destroy = &DestroyVertexBuffer;

    CreateVertexBuffer(&buffer);

    SetBufferData(attributePosition, vertexCount, verticies);

    return buffer;
}

#endif
