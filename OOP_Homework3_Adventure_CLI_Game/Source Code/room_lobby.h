#ifndef ROOM_LOBBY_H
#define ROOM_LOBBY_H

#include "room_3_e.h"

class room_lobby:public room_3_E
{
public:
    room_lobby(int direction_3=3,int direction_2=2,int direction_1=1,int direction=0,int mon=0,int prin=0);
    virtual bool show_dialog();
};

#endif // ROOM_LOBBY_H
