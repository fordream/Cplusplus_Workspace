#ifndef ROOM_2_E_H
#define ROOM_2_E_H
#include "room_1_e.h"

class room_2_E:public room_1_E
{
public:
    room_2_E(int direction_2=2,int direction_1=1,int direction=0,int mon=0,int prin=0);
    virtual bool show_dialog();
    virtual void set_route(room_0_E* room,room_0_E* room1,room_0_E* room2);
};
#endif // ROOM_2_E_H
