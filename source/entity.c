#include "library.h"
#include "macro.h"
#include "struct/window.h"
#include "struct/entity.h"

int getRand(int min, int max);

void Factory(Entity *entity){
    entity->state=NONE;
    entity->pos_y = getRand(0,WINDOW_HEIGHT-entity->height);
    entity->pos_x = WINDOW_WIDTH;
    entity->speed = (float) getRand(1,4);
    entity->mv_x = getRand(-3,-1);
    entity->mv_y = 0;
    entity->frame = DONE;
    entity->counter = SEC(getRand(2,10));
    entity->score = 100;
    entity->life = 1;
}

Entity *spawnEntity(Window *win,int tag){
    Entity *entity = malloc(sizeof(Entity));
    entity->tag=tag;
    
    if(tag==PLAYER){
        entity->texture = loadTexture(win, "ressource/ship_2973x904.png");
        entity->width = (int)2973/25;
        entity->height = (int)904/25;
        entity->pos_x = 100;
        entity->pos_y = WINDOW_HEIGHT/2-entity->height/2;
        entity->life = 3;
        entity->speed = 1.5;
        entity->mv_x = 1;
        entity->mv_y = 0;
        entity->hide = false;
        entity->state=NONE;
        entity->score = 0;
    } else {
        switch (tag){        
            case OBSTACLE:
                entity->texture = loadTexture(win,"ressource/meteor_3491x1376.png");
                entity->width = (int)3491/30;
                entity->height = (int)1376/30;
                Factory(entity);
                break;

            case BONUS:
                // entity->width = (int)3491/30;
                // entity->height = (int)1376/30;
                // Factory(entity);
                break;
        }
        entity->life = 1;
        entity->hide = true;
    }
    entity->collider=setCollider(entity);
    return entity;
}

void Move(Entity **entities){
    for(int i = 0;i!=10;i+=1){
        if(entities[i]->hide == 0){
            entities[i]->pos_y += entity_MVY;

            // FIRST IS PLAYER *par vitesse
            if(entities[i]->tag!=PLAYER){
                entities[i]->collider=setCollider(entities[i]);
                entities[i]->pos_x += _player->speed*-1 + entity_MVX;
            } else {
                // PLAYER SPEED
                // SWITCH TO ANIM
                // entities[i]->pos_x += _player->speed*PLAYER->mv_x;
                entities[i]->pos_x += 0;
            }

            entities[i]->collider=setCollider(entities[i]);
        }
    }
}

void stateAction(Entity **entities){
    for(int i = 0;i!=10;i+=1){
        if(entities[i]->hide==false){
        // check position meteor -> DEAD
            if(entities[i]->tag!=PLAYER){
                if(entities[i]->pos_x<0-entities[i]->width){
                    entities[i]->state=HIT;
                    _player->score+=entities[i]->score;
                    printf("Score : %d\n",_player->score);
                }
            }

            if(entities[i]->state!=NONE){
                if(entities[i]->state==HIT){
                    entities[i]->life-=1;
                    if(entities[i]->life==0){
                        entities[i]->state=DEAD;
                    } else {
                        entities[i]->state=NONE;
                    }
                }

                if(entities[i]->state==DEAD){
                    switch (entities[i]->tag){
                        case PLAYER:
                            return;
                        case OBSTACLE:
                            // explode
                            entities[i]->hide=true;
                            Factory(entities[i]);
                            break;
                        case BONUS:
                            _player->state=SUPER;
                            break;
                    }
                }
            }
        }
    }
}
