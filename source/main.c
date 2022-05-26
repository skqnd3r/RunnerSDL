#include <stdio.h>
#include "window.h"
#include "init.h"
#include "input.h"
#include "draw.h"

int main()
{
    Win *app = malloc(sizeof(Win));
    Entity *player = malloc(sizeof(Entity));

    if(initSDL(app) < 0){
        return -1;

    player->pos_x = 100;
    player->pos_y = 100;
    player->width = 50;
    player->height = 50;
    player->texture= loadTexture(app, "ressource/Player.png");
    };
    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255); // Modifier couleur player

    while(input_handler(player) == 0){
        prepareCanvas(app);
        drawEntity(app, player);
        presentCanvas(app);
        SDL_Delay(16);
    }
    return 0;
}