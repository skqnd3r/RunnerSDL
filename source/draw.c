#include "draw.h"

void prepareCanvas(Window *win){
    SDL_RenderClear(win->renderer);
    // INSIDE A RECT
    SDL_Rect background={ 0, 0, WINDOW_WIDTH ,WINDOW_HEIGHT };
    SDL_RenderCopy(win->renderer, win->texture, NULL, &background);
}

void presentCanvas(Window *win){
    SDL_RenderPresent(win->renderer);
}

SDL_Texture *loadTexture(Window *win,char *img_path){      // Sert à transorfmer les fichiers d'image et à les modifier.
    SDL_Texture *texture;
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO, "Loading: %s", img_path);  
    texture = IMG_LoadTexture(win->renderer,img_path);
    if (texture == NULL){
        printf("Failed to load texture %s\n",IMG_GetError());
        return texture;
    }
    return texture;
}

void drawEntity(Window *win,Entity *entity){
    SDL_Rect dest={entity->pos_x, entity->pos_y, entity->width, entity->height};
    SDL_RenderCopy(win->renderer, entity->texture, NULL, &dest);
}

void drawCollider(Window *win,Entity *entity){
    SDL_SetRenderDrawColor(win->renderer,255,0,0,0);
    SDL_RenderDrawRect(win->renderer, &entity->collider);
}

void Refresh(Window *win,Entity **entities){
    // clear screen
    prepareCanvas(win);
    

    for(int i=0;i!=10;i++){
        // refresh pos
        if(entities[i]->hide == false){
            drawEntity(win, entities[i]);
            drawCollider(win,entities[i]);
        }
    }
    //print screen
    presentCanvas(win);
}