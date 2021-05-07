#ifndef AX_SHADER_H
#define AX_SHADER_H

#include <glad/glad.h>
#include "Types.h"
#include "FileIO.h"

GLuint shaderProgram;
GLuint vertexObject;
GLuint fragmentObject;
char const* vertexSource;
char const* fragmentSource;

typedef struct Shader {
    GLuint program;

} Shader;

Shader program;

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

void LoadShaderSource()
{
    // VERTEX SHADER
    vertexObject = glCreateShader(GL_VERTEX_SHADER);
    vertexSource = ReadFile("assets/shaders/default-vsh.glsl");
    glShaderSource(vertexObject, 1, &vertexSource, NULL);
    glCompileShader(vertexObject);

    CheckCompileErrors(vertexObject, GL_COMPILE_STATUS, GL_VERTEX_SHADER);

    // FRAGMENT SHADER
    fragmentObject = glCreateShader(GL_FRAGMENT_SHADER);
    fragmentSource = ReadFile("assets/shaders/default-fsh.glsl");
    glShaderSource(fragmentObject, 1, &fragmentSource, 0);
    glCompileShader(fragmentObject);

    CheckCompileErrors(fragmentObject, GL_COMPILE_STATUS, GL_FRAGMENT_SHADER);
}

void CreateShader()
{
    // CREATE SHADER PROGRAM
    shaderProgram = glCreateProgram();
    program.program = shaderProgram;

    LoadShaderSource();

    // ATTACH, LINK ETC
    glAttachShader(shaderProgram, vertexObject);
    glAttachShader(shaderProgram, fragmentObject);

    GLint success;

    glLinkProgram(shaderProgram);

    CheckCompileErrors(shaderProgram, GL_LINK_STATUS, 0);
    glValidateProgram(shaderProgram);

    free((char*)vertexSource);
    free((char*)fragmentSource);
}





#endif
