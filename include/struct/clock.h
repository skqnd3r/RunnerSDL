#ifndef CLOCK
#define CLOCK


typedef struct{
    unsigned int l_delay;
    unsigned int l_time;
    unsigned int l_frame;
} Clock;

#include "struct/entity.h"

void Count(int arg, Entity **entities);

#endif