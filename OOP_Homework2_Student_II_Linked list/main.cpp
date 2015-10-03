#include<iostream>
#include<cstdio>
#include"Class.h"

using namespace std;
int STUDENT_COUNT=0;
int COURSE_COUNT=0;

int main()
{
 if(freopen("1.in","r",stdin)==NULL)
    exit(0);
  Class C;
  C.print();
  return 0;
}
