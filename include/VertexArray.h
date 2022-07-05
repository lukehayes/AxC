/**
 * Vertex Array abstraction.
 */
#pragma once

#include "Types.h"
#include "Shader.h"

static GLuint vertexArrayID;

typedef struct VertexArray {
    GLuint id;
    Shader* shader;
} VertexArray;


/**
 * Bind the vertex array.
 *
 * @param VertexArray* vertexArray
 *
 * @return void
 */
void BindVertexArray(VertexArray* vertexArray);

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
void UnbindVertexArray(VertexArray* vertexArray);

/**
 * Create and bind a vertex array object.
 *
 * @param Shader* shader
 *
 * @return VertexArray*
 */
VertexArray CreateVertexArray(Shader* shader);

/**
 * Destroy the vertex array
 *
 * @param VertexArray* vertexArray
 *
 */
void DestroyVertexArray(VertexArray* vertexArray);
