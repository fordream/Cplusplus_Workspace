#include "room_3_e.h"

extern int princess_encounter;
room_3_E::room_3_E(int direction_3,int direction_2,int direction_1,int direction,int mon,int prin):room_2_E(direction_2,direction_1,direction,mon,prin)
{
    exit_index[direction_3]=1;
}

bool room_3_E::show_dialog()
{
    if(!monster&&!princess)
    {
    cout<<"Welcome to the room_3_E. There are 4 exits as:";
    command_menu();
    }
    else
    {
        if(princess)
        {
          princess_encounter=1;
          cout<<"You have found the princess, please take her back to lobby"<<endl;
          cout<<"Welcome to the room_3_E. There are 4 exits as:";
          command_menu();
        }
        else
        return false;
    }
}

void room_3_E::set_route(room_0_E *room, room_0_E *room1, room_0_E *room2, room_0_E *room3)
{
    room_0_E* tmp[4];
    tmp[0]=room;
    tmp[1]=room1;
    tmp[2]=room2;
    tmp[3]=room3;
    int i;
    int j=0;
    for(i=0;i<4;i++)
    if(exit_index[i]!=0)
    {
        exit_gate[i]=tmp[j];
        j++;
    }
}

