#ifndef AX_SHADER_H
#define AX_SHADER_H

#include <glad/glad.h>
#include "Types.h"
#include "FileIO.h"

typedef struct AxShader Shader;

//Shader program;

/**
 * Check for compilation errors during shader creation.
 *
 * @param GLuint shaderObject
 * @param GLenum compilerState
 * @param GLenum shaderType
 *
 * @return void
 */
static void CheckCompileErrors(GLuint shaderObject, GLenum compilerState, GLenum shaderType);

/**
 * Read in contents of a shader source file and compile it.
 *
 * @return void
 */
static void LoadShaderSource(const char* vPath, const char* fPath);

/**
 * Creates an entire shader program with compiling, linking and validation.
 */
Shader* CreateShader();

/**
 * Call glUseProgram with a specific shader.
 */
void UseShader(const Shader* shader);

/**
 * Send a single float value into the shader.
 *
 * @param const Shader* shader
 * @param const Shader* name
 * @param float value
 *
 * @return void
 */
void ShaderSetFloat(const Shader* shader, const char* name, float value);

#endif
