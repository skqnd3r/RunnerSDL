#ifndef DRAW
#define DRAW

#include "macro.h"
#include "entity.h"
#include "window.h"
#include LIB_SDL_IMG

void prepareCanvas(Window *win);
void presentCanvas(Window *win);
SDL_Texture *loadTexture(Window *win,char *img_path);

void drawEntity(Window *win,Entity *entity);
void drawCollider(Window *win,Entity *entity);
void Refresh(Window *win,Entity **entities);

#endif