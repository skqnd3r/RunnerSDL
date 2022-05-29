#include "library.h"
#include "macro.h"
#include "struct/window.h"
#include "struct/config.h"

Config *initApp(){
    Config *app = malloc(sizeof(Config));
    if(app==NULL){
        printf("Failed to allocate memory for App");
        return NULL;
    };

    Window *win = malloc(sizeof(Window));
    app->win=win;
    if(initSDL(app->win) < 0){
        printf("Error inside initSDL()");
        return NULL;
    };
    
    Clock *clock = malloc(sizeof(Clock));
    if(clock==NULL){
        printf("Failed to allocate memory for clock");
        return NULL;
    };
    app->clock=clock;
    app->clock->l_time=0;
    app->clock->l_frame=0;
    app->state=START;
    srand(time(0));
    return app;
}

int initSDL(Window *win){
    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Couldn't initialize SDL: %s\n",SDL_GetError());
    }
    
    // Create window
    win->window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
    WINDOW_WIDTH,WINDOW_HEIGHT,0);
    if (!win->window){
        printf("Failed to initialize %d x %d Windows : %s\n",WINDOW_WIDTH,WINDOW_HEIGHT, SDL_GetError());
        return -1;
    }

    // Set Render (don't change)
    win->renderer = SDL_CreateRenderer(win->window, -1,SDL_RENDERER_ACCELERATED);
    if (!win->renderer){
        printf("Failed to initialize renderer : %s\n",SDL_GetError());
        return -1;
    }
    
    // add background
    win->image = IMG_Load("ressource/background_1920x1080.png");
    if (!win->image){
        printf("Failed to import backgroubd: %s\n",SDL_GetError());
        return -1;
    }
    win->texture = SDL_CreateTextureFromSurface(win->renderer, win->image); 
    if (!win->texture){
        printf("Failed to import background texture: %s\n",SDL_GetError());
        return -1;
    }
    return 0;
}

void Close(Config *app,Entity **entities){
    for(int i=0;i!=10;i++){
        free(entities[i]);
    }
    SDL_DestroyTexture(app->win->texture);
    SDL_FreeSurface(app->win->image);
    SDL_DestroyRenderer(app->win->renderer);
    SDL_DestroyWindow(app->win->window);
    free(app->win);
    free(app);
}