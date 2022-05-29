#include "library.h"
#include "macro.h"
#include "struct/config.h"
#include "struct/entity.h"
#include "hybrid.h"


int main(){
    // init function
    Config *app = initApp();
    if(app==NULL){
        printf("Failed to initialize App");
        return -1;
    };

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
    
    while(_player->state!=DEAD && input_handler(_player,app) == 0){
        switch(app->state){
            case START:
                app->clock->l_delay = SDL_GetTicks();
                app->clock->l_time = SDL_GetTicks();
                app->clock->l_frame = SDL_GetTicks();
                app->state=GAME;
                break;

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

    if(_player->state==DEAD){
        printf("GAME OVER\n");
    }
    // game over

    // CLOSE WIN
    Close(app,entities);
    return 0;
}