#include "collider.h"

int check_collision(Entity *entityA, Entity *entityB){
    SDL_Rect A = entityA->collider;
    SDL_Rect B = entityB->collider;

    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int botA, botB;

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
            entities[i]->life-=1;
            entities[0]->life-=1;
        }
    }
}