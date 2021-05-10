/**
 * Vertex Buffer abstraction.
 */
#ifndef AX_VTXBUFFER_H
#define AX_VTXBUFFER_H

#include "Types.h"

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
void BindBuffer(Buffer* buffer);

/**
 * Unbind the currently bound buffer object.
 */
void UnBindBuffer();

/**
 * Delete a vertex buffer from GPU memory.
 *
 * @return Buffer
 */
void DestroyVertexBuffer(Buffer* buffer);

/**
 * Create and bind a vertex buffer object.
 */
void CreateVertexBuffer(Buffer* buffer);

/**
 * Added the vertex data to the bound buffer object.
 *
 * @param int attributePosition
 * @param int vertexCount
 * @param float verticies[]
 *
 * @return Buffer*
 */
void SetBufferData(s32 attributePosition, s32 vertexCount, const float verticies[12]);

/**
 * Create a Buffer struct.
 *
 * @return Buffer
 */
Buffer CreateBufferObject(s32 attributePosition, s32 vertexCount, const float verticies[12]);

#endif
