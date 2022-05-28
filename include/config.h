#ifndef CONFIG
#define CONFIG

#include "window.h"

#define MENU 0
#define PLAY 1
#define PAUSE 2

typedef struct{
    int state;
    Window win;
} Config;

#endif