#include<iostream>
#include<iomanip>
#include<cstdio>
#include"Class.h"
using namespace std;

Class::Class()
{
    Student* Stmp;
    Stmp=new Student;
    while(Stmp->init())
    {
      stu_vec.push_back(*Stmp);
      Stmp=new Student;
    }
    delete Stmp;
}

void Class::print()
{     extern vector<string> course_name_vec;
      unsigned int i=1;
      cout<<"no  name    ";
      vector<string>::iterator p;
      for(p=course_name_vec.begin();p!=course_name_vec.end();p++)
      cout<<left<<setw(8)<<*p<<" ";

      cout<<endl;
      vector<Student>::iterator q;
      for(q=stu_vec.begin();q!=stu_vec.end();q++,i++)
       {     cout<<left<<setw(4)<<i;
             q->print();
       }
       cout<<"    "<<left<<setw(8)<<"min";
       for(i=0;i<course_name_vec.size();i++)
         cout<<left<<setw(9)<<Findmin(i);
       cout<<endl;
       cout<<"    "<<left<<setw(8)<<"max";
       for(i=0;i<course_name_vec.size();i++)
         cout<<left<<setw(9)<<Findmax(i);
        cout<<endl;
        cout<<"    "<<left<<setw(8)<<"average";
       for(i=0;i<course_name_vec.size();i++)
         cout<<left<<setw(9)<<FindAvg(i);
        cout<<endl;
}

int Class::Findmin(int option)
{
    double tmp;
    int mark;
    vector<Student>::iterator p;
    for(p=stu_vec.begin();p!=stu_vec.end();p++)
        if(p->read(option)!=-1)
        {
        tmp=p->read(option);
        break;
         }
    for(p=stu_vec.begin();p!=stu_vec.end();p++)
    {
        mark=p->read(option);
        if(mark==-1);
        else if (mark<tmp)
            tmp=mark;
    }
    return tmp;
}

int Class::Findmax(int option)
{
    double tmp=stu_vec[0].read(option);
    vector<Student>::iterator p;
    for(p=stu_vec.begin();p!=stu_vec.end();p++)
        if(p->read(option)>tmp)
            tmp=p->read(option);
    return tmp;
}

double Class::FindAvg(int option)
{
    double tmp=0;
    int counter=0;
    int mark;
    vector<Student>::iterator p;
    for(p=stu_vec.begin();p!=stu_vec.end();p++)
     {
            mark=p->read(option);
            if(mark==-1)
                 tmp+=0;
            else
            {
                 tmp+=mark;
                 counter++;
            }
     }
    return tmp/counter;
}
