#ifndef DRAW
#define DRAW

#include "macro.h"
#include "window.h"
#include LIB_SDL_IMG

void prepareCanvas(Win *app);
void presentCanvas(Win *app);
SDL_Texture *loadTexture(Win *app,char *img_path);

#endif