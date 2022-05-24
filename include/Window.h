#ifndef WINDOW
#define WINDOW

#include </Library/Frameworks/SDL2.Framework/Headers/SDL.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 380
#define WINDOW_NAME "RUNNER"

typedef struct {
    SDL_Renderer    *Renderer; 
    SDL_Window      *Window;
} WIN; /* Donner un nom au type */

#endif  /* !WINDOW */
