#ifndef MACRO
#define MACRO

// change btwn mac or win

#define LIB_SDL <SDL2/SDL.h>
//#define LIB_SDL </Library/Frameworks/SDL2.framework/Headers/SDL.h>

#define LIB_SDL_IMG <SDL2/SDL_image.h>
//#define LIB_SDL_IMG </Library/Frameworks/SDL2.framework/Headers/SDL_image.h>

#define player_MV (entities[0]->mv_x*-1)*entities[0]->speed
#define entity_MVX entities[i]->mv_x*entities[i]->speed
#define entity_MVY entities[i]->mv_y*entities[i]->speed

#endif