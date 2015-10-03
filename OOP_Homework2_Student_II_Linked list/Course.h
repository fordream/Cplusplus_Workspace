#ifndef __COURSE_H__
#define __COURSE_H__
#include<string>
using namespace std;

class Course{
public:
  double read(); /*read and return the mark of this course*/
  string read(string tmp);
  int init();  /*write the mark in the object*/
  Course *Next;
private:
  string  name;  /*name of the course*/
  double mark; /*mark of the course*/
};

#endif

