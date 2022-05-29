#ifndef WINDOW
#define WINDOW

typedef struct {
    SDL_Renderer    *renderer;
    SDL_Window      *window;
    SDL_Surface     *image;
    SDL_Texture     *texture;
} Window; /* Donner un nom au type */

int initSDL(Window *win);
void prepareCanvas(Window *win);
void presentCanvas(Window *win);
SDL_Texture *loadTexture(Window *win,char *img_path);

#endif