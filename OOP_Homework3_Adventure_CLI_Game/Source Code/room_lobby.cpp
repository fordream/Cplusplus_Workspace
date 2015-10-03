#include "room_lobby.h"

extern int princess_encounter;
extern int princess_saved;
room_lobby::room_lobby(int direction_3,int direction_2,int direction_1,int direction,int mon,int prin):room_3_E(direction_3,direction_2,direction_1,direction,mon,prin)
{

}

bool room_lobby::show_dialog()
{
    if(princess_encounter)
    {
        cout<<"congradulations! you have saved the princess!"<<endl;
        princess_saved=1;
        return true;
    }
    else
    {
    cout<<"Welcome to the lobby. There are 3 exits as:";
    command_menu();
    }
    return true;
}
