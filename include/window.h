#ifndef WINDOW
#define WINDOW

#include "macro.h"
#include LIB_SDL

#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 360
#define WINDOW_NAME "RunnerSDL"

typedef struct {
    SDL_Renderer    *renderer; 
    SDL_Window      *window;
} Win; /* Donner un nom au type */

#endif  /* !WINDOW */
