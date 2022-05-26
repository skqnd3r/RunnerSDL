#include "entity.h"

Entity *initPlayer(Win *app){
    Entity *player = malloc(sizeof(Entity));
    player->pos_x = 100;
    player->pos_y = 100;
    player->width = 50;
    player->height = 50;
    player->texture = loadTexture(app, "ressource/player.png");
    return player;
}

Entity *spawnObstacle(Win *app){
    Entity *obstacle = malloc(sizeof(Entity));
    obstacle->pos_x = 150;
    obstacle->pos_y = 150;
    obstacle->width = 50;
    obstacle->height = 50;
    obstacle->texture= loadTexture(app,"ressource/obstacle.png");
    return obstacle;
}