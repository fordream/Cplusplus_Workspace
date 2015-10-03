#ifndef __CLASS_H__
#define __CLASS_H__
#include"Student.h"

class Class{
public:
  Class();       /*Initialize the class*/
  void print();  /*Print the mark of all the student in the class
                       and the max, min and average of each course*/
  int Findmin(int option); /*Find the minimum mark of each subject*/
  int Findmax(int option); /*Find the maximum mark of each subject*/
  double FindAvg(int option);     /*calculate the average of each subject*/
private:
  vector<Student>  stu_vec;  /*vector that contains the every student*/
};

#endif
