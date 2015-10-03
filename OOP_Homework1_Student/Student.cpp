#include<iostream>
#include<cstdio>
#include"Student.h"

double Student::read(int option){
  return C[option].read(); /*return the mark of selected course*/ 
}

void Student::Init() {
  int i;
  std::cin>>name;    /*write the name of the student*/
   for(i=3;i<8;i++) 
      if(name[i]<'a'||name[i]>'z') 
      {                /*change the name to a unified formate*/ 
          name[i]=' ';
          name[i+1]=0;
      }


  for(i=1;i<=3;i++)
     C[i].write();   /*write the mark of each course*/
  avg=(C[1].read()+C[2].read()+C[3].read())/3; /*calculate average*/
}

void Student::print() { /*print the student's information*/
  printf("%s", name);
  std::cout<<C[1].read()<<"       "<<C[2].read()<<"       "<<C[3].read()<<"       "<<avg<<std::endl;
}






