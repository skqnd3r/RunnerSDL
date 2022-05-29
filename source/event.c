#include "library.h"
#include "macro.h"
#include "struct/clock.h"
#include "struct/entity.h"

void Timer(Clock *clock,Entity **entities){
    unsigned int ticks = SDL_GetTicks();
    while(ticks < clock->l_delay + FPS(90)){
        ticks = SDL_GetTicks();
        // HALF SEC
        if(ticks > clock->l_time + 500){
            Count(seconds,entities);
            clock->l_time = ticks;
        }
        // FRAME ANIM
        if(ticks > clock->l_frame + FPS(23)){
            Count(frames,entities);
            clock->l_frame = ticks;
        }
    }
    clock->l_delay = ticks;
}

int getRand(int min, int max){
    return (int) rand() % (max - min + 1) + min;
}

void Count(int arg,Entity **entities){
    for(int i=0;i!=10;i++){
        if(entities[i]->hide==true){
            switch(arg){
            case seconds:
                if(entities[i]->counter!=DONE){
                    entities[i]->counter-=1;
                    // printf("%d : %d\n",entities[i]->tag,entities[i]->frame);
                }
                break;
            case frames:
                if(entities[i]->frame!=DONE){
                    entities[i]->frame-=1;
                }
                break;
            }
        }
    }
}

void Event(Entity **entities){
    // HAS ANIMATION
    for(int i = 0;i!=10;i+=1){
        switch(entities[i]->hide){
            case false:
                switch (entities[i]->tag){
                    case PLAYER:
                        // START
                        
                        // DEATH
                        // IMAGE TO WHITE
                        
                        // SUPER
                        
                        break;
                }
                break;
            case true:
                switch (entities[i]->tag){
                    case OBSTACLE:
                        if(entities[i]->counter==0 && entities[i]->life==1){
                            entities[i]->hide=false;
                            entities[i]->counter=DONE;
                        }
                        break;
                    case BONUS:
                        /* code */
                        break;
                    default:
                        break;
                }
                break;
        }
    }
}