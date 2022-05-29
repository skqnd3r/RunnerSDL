#include "library.h"
#include "macro.h"
#include "struct/config.h"
#include "struct/entity.h"
#include "hybrid.h"


int main(){
    // init function
    Config *app = malloc(sizeof(Config));
    if(app==NULL){
        printf("Failed to allocate memory for App");
        return -1;
    };

    if(initApp(app) < 0){
        printf("Failed to initialize App");
        return -1;
    }

    // init funciton
    Entity *entities[10];
    for(int i=0;i!=10;i++){
        switch (i){
            case 0:
                entities[i] = spawnEntity(app->win,PLAYER);
                break;        
            case 11:
                entities[i] = spawnEntity(app->win,BONUS);
                break;
            default:
                entities[i] = spawnEntity(app->win,OBSTACLE);
                break;
        }
    }

    // START
    app->state=START;
    // animation
    // int counter =5;
    // int i = 0;
    app->clock->l_delay = SDL_GetTicks();
    app->clock->l_time = SDL_GetTicks();
    app->clock->l_frame = SDL_GetTicks();
    app->state=GAME;

    while(_player->state!=DEAD && input_handler(_player,app) == 0){
        switch(app->state){
            case GAME:
                Move(entities);
                isCollinding(entities);
                stateAction(entities);
                Event(entities);
                Refresh(app->win,entities);
                Timer(app->clock,entities);
                break;
            
            case PAUSE:
                Refresh(app->win,entities);
                SDL_Delay(FPS(90));
                break;
        }
    }

    // if dead
    // game over

    // CLOSE WIN
    for(int i=0;i!=10;i++){
        free(entities[i]);
    }
    SDL_DestroyTexture(app->win->texture);
    SDL_FreeSurface(app->win->image);
    SDL_DestroyRenderer(app->win->renderer);
    SDL_DestroyWindow(app->win->window);
    free(app->win);
    free(app);

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

