#ifndef WINDOW
#define WINDOW

#include "macro.h"
#include LIB_SDL

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 360
#define WINDOW_NAME "RunnerSDL"

typedef struct {
    // window application
    SDL_Renderer    *renderer;
    SDL_Window      *window;
    // backgroung window
    SDL_Surface     *image;
    SDL_Texture     *texture;

} Win; /* Donner un nom au type */

#endif  /* !WINDOW */  
