#include "Render.h"
#include "Global.h"

void render_init(void)
{
	global.width  = 640;
	global.height = 480;
	global.title  = "Game";
}


void RenderClear(float r, float g, float b)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(r,g,b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void RenderBegin() {}
void RenderQuad() {}
void RenderEnd() {}
