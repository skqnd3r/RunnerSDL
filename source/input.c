#include "input.h"
#include "stdio.h"


int input_handler(Entity *entity){
    // DIRECTIONS AXIS
    const Uint8* keys = SDL_GetKeyboardState(NULL);
    // if(keys[SDLK_LEFT]){
    
    // }
    // if(keys[SDLK_RIGHT]){
    
    // }
    entity->mv_y = 0;
    if(keys[SDL_SCANCODE_UP]){
        if(entity->pos_y >= 0){
            entity->mv_y = -4;
        }
    }
    if(keys[SDL_SCANCODE_DOWN])
    {
        if(entity->pos_y <= WINDOW_HEIGHT-entity->height){
            entity->mv_y = 4;
        }
    }
    
    // read event
    SDL_Event event;  // récupère ce que la personne tape sur son clavier
    SDL_PollEvent(&event);

    switch (event.type){
        case SDL_QUIT : // Event quand la personne ferme la fenêtre
            return -1;
    }
    return 0;
}