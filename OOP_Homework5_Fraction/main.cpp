#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
    fraction c;  //test default constructor
    fraction a(4,6); //test ctor with two arguments
    fraction b(3,4);
    fraction d=a;  //test copy constructor
    d=a+b;         //test +
    cout<<d;       //test extractor for streams
    d=b-a;         //test -
    cout<<d;
    d=a*b;         //test *
    cout<<d;
    d=a/b;         //test /
    cout<<d;
    //cin>>c;        //test inserter for streams
    cout<<(a>b);   //test >
    cout<<(a<b);   //test <
    cout<<(a>=c);  //test >=
    cout<<(a<=d);  //test <=
    cout<<(a==c);  //test ==
    double e=1+b;  //test type cast to double;
    cout<<e;
    cout<<a.toString(); //test function to string
    cin>>a;
    cout<<a;
    return 0;
}

