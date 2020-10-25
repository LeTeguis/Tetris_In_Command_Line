#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <conio.h>
#include "../header/Utils.h"

typedef enum {SPECIAL = 224, AUTHER}MODE;
typedef enum {KEY_LEFT = 75, KEY_RIGHT = 77, KEY_UP = 72, KEY_DOWN = 80, KEY_P = 112, KEY_ESCAPE = 27, KEY_AUTHER}KEY;

typedef struct Event Event;
struct Event{
    MODE mode;
    KEY key;
};

void get_Event(Event*);
int poll_event(Event*);
void vider_Event(Event*);

#endif // EVENT_H_INCLUDED
