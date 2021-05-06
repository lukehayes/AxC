#ifndef AX_SHADER_H
#define AX_SHADER_H

#include <glad/glad.h>
#include "Types.h"
#include "FileIO.h"

GLuint shaderProgram;
GLuint vertexObject;
GLuint fragmentObject;

typedef struct Shader {
    GLuint program;

} Shader;

Shader program;

void CreateShader()
{
    // VERTEX SHADER
    vertexObject = glCreateShader(GL_VERTEX_SHADER);
    char const* vertexSource = ReadFile("assets/shaders/default-vsh.glsl");

    glShaderSource(vertexObject, 1, &vertexSource, NULL);
    glCompileShader(vertexObject);

    GLint success;
    glGetShaderiv(vertexObject, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar InfoLog[1024];
        glGetShaderInfoLog(vertexObject, sizeof(InfoLog), NULL, InfoLog);
        fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_VERTEX_SHADER, InfoLog);
    }

    // FRAGMENT SHADER
    fragmentObject = glCreateShader(GL_FRAGMENT_SHADER);
    char const* fragmentSource = ReadFile("assets/shaders/default-fsh.glsl");
    glShaderSource(fragmentObject, 1, &fragmentSource, 0);
    glCompileShader(fragmentObject);

    glGetShaderiv(fragmentObject, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar InfoLog[1024];
        glGetShaderInfoLog(fragmentObject, sizeof(InfoLog), NULL, InfoLog);
        fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_FRAGMENT_SHADER, InfoLog);
    }

    // CREATE SHADER PROGRAM
    shaderProgram = glCreateProgram();
    program.program = shaderProgram;

    // ATTACH, LINK ETC
    glAttachShader(shaderProgram, vertexObject);
    glAttachShader(shaderProgram, fragmentObject);

    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        GLchar ErrorLog[1024];
        glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
        fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
    }

    glValidateProgram(shaderProgram);

    free((char*)vertexSource);
    free((char*)fragmentSource);
}





#endif
