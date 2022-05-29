#ifndef MACRO
#define MACRO

//WINDOW
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 360
#define WINDOW_NAME "RunnerSDL"

//GAME STATEMENT
#define MENU 0
#define START 1
#define GAME 2
#define PAUSE 3

//ENTITY TAGS
#define PLAYER 0
#define OBSTACLE 1
#define BONUS 2

//ENTITY STATEMENT
#define NONE 0
#define HIT 1
#define DEAD 2
#define SUPER 3

//CLOCK
#define FPS(x) (int)1000/x
#define SEC(x) (int)2*x
#define seconds 0
#define frames 1
#define DONE -1

//MOVEMENT
#define FAST 1
#define SLOW -1
#define DOWN 4
#define UP -4

//SHORTCUT
#define _player entities[0]

#define entity_MVX entities[i]->mv_x*entities[i]->speed
#define entity_MVY entities[i]->mv_y*entities[i]->speed

#define true 1
#define false 0

#define OFFSET(x,y,w,h) ({\
offset_x = x;\
offset_y = y;\
offset_w = w;\
offset_h = h;\
})


#endif