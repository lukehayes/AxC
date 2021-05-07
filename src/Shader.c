#include "Shader.h"

static GLuint shaderProgram;
static GLuint vertexObject;
static GLuint fragmentObject;
static char const* vertexSource;
static char const* fragmentSource; 
Shader program;

typedef struct AxShader {
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
    vertexSource = ReadFile(vPath);
    glShaderSource(vertexObject, 1, &vertexSource, NULL);
    glCompileShader(vertexObject);

    CheckCompileErrors(vertexObject, GL_COMPILE_STATUS, GL_VERTEX_SHADER);

    // FRAGMENT SHADER
    fragmentObject = glCreateShader(GL_FRAGMENT_SHADER);
    fragmentSource = ReadFile(fPath);
    glShaderSource(fragmentObject, 1, &fragmentSource, 0);
    glCompileShader(fragmentObject);

    CheckCompileErrors(fragmentObject, GL_COMPILE_STATUS, GL_FRAGMENT_SHADER);
}

/**
 * Creates an entire shader program with compiling, linking and validation.
 */
Shader* CreateShader()
{
    // CREATE SHADER PROGRAM
    shaderProgram = glCreateProgram();
    program.program = shaderProgram;

    LoadShaderSource(
        "assets/shaders/default-vsh.glsl",
        "assets/shaders/default-fsh.glsl"
    );

    // ATTACH, LINK ETC
    glAttachShader(shaderProgram, vertexObject);
    glAttachShader(shaderProgram, fragmentObject);

    GLint success;

    glLinkProgram(shaderProgram);

    printf("Shader Linking Error. \n");
    CheckCompileErrors(shaderProgram, GL_LINK_STATUS, 0);

    glValidateProgram(shaderProgram);

    free((char*)vertexSource);
    free((char*)fragmentSource);

    return &program;
}

void UseShader(const Shader* shader)
{
    glUseProgram(shader->program);
}

void ShaderSetFloat(const Shader* shader, const char* name, float value)
{
    GLuint location = glGetUniformLocation(shader->program, name);
    glUniform1f(location, value);
}

void ShaderSetFloat2(const Shader* shader, const char* name, float value1, float value2)
{
    GLuint location = glGetUniformLocation(shader->program, name);
    glUniform2f(location, value1, value2);
}
