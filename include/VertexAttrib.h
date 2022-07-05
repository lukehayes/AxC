/**
 * Struct represents a single location to hold all the
 * data needer per vertex attribute.
 */
#pragma once

#include "Types.h"

typedef struct VertexAttrib
{
    s32 position;
    s32 vertexCount;
    u8 componentCount;
    f32* verticies;

} VertexAttrib;
