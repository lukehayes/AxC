/**
 * Vertex Buffer abstraction.
 */
#ifndef AX_VTXBUFFER_H
#define AX_VTXBUFFER_H

#include "Types.h"

typedef struct VertexBuffer {
    GLuint id;
    void (*bind) ();
    void (*unbind) ();
    void (*destroy) ();

} VertexBuffer;

/**
 * Bind the currently bound buffer object.
 *
 * @param VertexBuffer* buffer.
 *
 * @return void
 */
void BindVertexBuffer(VertexBuffer* buffer);

/**
 * Unbind the currently bound buffer object.
 */
void UnBindVertexBuffer();

/**
 * Delete a vertex buffer from GPU memory.
 *
 * @return VertexBuffer
 */
void DestroyVertexBuffer(VertexBuffer* buffer);

/**
 * Create and bind a vertex buffer object.
 */
void CreateVertexBufferObject(VertexBuffer* buffer);

/**
 * Added the vertex data to the bound buffer object.
 *
 * @param int attributePosition
 * @param int vertexCount
 * @param float verticies[]
 *
 * @return VertexBuffer*
 */
void SetBufferData(s32 attributePosition, s32 vertexCount, const float verticies[12]);

/**
 * Create a VertexBuffer struct.
 *
 * @return VertexBuffer
 */
VertexBuffer CreateVertexBuffer(s32 attributePosition, s32 vertexCount, const float verticies[12]);

#endif
