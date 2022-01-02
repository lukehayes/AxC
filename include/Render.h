#ifndef AX_RENDER_H
#define AX_RENDER_H

void Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}


void GLDrawBasic(Shader* shader, int indices)
{
    UseShader(shader);
    glDrawArrays(GL_LINES, 0, indices);
}


#endif
