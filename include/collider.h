#ifndef COLLIDER
#define COLLIDER

#include "macro.h"
#include LIB_SDL_IMG
#include "entity.h"

int check_collision(Entity *entityA, Entity *entityB);
void isCollinding(Entity **entities);

#endif