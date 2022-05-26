#include <stdio.h>
#include "entity.h"
#include "window.h"
#include "init.h"
#include "input.h"
#include "draw.h"

int main()
{
    Win *app = malloc(sizeof(Win));
    if(initSDL(app) < 0){
        return -1;
    };
    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255); // Modifier couleur fond
    
    // spawn obstacle
    // Entity *obstacle = spawnObstacle();
    

    Entity *player = initPlayer(app);
    Entity *obstacle = spawnObstacle(app);

    while(input_handler(player) == 0){
        // clear screen
        prepareCanvas(app);
        
        // refresh pos
        drawEntity(app, obstacle);
        drawEntity(app, player);

        //draw collider
        drawCollider(app,obstacle);
        drawCollider(app,player);

        //print screen
        presentCanvas(app);
        SDL_Delay(16);
    }
    return 0;
}