#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<string>
#include<vector>
#include"Course.h"
using namespace std;

class Student{
public:
  int init();    /*Initialize the Student*/
  double read(int option); /*read the Student's mark of a course*/
  void print();  /*print the student's information*/
private:
  string name;
  vector<Course>  course_vec;  /*the vector that contain's every course*/
  int * index;                 /*index stores the position of the student's course
                                 in all the courses for uniform output*/ 
};

#endif
