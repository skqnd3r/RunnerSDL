#include "input.h"
#include "stdio.h"


int input_handler(Entity *entity){
    // catch event
    SDL_Event event;  // récupère ce que la personne tape sur son clavier

    // read event
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT : // Event quand la personne ferme la fenêtre
        return -1;
    case SDL_KEYDOWN :
        switch(event.key.keysym.sym)
        {
            case SDLK_UP:
                entity->pos_y -= 4;
                break;
            case SDLK_DOWN:
                entity->pos_y += 4;
                break;
        }
        printf("Key is down\n");
        break;                      // Break sert à sortir du switch
    case SDL_KEYUP   :
        printf("Key is up");
    }
    return 0;
}