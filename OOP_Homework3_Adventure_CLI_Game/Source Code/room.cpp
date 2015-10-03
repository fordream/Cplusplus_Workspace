#include "room.h"
#include "iostream"
using namespace std;

extern int princess_encounter;
room_0_E::room_0_E(int direction,int mon,int prin)
{
    monster=princess=0;
    int i;
    for(i=0;i<4;i++)
    exit_index[i]=0;
    exit_index[direction]=1;
    if(mon)
        monster=1;
    if(prin)
        princess=1;
}

bool room_0_E::show_dialog()
{
   if(!monster&&!princess)
   {
   cout<<"Welcome to the deadend,There are 1 exit please go back, which is:";
   command_menu();
   }
   else
   {
       if(princess)
       {
         princess_encounter=1;
         cout<<"You have found the princess, please take her back to lobby"<<endl;
         cout<<"Welcome to the deadend,There are 1 exit please go back, which is:";
         command_menu();
       }
       else
       return false;
   }
}

bool room_0_E::exec_command(string command)
{
    room_0_E* direction_index;
    if(command=="go east")
    {
        if(!exit_index[0])
        {cout<<"path not exist"<<endl;
         return false;}
        else
        {exit_gate[0]->show_dialog();
         return true;}
    }
    else if(command=="go north")
    {
        if(!exit_index[1])
        {cout<<"path not exist"<<endl;
         return false;}
        else
        {exit_gate[1]->show_dialog();
         return true;}
    }
    else if(command=="go west")
    {
        if(!exit_index[2])
        {cout<<"path not exist"<<endl;
         return false;}
        else
        {exit_gate[2]->show_dialog();
         return true;}
    }
    else if(command=="go south")
    {
        if(!exit_index[3])
        {cout<<"path not exist"<<endl;
         return false;}
        else
        {exit_gate[3]->show_dialog();
         return true;}
    }
    else
    {
        cout<<"don't know what you are saying"<<endl;
        return false;
    }
}

void room_0_E::set_route(room_0_E *room)
{
   int i;
   for(i=0;i<4;i++)
    if(exit_index[i]!=0)
      exit_gate[i]=room;
}

void room_0_E::command_menu()
{

    if(exit_index[0]==1)
    cout<<"east ";
    if(exit_index[1]==1)
    cout<<"north ";
    if(exit_index[2]==1)
    cout<<"west ";
    if(exit_index[3]==1)
    cout<<"south ";
    cout<<endl;
    cout<<"Enter your command:";
    string command;
    getline(cin,command);
    while(!exec_command(command))
     {
       cout<<"Enter your command again:";
       getline(cin,command);
     }
}

