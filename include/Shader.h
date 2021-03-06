#pragma once

#include "Types.h"
#include "MathUtil.h"
#include "FileIO.h"
#include "utils/colors.h"


typedef struct AxShader Shader;

/**
 * Creates an entire shader program with compiling, linking and validation.
 *
 * @param const Shader* vsh
 * @param const Shader* vsh
 *
 * @return Shader*
 */
Shader* CreateShader(const_str vsh, const_str fsh);

/**
 * Destory the shader allocated in memory.
 *
 * @param Shader* shader
 *
 * @return void
 */
void DestroyShader(Shader* shader);

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
void ShaderUniform1f(const Shader* shader, const char* name, float value);

/**
 * Send two float values into the shader.
 *
 * @param const Shader* shader
 * @param const Shader* name
 * @param float value1
 * @param float value2
 *
 * @return void
 */
void ShaderUniform2f(const Shader* shader, const char* name, float value1, float value2);

/**
 * Send a three float values into the shader.
 *
 * @param const Shader* shader
 * @param const Shader* name
 * @param float value1
 * @param float value2
 * @param float value3
 *
 * @return void
 */
void ShaderUniform3f(const Shader* shader, const char* name, vec3 value);

/**
 * Send a three float values into the shader.
 *
 * @param const Shader* shader
 * @param const Shader* name
 *
 * @return void
 */
void ShaderSetColor(const Shader* shader, const char* name, Color color);

/**
 * Send a Matrix4 uniform into the shader.
 *
 * @param const Shader* shader
 * @param const Shader* name
 * @param mat4  Matrix
 *
 * @return void
 */
void ShaderUniformMat4(const Shader* shader, const char* name, mat4 matrix);
