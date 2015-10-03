#ifndef __COURSE_H__
#define __COURSE_H__

class Course{
public:
  double read(); /*read and return the mark of this course*/ 
  void write();  /*write the mark in the object*/
private:
  char name[8];  /*name of the course*/
  double mark;   /*mark of the course*/
};

#endif

