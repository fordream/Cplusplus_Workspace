#include <iostream>
#include <cstdlib>
#include "room.h"
#include "room_1_e.h"
#include "room_2_e.h"
#include "room_3_e.h"
#include "room_lobby.h"
#include "time.h" /*需引用的头文件*/

#define east 0
#define north 1
#define west 2
#define south 3
using namespace std;

int princess_saved;
int princess_encounter;
room_lobby* map()
{
    room_3_E *r4;
    room_2_E *r3;
    room_2_E *r2,*r1b;
    room_1_E *r1a,*r1c;
    room_0_E *r2a,*r2b,*r2c,*r4a,*r4b;
    room_lobby *lobby;
    int monst[11];
    int princ[11];
    int i,j;
    for(i=0;i<10;i++)
    {
       monst[i]=princ[i]=0;
    }

    while(1)
    {
    srand((unsigned)time(NULL)); /*随机种子*/
    i=rand()%11; /*n为X~Y之间的随机数*/
    j=rand()%11;
    if(i!=j)
       break;
    }
    monst[i]=1;
    princ[j]=1;
    r4=new room_3_E(0,1,2,3,monst[0],princ[0]);
    r3=new room_2_E(east,north,west,monst[1],princ[1]);
    r2=new room_2_E(north,west,south,monst[2],princ[2]);
    r1b=new room_2_E(east,south,west,monst[3],princ[3]);
    r1a=new room_1_E(west,south,monst[4],princ[4]);
    r1c=new room_1_E(east,north,monst[5],princ[5]);
    r2a=new room_0_E(west,monst[6],princ[6]);
    r2b=new room_0_E(east,monst[7],princ[7]);
    r2c=new room_0_E(north,monst[8],princ[8]);
    r4a=new room_0_E(south,monst[9],princ[9]);
    r4b=new room_0_E(east,monst[10],princ[10]);
    lobby=new room_lobby;

    r4->set_route(r1b,r4a,r4b,r1c);
    r3->set_route(r2,r1b,r1c);
    r2->set_route(r1a,r3,lobby);
    r1a->set_route(r1b,r2);
    r1b->set_route(r1a,r4,r3);
    r1c->set_route(r3,r4);
    r2a->set_route(lobby);
    r2b->set_route(lobby);
    r2c->set_route(lobby);
    r4a->set_route(r4);
    r4b->set_route(r4);
    lobby->set_route(r2a,r2,r2b,r2c);

    return lobby;
}

int main()
{
    room_lobby* lobby;
    while(1)
    {   lobby=map();
        if(lobby->show_dialog()&&!princess_saved)
        cout<<"Monster encountered!! Game over!!"<<endl;
        else if(princess_saved)
        cout<<"You Win!!";
        cout<<"restart? yes or no:";
        string option;
        cin>>option;
        if(option=="yes")
            princess_encounter=0;
        else if(option=="no")
            break;
    }
    return 0;
}
