#ifndef AX_RENDER_H
#define AX_RENDER_H


void GLDrawBasic(Shader* shader, int indices)
{
    UseShader(shader);
    glDrawArrays(GL_TRIANGLES, 0, indices);
}


#endif
