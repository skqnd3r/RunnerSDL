#include "input.h"


int input_handler(){
    // catch event
    SDL_Event event;

    // read event
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT :
        return -1;
    default:
        break;
    }
    return 0;
}