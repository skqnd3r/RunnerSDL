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
    // SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255); // Modifier couleur fond
    
    // init funciton
    Entity *entities[10];
    entities[0] = spawnPlayer(app);
    for(int i=1;i!=10;i++){
        entities[i] = spawnObstacle(app);
    }
    


    // animation
    // int counter =5;

    entities[1]->hide=0;
    while(input_handler(entities[0]) == 0){
        Move(entities);
        Refresh(app,entities);

        //while (50)
        //{
            /* code */
        
        
            //SDL_SetRenderDrawColor(app->renderer, 255, 255, 255, 255);
            //SDL_RenderClear(app->renderer);
        //SDL_RenderPresent(app->renderer);
       // } 

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

        SDL_Delay(16);
    }

    for(int i=0;i!=10;i++){
        free(entities[i]);
    }

    return 0;
}
// SDL_DestroyTexture(texture);
// SDL_FreeSurface(image);
// SDL_DestroyRenderer(renderer);
// SDL_DestroyWindow(window);