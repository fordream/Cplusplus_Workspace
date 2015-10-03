#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"Class.h"

using namespace std;

int main()
{
 if(freopen("1.in","r",stdin)==NULL)
    exit(0);
  Class C;
  C.Init(); /*initialize the class first*/
  C.Avg();   /*calculate the min max and average*/
  C.Findmax();
  C.Findmin();
  C.print(); /*print the class*/

  return 0;
}
