#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include"Class.h"

using namespace std;
vector <string> course_name_vec; /*global variable, store the 
                                   name of different courses*/

int main()
{
 //if(freopen("1.in","r",stdin)==NULL)
   // exit(0);
  Class C;       /*declaration of Class C*/ 
  C.print();     /*print the summary sheet*/
  return 0;
}
