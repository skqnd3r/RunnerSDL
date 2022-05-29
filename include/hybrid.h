#ifndef HYBRID
#define HYBRID

int input_handler(Entity *entity,Config *app);
void drawEntity(Window *win,Entity *entity);
void drawCollider(Window *win,Entity *entity);
void Refresh(Window *win,Entity **entities);
void Timer(Clock *clock, Entity **entities);
void Close(Config *app,Entity **entities);


#endif