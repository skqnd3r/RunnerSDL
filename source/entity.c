#include "entity.h"

Entity *spawnPlayer(Window *win){
    Entity *player = malloc(sizeof(Entity));
    player->texture = loadTexture(win, "ressource/player.png");
    player->width = 50;
    player->height = 50;
    player->pos_x = 100;
    player->pos_y = WINDOW_HEIGHT/2-player->height/2;
    player->life = 1;
    player->speed = 1.5;
    player->mv_x = 1;
    player->mv_y = 0;
    player->hide = false;
    player->collider=setCollider(player);
    return player;
}

Entity *spawnObstacle(Window *win){
    Entity *obstacle = malloc(sizeof(Entity));
    // algo random
    obstacle->texture = loadTexture(win,"ressource/obstacle.png");
    obstacle->width = 50;
    obstacle->height = 50;
    obstacle->pos_x = WINDOW_WIDTH;
    obstacle->pos_y = WINDOW_HEIGHT-obstacle->height;
    obstacle->speed = 1;
    obstacle->life = 1;
    obstacle->mv_x = -1;
    obstacle->mv_y = 0;
    obstacle->hide = true;
    return obstacle;
}

SDL_Rect setCollider(Entity *entity){
    SDL_Rect collider;
    collider.x = entity->pos_x;
    collider.y = entity->pos_y;
    collider.w = entity->width;
    collider.h = entity->height;
    return collider;
}

void Move(Entity **entities){
    for(int i = 0;i!=10;i+=1){
        if(entities[i]->hide == 0){
            entities[i]->pos_y += entity_MVY;
            if(i!=0){
                entities[i]->collider=setCollider(entities[i]);
                entities[i]->pos_x += player_MVX*-1 + entity_MVX;
            } else {
                entities[i]->pos_x += player_MVX-1;
            }
            entities[i]->collider=setCollider(entities[i]);
        }
    }
}