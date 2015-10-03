#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<string>
#include"Course.h"
using namespace std;

class Student{
public:
  int init();   /*Initialize the Student*/
  double read(int option); /*read and return the students mark of one course*/
  string read(string course_name,int option);
  double FindAvg();
  void print(); /*print the student's information*/
  void Delete();
  Student * Next;
private:
  string name;
  Course *C;
  Course* Ctmp;
  double avg;
};

#endif
