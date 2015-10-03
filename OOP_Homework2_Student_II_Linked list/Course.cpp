#include<iostream>
#include"Course.h"
using namespace std;

double Course::read(){ /*return rhe mark*/
  return mark;
}

string Course::read(string tmp){
   return name;
}

int Course::init(){ /*read from the input and write it to mark*/
    cin>>name;
    if(name==";" )
        return 0;
    else
    cin>>mark;
    return 1;
}

