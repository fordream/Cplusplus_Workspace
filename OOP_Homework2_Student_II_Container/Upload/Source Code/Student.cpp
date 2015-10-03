#include<iostream>
#include<iomanip>
#include<vector>
#include"Student.h"

using namespace std;

double Student::read(int option)
{
    if(index[option]!=-1) //if the student have the course
        return course_vec[index[option]].read(); //return the mark
    else
        return -1; //if a student don't have the course return -1
}

int Student::init() {
    cin>>name;     //write the name of the student
    Course* Ctmp;  
    if(name=="end") //check if reaches the end of input
      return 0;
    else         
     {
         Ctmp=new Course; //alloc space for a sourse
     while(Ctmp->init())  //initiate the course
         {
             course_vec.push_back(*Ctmp); //push the course into the vector
             Ctmp=new Course; //assign space for a new course
         }
     }
     delete Ctmp; //delete the temp pointer
      return 1;
}

void Student::print() {
      extern vector<string> course_name_vec;
      unsigned int size_total_course=course_name_vec.size(); //record the total number of courses
      index=new int[size_total_course]; //allocate space for array index
      unsigned int i,j;

      for(i=0;i<size_total_course;i++) //initialize the array by setting all the value -1 
         index[i]=-1;

      for(i=0;i<course_vec.size();i++)
      {
          for(j=0;j<size_total_course;j++) //find the place of each course of the stu in the total
            {                                               //course vector
                if(course_vec[i].read(" ")==course_name_vec[j])
                index[j]=i;
            }
      }                       /*finally we get the of the Xst(1st,2nd,3rd) course of the student 
                               is in the Xst column in the summary sheet*/
      cout<<left<<setw(8)<<name;  
      for(i=0;i<size_total_course;i++)  //outputing the mark of each course
      {
          if(index[i]!=-1)              //if a student have this course
          cout<<left<<setw(9)<<course_vec[index[i]].read();
          else                          //if a student don't have this course output "\"
          cout<<left<<setw(9)<<" \\";
      }
      cout<<endl;
}

