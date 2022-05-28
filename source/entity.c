#include "entity.h"

Entity *spawnEntity(Window *win,int tag){
    Entity *entity = malloc(sizeof(Entity));
    entity->tag=tag;
    if(tag==PLAYER){
        entity->texture = loadTexture(win, "ressource/ship_2973x904.png");
        entity->width = (int)2973/25;
        entity->height = (int)904/25;
        entity->pos_x = 100;
        entity->pos_y = WINDOW_HEIGHT/2-entity->height/2;
        entity->life = 3;
        entity->speed = 1.5;
        entity->mv_x = 1;
        entity->mv_y = 0;
        entity->hide = false;
    } else {
        switch (tag){        
            case OBSTACLE:
                entity->texture = loadTexture(win,"ressource/meteor_3491x1376.png");
                entity->width = (int)3491/30;
                entity->height = (int)1376/30;
                
                // FACTORY
                entity->pos_y = WINDOW_HEIGHT-entity->height;
                entity->speed = 1;
                entity->life = 1;
                entity->mv_x = -1;
                entity->mv_y = 0;
                break;

            case BONUS:
                entity->width = (int)3491/30;
                entity->height = (int)1376/30;
                break;
        }
        entity->pos_x = WINDOW_WIDTH;
        entity->life = 1;
        entity->hide = true;

    }
    entity->collider=setCollider(entity);
    return entity;
}

SDL_Rect setCollider(Entity *entity){
    SDL_Rect collider;

    int offset_x;
    int offset_y;
    int offset_w;
    int offset_h;

    switch(entity->tag){
        case PLAYER:
            OFFSET(25,0,-25,-13);
            break;
        case OBSTACLE:
            OFFSET(25,0,-25,-13);
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

void Move(Entity **entities){
    for(int i = 0;i!=10;i+=1){
        if(entities[i]->hide == 0){
            entities[i]->pos_y += entity_MVY;
            if(entities[i]->tag!=PLAYER){
                entities[i]->collider=setCollider(entities[i]);
                entities[i]->pos_x += player_MVX*-1 + entity_MVX;
            } else {
                entities[i]->pos_x += player_MVX-1;
            }
            entities[i]->collider=setCollider(entities[i]);
        }
    }
}