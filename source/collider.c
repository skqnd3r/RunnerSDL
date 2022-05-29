#include "library.h"
#include "macro.h"
#include "struct/entity.h"

SDL_Rect setCollider(Entity *entity){
    SDL_Rect collider;

    int offset_x, offset_y, offset_w, offset_h;

    switch(entity->tag){
        case PLAYER:
            OFFSET(25,0,-25,-13);
            break;
        case OBSTACLE:
            OFFSET(5,10,-30,-20);
            break;
        case BONUS:
            OFFSET(25,0,-25,-13);
            break;
    }

    collider.x = entity->pos_x+offset_x;
    collider.y = entity->pos_y+offset_y;
    collider.w = entity->width+offset_w;
    collider.h = entity->height+offset_h;

    return collider;
}

int check_collision(Entity *entityA, Entity *entityB){
    SDL_Rect A = entityA->collider;
    SDL_Rect B = entityB->collider;

    int leftA, leftB, rightA, rightB, topA, topB, botA, botB;

    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    botA = A.y + A.h;

    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    botB = B.y + B.h;

    if( botA <= topB
    || topA >= botB
    || rightA <= leftB
    || leftA >= rightB){
        return false;
    }
    return true;
}

void isCollinding(Entity **entities){
    for(int i = 1;i!=10;i+=1){
        if(entities[i]->hide==false
        && check_collision(entities[0],entities[i])==true){
            entities[i]->state=HIT;
            if(_player->state!=SUPER){
                _player->state=HIT;
            }
        }
    }
}