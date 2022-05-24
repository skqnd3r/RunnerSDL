#include "init.h"

int initSDL(Win *window){
    if (SDL_init(SDL_INIT_VIDEO) < 0){
        printf("Couldn't initialize SDL: %s\n",SDL_GetError());
    }
}