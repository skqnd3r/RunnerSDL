#include <stdio.h>
#include "collider.h"
#include "entity.h"
#include "window.h"
#include "init.h"
#include "input.h"
#include "draw.h"

int main(){
    Window *win = malloc(sizeof(Window));
    if(initSDL(win) < 0){
        return -1;
    };
    SDL_SetRenderDrawColor(win->renderer, 96, 128, 255, 255); // Modifier couleur fond
    
    // init funciton
    Entity *entities[10];
    entities[0] = spawnPlayer(win);
    for(int i=1;i!=10;i++){
        entities[i] = spawnObstacle(win);
    }
    
    // animation
    // int counter =5;
    // int i = 0;

    entities[1]->hide=0;
    while(entities[0]->life!=0 && input_handler(entities[0]) == 0){
        Move(entities);
        isCollinding(entities);
        Refresh(win,entities);
        SDL_Delay(FPS(60));
    }

    // if dead
    // game over
    
    for(int i=0;i!=10;i++){
        free(entities[i]);
    }
    return 0;
}

// // factory
// if(null) {

//     int random()
// }
// else if (count == )
// {
//     spawnObstacl
//     null
// }
// i -=1