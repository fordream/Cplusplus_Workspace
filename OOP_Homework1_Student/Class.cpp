#include<iostream>
#include<cstdio>
#include"Class.h"

void Class::Init(){

  int i;
  for(i=0;i<10;i++)   /*initialize every student in the class*/ 
     S[i].Init();

}
void Class::Findmin(){
 int temp;           
 int i;
 int j;

 for(j=1;j<4;j++)
 { 
   temp=S[0].read(j);  /*Find the minimum mark of each course*/
   for(i=1;i<10;i++)
    if(S[i].read(j)<temp) 
       temp=S[i].read(j);
   Min[j]=temp;       /*store it*/
 }
}

void Class::Findmax(){

   int i;
   int j;
   int temp;

    for(j=1;j<=3;j++)  
    {
     temp=S[0].read(j);  /*Find the minimum mark of each course*/
     for(i=0;i<10;i++)
      if(S[i].read(j)>temp)
        temp=S[i].read(j);
     Max[j]=temp;        /*store it*/
    }
}

void Class::Avg(){
    int i;
    int j;
    double temp;

    for(j=1;j<=3;j++)     /*Find the minimum mark of each course*/
    {
     temp=0;
     for(i=0;i<10;i++)
      temp+=S[i].read(j);
     average[j]=temp/10;   /*store it*/
    }
}

void Class::print() {   /*print the class according to the format*/
    int i;
    std::cout<<"no      name    score1  score2  score3  average"<<std::endl;
    for(i=0;i<10;i++)
    {
        printf("%d       ",i);
        S[i].print();
    }
    std::cout<<"        average "<<average[1]<<"     "<<average[2]<<"     "<<average[3]<<std::endl;
    std::cout<<"        min     "<<Min[1]<<"       "<<Min[2]<<"       "<<Min[3]<<std::endl;
    std::cout<<"        max     "<<Max[1]<<"       "<<Max[2]<<"       "<<Max[3]<<std::endl;
}
