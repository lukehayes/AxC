#include "VertexBuffer.h"

/**
 * Bind the currently bound buffer object.
 *
 * @param VertexBuffer* buffer.
 *
 * @return void
 */
void BindVertexBuffer(VertexBuffer* buffer)
{
    glBindBuffer(GL_ARRAY_BUFFER, buffer->id);
}

/**
 * Unbind the currently bound buffer object.
 */
void UnBindVertexBuffer()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/**
 * Delete a vertex buffer from GPU memory.
 *
 * @return void
 */
void DestroyVertexBuffer(VertexBuffer* buffer)
{
    glDeleteBuffers(1, &buffer->id);
}

/**
 * Create and bind a vertex buffer object.
 */
static void CreateVertexBufferObject(VertexBuffer* buffer)
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
 * @return VertexBuffer*
 */
void SetBufferData(s32 attributePosition, s32 vertexCount, const float verticies[12])
{
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexCount, verticies, GL_STATIC_DRAW );
    glVertexAttribPointer(attributePosition, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(attributePosition);
}


/**
 * Create a VertexBuffer struct.
 *
 * @return VertexBuffer
 */
VertexBuffer CreateVertexBuffer(s32 attributePosition, s32 vertexCount, const float verticies[12]) 
{
    VertexBuffer buffer;
    buffer.bind = &BindVertexBuffer;
    buffer.unbind = &UnBindVertexBuffer;
    buffer.destroy = &DestroyVertexBuffer;

    CreateVertexBufferObject(&buffer);

    SetBufferData(attributePosition, vertexCount, verticies);

    return buffer;
}

