#include<iostream>
#include<vector>
#include<string>
#include"Course.h"

using namespace std;

double Course::read() {return mark;} //return the mark 
string Course::read(string course_name){ return name;}  //overloading, return the course name

int Course::init(){  /*read from the input and write it to mark*/
    extern vector<string> course_name_vec;
    cin>>name;
    if(name==";" )   /*check if it gets to the end*/
        return 0;
    else
        cin>>mark;
    vector<string>::iterator p;    //if the course was in the course_name_vec, do nothing
    for(p=course_name_vec.begin();p<course_name_vec.end();p++)
        if(name==*p)
        return 1;
    course_name_vec.push_back(name); //else put the course name in the container
    return 1;
}

