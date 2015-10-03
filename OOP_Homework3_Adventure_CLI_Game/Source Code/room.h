#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <iostream>
using namespace std;

class room_0_E
{
public:
    room_0_E(int direction=0,int mon=0,int prin=0);
    ~room_0_E();
    virtual bool show_dialog();
    virtual void set_route(room_0_E* room);
    int monster;
    int princess;
protected:
    virtual bool exec_command(string command);
    void command_menu();
    int exit_index[4];
    room_0_E* exit_gate[4];
};
#endif // ROOM_H
