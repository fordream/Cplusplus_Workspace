#include<iostream>
#include<vector>
#include<string>
#include"Course.h"

using namespace std;

double Course::read() {return mark;}

string Course::read(string course_name){ return name;}

int Course::init(){ /*read from the input and write it to mark*/
    extern vector<string> course_name_vec;
    cin>>name;
    if(name==";" )
        return 0;
    else
        cin>>mark;
    vector<string>::iterator p;
    for(p=course_name_vec.begin();p<course_name_vec.end();p++)
        if(name==*p)
        return 1;
    course_name_vec.push_back(name);
    return 1;
}

