#include "Vector.h"

void funct(Vector<string> a)
{
    cout<<"size after copying: "<<a.size()<<endl;
    return;
}

int main()
{
    Vector<string> a;                    //test Vector()
    Vector<string> b(20);                //test Vector(int size)
    a[0]="Hello";                        //test operator[](int index)
    b=a;                                 //test copying one vector to another
    funct(b);
    cout<<"size of b: "<<b.size()<<endl; //test size()
    b.inflate(10);                       //test inflate(int addSize)
    cout<<"size of b after inflating: "<<b.size()<<endl;
    b[28]="Hi";
    cout<<"b[0]="<<b[0]<<" b[28]="<<b[28]<<endl;//output the result after inflating and copying
    Vector<int> c;
    Vector<double> d;
    c[1]=10;
    d[3]=3.345;
    cout<<"c[1]: "<<c[1]<<endl;
    cout<<"d[3]: "<<d[3]<<endl;

}

