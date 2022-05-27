#include "entity.h"

Entity *spawnPlayer(Win *app){
    Entity *player = malloc(sizeof(Entity));
    player->texture = loadTexture(app, "ressource/player.png");
    player->width = 50;
    player->height = 50;
    player->pos_x = 100;
    player->pos_y = WINDOW_HEIGHT/2-player->height/2;
    player->life = 3;
    player->speed = 1.5;
    player->mv_x = 1;
    player->mv_y = 0;
    player->hide = 0;
    return player;
}

Entity *spawnObstacle(Win *app){
    Entity *obstacle = malloc(sizeof(Entity));
    // algo random
    obstacle->texture = loadTexture(app,"ressource/obstacle.png");
    obstacle->width = 50;
    obstacle->height = 50;
    obstacle->pos_x = WINDOW_WIDTH-obstacle->width;
    obstacle->pos_y = WINDOW_HEIGHT-obstacle->height;
    obstacle->life = 1;
    obstacle->mv_x =- 1;
    obstacle->mv_y = 0;
    obstacle->hide = 1;
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
        if(i==0){
            entities[i]->pos_y += entities[i]->mv_y;
        } else {
            if(entities[i]->hide == 0){
                entities[i]->pos_x += player_MV + entity_MVX;
                entities[i]->pos_y += entity_MVY;
            }
        }
    }
};