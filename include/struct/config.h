#ifndef CONFIG
#define CONFIG

#include "struct/clock.h"
#include "struct/window.h"

typedef struct{
    int state;
    // FOR MENU
    int selected;
    Window *win;
    Clock *clock;
    int seed;
} Config;

Config *initApp();

#endif