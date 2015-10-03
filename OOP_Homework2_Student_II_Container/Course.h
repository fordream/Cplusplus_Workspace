#ifndef __COURSE_H__
#define __COURSE_H__
#include<string>
using namespace std;

class Course{
public:
  double read();
  string read(string course_name);
  int init();  /*write the mark in the object*/
private:
  string  name;  /*name of the course*/
  double mark; /*mark of the course*/
};

#endif

