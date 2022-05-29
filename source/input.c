#include "library.h"
#include "macro.h"
#include "struct/config.h"
#include "struct/entity.h"

int input_handler(Entity *entity,Config *app){
    // read event
    SDL_Event event;  // récupère ce que la personne tape sur son clavier
    SDL_PollEvent(&event);
    const Uint8* keys = SDL_GetKeyboardState(NULL);
    
    if(app->state==GAME){
        entity->mv_y = 0;
        entity->mv_x = 0;
        
        if(keys[SDL_SCANCODE_LEFT] && keys[SDL_SCANCODE_RIGHT]){
            entity->mv_x = NONE;
        } else if (keys[SDL_SCANCODE_LEFT]){
            entity->mv_x = SLOW;
        } else if (keys[SDL_SCANCODE_RIGHT]){
            entity->mv_x = FAST;
        }

        if(keys[SDL_SCANCODE_UP]){
            if(entity->collider.y >= DOWN){
                entity->mv_y = UP;
            }
        }
        if(keys[SDL_SCANCODE_DOWN]){
            if(entity->pos_y <= WINDOW_HEIGHT-(entity->collider.h-UP)){
                entity->mv_y = DOWN;
            }
        }
    }

    switch(event.type){
        case SDL_QUIT : // Event quand la personne ferme la fenêtre
            return -1;
            break;
        case SDL_KEYDOWN:
            break;
        case SDL_KEYUP:
            if(event.key.keysym.sym == SDLK_ESCAPE){
                if(app->state==PAUSE){
                    app->state=GAME;
                    return 0;
                } else if(app->state==GAME){
                    app->state=PAUSE;
                    return 0;
                }
            }
            break;
    }
    return 0;
}