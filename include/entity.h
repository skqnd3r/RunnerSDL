#ifndef ENTITY
#define ENTITY

#include "macro.h"
#include LIB_SDL_IMG

typedef struct {
    SDL_Texture *texture;
    int pos_x;
    int pos_y;
    int width;
    int height;
    SDL_Rect collider;
    int life;
    float speed;
    int mv_x;
    int mv_y;
    int hide;
} Entity;

#include "window.h"
#include "draw.h"

Entity *spawnPlayer(Win *app);
Entity *spawnObstacle(Win *app);

SDL_Rect setCollider(Entity *entity);
void Move(Entity **entities);


#endif