#include<iostream>
#include<iomanip>
#include<cstdio>
#include"Class.h"
using namespace std;

Class::Class() //constructer that initialize the Class
{
    Student* Stmp;
    Stmp=new Student;
    while(Stmp->init()) //if doesn't reach the end of input
    {
      stu_vec.push_back(*Stmp);// put it in the stuent vector
      Stmp=new Student;
    }
    delete Stmp; //delete the temp pointer 
}

void Class::print()
{     extern vector<string> course_name_vec;
      unsigned int i=1;
      cout<<"no  name    ";
      vector<string>::iterator p;
      for(p=course_name_vec.begin();p!=course_name_vec.end();p++)
      cout<<left<<setw(8)<<*p<<" ";   //output name of all the course in the 1st row

      cout<<endl;
      vector<Student>::iterator q;   
      for(q=stu_vec.begin();q!=stu_vec.end();q++,i++)
       {     cout<<left<<setw(4)<<i;    // the index of each student
             q->print();                //output each student's mark
       }
       cout<<"    "<<left<<setw(8)<<"min";
       for(i=0;i<course_name_vec.size();i++)
         cout<<left<<setw(9)<<Findmin(i);  //output the min of each course
       cout<<endl;
       cout<<"    "<<left<<setw(8)<<"max";
       for(i=0;i<course_name_vec.size();i++)
         cout<<left<<setw(9)<<Findmax(i);  //output the max of each course
        cout<<endl;
        cout<<"    "<<left<<setw(8)<<"average";
       for(i=0;i<course_name_vec.size();i++)
         cout<<left<<setw(9)<<FindAvg(i);  //output the avg of each course
        cout<<endl;
}

int Class::Findmin(int option)
{
    double tmp;
    int mark;
    vector<Student>::iterator p;
    for(p=stu_vec.begin();p!=stu_vec.end();p++)//find the first student
        if(p->read(option)!=-1)   //that has mark on this course as tmp
        {
        tmp=p->read(option);
        break;
         }
    for(p=stu_vec.begin();p!=stu_vec.end();p++)
    {
        mark=p->read(option);    //searching through every stu to find the min
        if(mark==-1);            //omitting those who doesnt have this course
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
        if(p->read(option)>tmp)   //searching through every stu to find the max
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
            if(mark==-1)   //omitting those who doesnt take the course
                 tmp+=0;
            else
            {
                 tmp+=mark; //if the student have taken the course add it to total
                 counter++; //count how many stu have taken the course
            }
     }
    return tmp/counter;
}
