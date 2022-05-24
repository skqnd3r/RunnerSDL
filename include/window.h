#ifndef WINDOW
#define WINDOW

// #include </Library/Frameworks/SDL2.Framework/Headers/SDL.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 360
#define WINDOW_NAME "RunnerSDL"

typedef struct {
    SDL_Renderer    *Renderer; 
    SDL_Window      *Window;
} Win; /* Donner un nom au type */

#endif  /* !WINDOW */
