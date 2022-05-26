#ifndef ENTITY
#define ENTITY

#include "macro.h"
#include LIB_SDL_IMG

typedef struct {
    int pos_x;
    int pos_y;
    int width;
    int height;
    SDL_Texture *texture;
    SDL_Rect collider;
} Entity;

#include "window.h"
#include "draw.h"

Entity *initPlayer(Win *app);
Entity *spawnObstacle(Win *app);

#endif