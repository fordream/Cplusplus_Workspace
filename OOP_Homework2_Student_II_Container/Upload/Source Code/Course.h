#ifndef __COURSE_H__
#define __COURSE_H__
#include<string>
using namespace std;

class Course{
public:
  double read();      /*read the mark of the course*/
  string read(string course_name); /*read the name of the course*/
  int init();        /*write the name and mark in the object*/
private:
  string  name;  /*name of the course*/
  double mark;   /*mark of the course*/
};

#endif

