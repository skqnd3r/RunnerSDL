#ifndef MACRO
#define MACRO

// change btwn mac or win

#define LIB_SDL <SDL2/SDL.h>
//#define LIB_SDL </Library/Frameworks/SDL2.framework/Headers/SDL.h>

#define LIB_SDL_IMG <SDL2/SDL_image.h>
//#define LIB_SDL_IMG </Library/Frameworks/SDL2.framework/Headers/SDL_image.h>

#define player_MVX entities[0]->mv_x*entities[0]->speed
#define player_MVY entities[0]->mv_y*entities[0]->speed

#define entity_MVX entities[i]->mv_x*entities[i]->speed
#define entity_MVY entities[i]->mv_y*entities[i]->speed

#define true 1
#define false 0

#define PLAYER 0
#define OBSTACLE 1
#define BONUS 2

#define OFFSET(x,y,w,h) ({\
offset_x = x;\
offset_y = y;\
offset_w = w;\
offset_h = h;\
})


// STATE
// #define PAUSE
// #define DEAD
// #define PLAY
// #define MENU

#endif