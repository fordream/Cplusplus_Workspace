#include<iostream>
#include<iomanip>
#include<vector>
#include"Student.h"

using namespace std;

double Student::read(int option)
{
    if(index[option]!=-1)
        return course_vec[index[option]].read();
    else
        return -1;
}

int Student::init() {
    cin>>name; /*write the name of the student*/
    Course* Ctmp;
    if(name=="end")
      return 0;
    else
     {
         Ctmp=new Course;
     while(Ctmp->init())
         {
             course_vec.push_back(*Ctmp);
             Ctmp=new Course;
         }
     }
     delete Ctmp;
      return 1;
}

void Student::print() {
      extern vector<string> course_name_vec;
      unsigned int size_total_course=course_name_vec.size();
      index=new int[size_total_course];
      unsigned int i,j;

      for(i=0;i<size_total_course;i++)
         index[i]=-1;

      for(i=0;i<course_vec.size();i++)
      {
          for(j=0;j<size_total_course;j++)
            {
                if(course_vec[i].read(" ")==course_name_vec[j])
                index[j]=i;
            }
      }
      cout<<left<<setw(8)<<name;
      for(i=0;i<size_total_course;i++)
      {
          if(index[i]!=-1)
          cout<<left<<setw(9)<<course_vec[index[i]].read();
          else
          cout<<left<<setw(9)<<" \\";
      }
      cout<<endl;
}

