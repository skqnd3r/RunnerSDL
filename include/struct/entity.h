#ifndef ENTITY
#define ENTITY

typedef struct {
    int tag;
    int hide;
    int frame;
    int counter;
    SDL_Texture *texture;
    SDL_Rect collider;
    int state;
    int life;
    int score;
    float speed;
    int pos_x;
    int pos_y;
    int width;
    int height;
    int mv_x;
    int mv_y;
} Entity;

#include "struct/window.h"

int check_collision(Entity *entityA, Entity *entityB);
void isCollinding(Entity **entities);
Entity *spawnEntity(Window *win,int tag);
SDL_Rect setCollider(Entity *entity);
void Move(Entity **entities);
void stateAction(Entity **entities);
void Event(Entity **entities);

#endif