#ifndef __STUDENT_H__
#define __STUDENT_H__
#include"Course.h"

class Student{
public:
  void Init();   /*Initialize the Student*/
  double read(int option); /*read and return the students mark of one course*/
  void print(); /*print the student's information*/
private:
  char name[10];
  Course C[5];
  double avg;  /*the student's average mark*/
};

#endif
