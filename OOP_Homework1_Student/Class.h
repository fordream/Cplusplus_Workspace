#ifndef __CLASS_H__
#define __CLASS_H__
#include"Student.h"

class Class{
public:
  void print();  /*Print the mark of all the student in the class 
                      and the max, min and average of each course*/ 
                    
  void Init();   /*Initialize the class*/ 
  void Findmin(); /*Find the minimum mark of each subject*/ 
  void Findmax(); /*Find the maximum mark of each subject*/ 
  void Avg();     /*calculate the average of each subject*/
private:
  Student S[10];  /*In a class there are 10 students*/
  double average[4]; /*the average of each subject*/
  double Min[4];  /*the minimum mark of each subject*/ 
  double Max[4];  /*the maximum mark of each subject*/
};

#endif
