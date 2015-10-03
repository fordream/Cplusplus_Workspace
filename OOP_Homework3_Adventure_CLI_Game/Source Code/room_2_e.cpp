#include "room_2_e.h"

extern int princess_encounter;
room_2_E::room_2_E(int direction_2,int direction_1,int direction,int mon,int prin):room_1_E(direction_1,direction,mon,prin)
{
    exit_index[direction_2]=1;
}

bool room_2_E::show_dialog()
{
    if(!monster&&!princess)
    {
    cout<<"Welcome to the room_2_E. There are 3 exits as:";
    command_menu();
    }
    else
    {
        if(princess)
        {
          princess_encounter=1;
          cout<<"You have found the princess, please take her back to lobby"<<endl;
          cout<<"Welcome to the room_2_E. There are 3 exits as:";
          command_menu();
        }
        else
        return false;
    }
}

void room_2_E::set_route(room_0_E *room, room_0_E *room1, room_0_E *room2)
{
    room_0_E* tmp[3];
    tmp[0]=room;
    tmp[1]=room1;
    tmp[2]=room2;
    int i;
    int j=0;
    for(i=0;i<4;i++)
    if(exit_index[i]!=0)
    {
        exit_gate[i]=tmp[j];
        j++;
    }
}
