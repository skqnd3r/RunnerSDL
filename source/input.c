#include "library.h"
#include "macro.h"
#include "struct/config.h"
#include "struct/entity.h"

int input_handler(Entity *entity,Config *app){
    // read event
    SDL_Event event;  // récupère ce que la personne tape sur son clavier
    SDL_PollEvent(&event);
    const Uint8* keys = SDL_GetKeyboardState(NULL);    
    
    if(app->state==GAME){
        entity->mv_y = 0;
        entity->mv_x = 0;
        
        if(keys[SDL_SCANCODE_LEFT] && keys[SDL_SCANCODE_RIGHT]){
            entity->mv_x = NONE;
        } else if (keys[SDL_SCANCODE_LEFT]){
            entity->mv_x = SLOW;
        } else if (keys[SDL_SCANCODE_RIGHT]){
            entity->mv_x = FAST;
        }

        if(keys[SDL_SCANCODE_UP]){
            if(entity->collider.y >= DOWN){
                entity->mv_y = UP;
            }
        }
        if(keys[SDL_SCANCODE_DOWN]){
            if(entity->pos_y <= WINDOW_HEIGHT-(entity->collider.h-UP)){
                entity->mv_y = DOWN;
            }
        }
    }

    switch(event.type){
        case SDL_QUIT : // Event quand la personne ferme la fenêtre
            return -1;
            break;
        case SDL_KEYDOWN:
            break;
        case SDL_KEYUP:
            if(event.key.keysym.sym == SDLK_ESCAPE){
                if(app->state==PAUSE){
                    app->state=GAME;
                    return 0;
                } else if(app->state==GAME){
                    app->state=PAUSE;
                    return 0;
                }
            }
            break;
    }
    return 0;
}

void Move(Entity **entities){
    for(int i = 0;i!=10;i+=1){
        if(entities[i]->hide == 0){
            entities[i]->pos_y += entity_MVY;

            if(entities[i]->tag==PLAYER){
                switch (_player->mv_x){
                    case FAST:
                        if(_player->speed<3){
                            _player->speed+=0.05;
                        }
                        if(_player->pos_x<160){
                            _player->pos_x+=1;
                        }
                        break;
                    case SLOW:
                        if(_player->speed>1){
                            _player->speed-=0.05;
                        }
                        if(_player->pos_x>40){
                            _player->pos_x-=1;
                        }
                        break;
                    case NONE:
                        if(_player->speed>1.5){
                            _player->speed-=0.05;
                        } else if(_player->speed<1.5){
                            _player->speed+=0.05;
                        }

                        if(_player->pos_x>100){
                            _player->pos_x-=1;
                        } else if(_player->pos_x<100){
                            _player->pos_x+=1;
                        }
                        break;
                default:
                    break;
                }
            } else {
                entities[i]->collider=setCollider(entities[i]);
                entities[i]->pos_x += _player->speed*-1 + entity_MVX;
                entities[i]->pos_x += 0;
            }
            entities[i]->collider=setCollider(entities[i]);
        }
    }
}