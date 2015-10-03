#include<iostream>
#include"Course.h"

double Course::read(){ /*return rhe mark*/ 
  return mark;
}

void Course::write(){ /*read from the input and write it to mark*/
  std::cin>>mark;
}

