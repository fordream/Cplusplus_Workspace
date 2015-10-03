#ifndef ROOM_1_E_H
#define ROOM_1_E_H
#include "room.h"

class room_1_E:public room_0_E
{
public:
    room_1_E(int direction_1=1,int direction=0,int mon=0,int prin=0);
    virtual bool show_dialog();
    virtual void set_route(room_0_E* room,room_0_E* room1);
protected:
};

#endif // ROOM_1_E_H
