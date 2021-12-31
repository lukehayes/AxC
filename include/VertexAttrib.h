#ifndef AX_VERTEX_ATTRIB_H
#define AX_VERTEX_ATTRIB_H

#include "Types.h"

/**
 * Struct represents a single location to hold all the
 * data needer per vertex attribute.
 */
typedef struct VertexAttrib
{
    s32 position;
    s32 vertexCount;
    u8 componentCount;
    f32* verticies;

} VertexAttrib;

#endif
