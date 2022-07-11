#include "Shader.h"
#include "Types.h"

GLuint      shaderProgram;
GLuint      vertexObject;
GLuint      fragmentObject;
char const* vertexSource;
char const* fragmentSource;
Shader      program;

typedef struct AxShader
{
   GLuint program;
} Shader;

/**
 * Check for compilation errors during shader creation.
 *
 * @param GLuint shaderObject
 * @param GLenum compilerState
 * @param GLenum shaderType
 *
 * @return void
 */
void CheckCompileErrors(GLuint shaderObject, GLenum compilerState, GLenum shaderType)
{
    GLint success;
    glGetShaderiv(shaderObject, compilerState, &success);
    if (!success) {
        GLchar InfoLog[1024];
        glGetShaderInfoLog(vertexObject, sizeof(InfoLog), NULL, InfoLog);
        fprintf(stderr, "Error compiling shader type %d: '%s'\n", shaderType, InfoLog);
    }
}

/**
 * Read in contents of a shader source file and compile it.
 *
 * @return void
 */
void LoadShaderSource(const char* vPath, const char* fPath)
{
    // VERTEX SHADER
    vertexObject = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexSource = ReadFile(vPath);
    glShaderSource(vertexObject, 1, &vertexSource, NULL);

    glCompileShader(vertexObject);

    CheckCompileErrors(vertexObject, GL_COMPILE_STATUS, GL_VERTEX_SHADER);

    // FRAGMENT SHADER
    fragmentObject = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentSource = ReadFile(fPath);
    glShaderSource(fragmentObject, 1, &fragmentSource, 0);
    glCompileShader(fragmentObject);

    CheckCompileErrors(fragmentObject, GL_COMPILE_STATUS, GL_FRAGMENT_SHADER);
}

/**
 * Creates an entire shader program with compiling, linking and validation.
 */
Shader* CreateShader(const_str vsh, const_str fsh)
{
    // CREATE SHADER PROGRAM
    shaderProgram = glCreateProgram();

    Shader* program = malloc(sizeof(Shader));

    program->program = shaderProgram;

    /*printf("Shader program: %s \n", vsh);*/

    LoadShaderSource(vsh, fsh);

    // ATTACH, LINK ETC
    glAttachShader(program->program, vertexObject);
    glAttachShader(program->program, fragmentObject);

    GLint success;

    glLinkProgram(program->program);

    /*printf("Shader Linking Error. \n");*/
    CheckCompileErrors(program->program, GL_LINK_STATUS, 0);

    printf("Shader Validating. \n");
    glValidateProgram(program->program);

    free((char*)vertexSource);
    free((char*)fragmentSource);

    return program;
}

void DestroyShader(Shader* shader)
{
    free(shader);
}

void UseShader(const Shader* shader)
{
    glUseProgram(shader->program);
}

void ShaderUniform1f(const Shader* shader, const char* name, float value)
{
    GLuint location = glGetUniformLocation(shader->program, name);
    glUniform1f(location, value);
}

void ShaderUniform2f(const Shader* shader, const char* name, float value1, float value2)
{
    GLuint location = glGetUniformLocation(shader->program, name);
    glUniform2f(location, value1, value2);
}

void ShaderUniform3f(const Shader* shader, const char* name, vec3 value)
{
    GLuint location = glGetUniformLocation(shader->program, name);
    glUniform3f(location, value[0], value[1], value[2]);
}

void ShaderUniformMat4(const Shader* shader, const char* name, mat4 matrix)
{
    GLuint location = glGetUniformLocation(shader->program, name);
    glUniformMatrix4fv(location,1, GL_FALSE, matrix[0]);
}
