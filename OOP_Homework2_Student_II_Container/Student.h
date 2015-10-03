#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<string>
#include<vector>
#include"Course.h"
using namespace std;

class Student{
public:
  int init();   /*Initialize the Student*/
  double read(int option);
  void print(); /*print the student's information*/
private:
  string name;
  vector<Course>  course_vec;
  int * index;
};

#endif
