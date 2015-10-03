#include<iostream>
#include<iomanip>
#include<cstdio>
#include"Class.h"
using namespace std;
extern int STUDENT_COUNT;
extern int COURSE_COUNT;

Class::Class()
{
    Student* Stmp1;
    S=new Student;
    S->Next=NULL;
    Stmp=S;
    while(Stmp->init())
    {
      Stmp->Next=new Student;
      Stmp1=Stmp;
      Stmp=Stmp->Next;
      STUDENT_COUNT++;
    }
    Stmp1->Next=NULL;
    delete Stmp;
}

Class::~Class()
{
     while(S!=NULL)
     {
         Stmp=S->Next;
         S->Delete();
         delete S;
         S=Stmp;
     }
}

void Class::print()
{   /*print the class according to the format*/
    int i;
    Stmp=S;
    cout<<left<<setw(8)<<"no  name    ";
    for(i=0;i<=COURSE_COUNT-1;i++)
        cout<<left<<setw(8)<<Stmp->read("Course_name",i);
    cout<<left<<setw(8)<<"average"<<endl;
    Stmp=S;
    i=0;
    while(Stmp!=NULL)
    {
        cout<<left<<setw(4)<<++i;
        Stmp->print();
        Stmp=Stmp->Next;
    }
    cout<<"    "<<left<<setw(8)<<"average";
    for(i=0;i<COURSE_COUNT;i++)
        cout<<left<<setw(8)<<Class::FindAvg(i);
    cout<<endl;

    cout<<"    "<<left<<setw(8)<<"min";
    for(i=0;i<COURSE_COUNT;i++)
        cout<<left<<setw(8)<<Class::Findmin(i);
    cout<<endl;

    cout<<"    "<<left<<setw(8)<<"max";
    for(i=0;i<COURSE_COUNT;i++)
        cout<<left<<setw(8)<<Class::Findmax(i);
    cout<<endl;
}

int Class::Findmax(int option)
{
      int tmp_max;
      Stmp=S;
      tmp_max=Stmp->read(option);
      while(Stmp!=NULL)
         {
            if(Stmp->read(option)>tmp_max)
                 tmp_max=Stmp->read(option);
            Stmp=Stmp->Next;
         }
       return tmp_max;
}

int Class::Findmin(int option)
{
      int tmp_min;
      Stmp=S;
      tmp_min=Stmp->read(option);
      while(Stmp!=NULL)
         {
            if(Stmp->read(option)<tmp_min)
                 tmp_min=Stmp->read(option);
            Stmp=Stmp->Next;
         }
       return tmp_min;
}

double Class::FindAvg(int option)
{
    Stmp=S;
    double tmp=0;
    while(Stmp!=NULL)
    {
        tmp+=Stmp->read(option);
        Stmp=Stmp->Next;
    }
    return tmp/STUDENT_COUNT;
}













