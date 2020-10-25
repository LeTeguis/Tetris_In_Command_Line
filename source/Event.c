#include "../header/Event.h"

void get_Event(Event* e){
    int event = _getch();

    if(event == 0 || event == 224){
        e->mode = SPECIAL;
    }

    if(e->mode == SPECIAL){
        event = _getch();
        e->key = event;
    }else{
        e->key = event;
    }
}
int poll_event(Event* e){
    if(_kbhit()){
        get_Event(e);
        return 1;
    }
    return 0;
}

void vider_Event(Event* e){
    e->key = KEY_AUTHER;
    e->mode = AUTHER;
}
