#include<iostream>
#include<cstdio>
#include<iomanip>
#include"Student.h"

using namespace std;
extern int COURSE_COUNT;

void Student::Delete()
{
     while(C!=NULL)
     {
         Ctmp=C->Next;
         delete C;
         C=Ctmp;
     }
}

double Student::read(int option){
    int i;
    Ctmp=C;
    for(i=0;i<option;i++)
    Ctmp=Ctmp->Next;
    return Ctmp->read();
}

string Student::read(string course_name,int option){
    int i;
    Ctmp=C;
    for(i=0;i<option;i++)
    Ctmp=Ctmp->Next;
    return Ctmp->read("coursename");
}

int Student::init() {
  int count_tmp=0;
  Course* Ctmp1;
  cin>>name; /*write the name of the student*/
    if(name=="end")
      return 0;
    else
     {
         C=new Course;
         C->Next=NULL;
         Ctmp=C;
     while(Ctmp->init())
       {
         Ctmp->Next=new Course;
         Ctmp1=Ctmp;
         Ctmp=Ctmp->Next;
         count_tmp++;
       }
      Ctmp1->Next=NULL;
      delete Ctmp;
      COURSE_COUNT=count_tmp;
     }
  return 1;
}

double Student::FindAvg()
{
    double tmp;
    Ctmp=C;
    while(Ctmp!=NULL)
    {
        tmp+=Ctmp->read();
        Ctmp=Ctmp->Next;
    }
    return tmp/COURSE_COUNT;
}

void Student::print() { /*print the student's information*/
  Ctmp=C;
  cout<<left<<setw(8)<<name;
  while(Ctmp!=NULL)
  {
        cout<<left<<setw(8)<<Ctmp->read();
        Ctmp=Ctmp->Next;
  }
  cout<<left<<setw(8)<<Student::FindAvg()<<endl;
}






