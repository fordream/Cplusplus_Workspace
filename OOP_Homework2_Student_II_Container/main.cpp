#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include"Class.h"

using namespace std;
vector <string> course_name_vec;

int main()
{
 if(freopen("1.in","r",stdin)==NULL)
    exit(0);
  Class C;
  C.print();
  return 0;
}
