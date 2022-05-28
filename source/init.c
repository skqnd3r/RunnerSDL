#include "init.h"

int initSDL(Win *app){
    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Couldn't initialize SDL: %s\n",SDL_GetError());
    }
    
    // Create window
    app->window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
    WINDOW_WIDTH,WINDOW_HEIGHT,0);
    if (!app->window){
        printf("Failed to initialize %d x %d Windows : %s\n",WINDOW_WIDTH,WINDOW_HEIGHT, SDL_GetError());
        return -1;
    }

    // Set Render (don't change)
    app->renderer = SDL_CreateRenderer(app->window, -1,SDL_RENDERER_ACCELERATED);
    if (!app->renderer){
        printf("Failed to initialize renderer : %s\n",SDL_GetError());
        return -1;
    }
    
    // add background
    app->image = IMG_Load("/ressource/background_1920x1080.png");
    app->texture = SDL_CreateTextureFromSurface(app->renderer, app->image);
    

    return 0;
}