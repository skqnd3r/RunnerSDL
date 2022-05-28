#ifndef WINDOW
#define WINDOW

#include "macro.h"
#include LIB_SDL

#define FPS(x) (int)1000/x
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
} Window; /* Donner un nom au type */

#endif  /* !WINDOW */