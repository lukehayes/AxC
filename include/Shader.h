#ifndef AX_SHADER_H
#define AX_SHADER_H

#include <glad/glad.h>
#include "Types.h"
#include "FileIO.h"

typedef struct Shader {
    GLuint program;

} Shader;

Shader program;

/**
 * Check for compilation errors during shader creation.
 *
 * @param GLuint shaderObject
 * @param GLenum compilerState
 * @param GLenum shaderType
 *
 * @return void
 */
void CheckCompileErrors(GLuint shaderObject, GLenum compilerState, GLenum shaderType);

/**
 * Read in contents of a shader source file and compile it.
 *
 * @return void
 */
void LoadShaderSource(const char* vPath, const char* fPath);

/**
 * Creates an entire shader program with compiling, linking and validation.
 */
void CreateShader();

#endif
