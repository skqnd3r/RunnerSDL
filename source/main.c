#include <stdio.h>
#include "window.h"
#include "init.h"
#include "input.h"
#include "draw.h"

int main()
{
    Win *app = malloc(sizeof(Win));

    if(initSDL(app) < 0){
        return -1;
    }

    while(input_handler() == 0){
        prepareCanvas(app);
        presentCanvas(app);
        SDL_Delay(16);
    }
    return 0;
}