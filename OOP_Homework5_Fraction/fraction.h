#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class fraction
{
public:
    fraction(const int a=1,const int b=1);
    ~fraction();
    fraction(const fraction& f);
    fraction operator +(const fraction& a)const;
    fraction operator -(const fraction& a)const;
    fraction operator *(const fraction& a)const;
    fraction operator /(const fraction& a)const;
    bool operator >(const fraction& a) const;
    bool operator <(const fraction& a) const;
    bool operator >=(const fraction& a) const;
    bool operator <=(const fraction& a) const;
    bool operator ==(const fraction& a) const;
    operator double() const{
        return numerator/(double)denominator;
    }
    friend istream& operator>>(istream& is,fraction& a);
    friend ostream& operator<<(ostream& os,const fraction& a);
    string toString();
private:
    int numerator;
    int denominator;
};

int GreatestCommonDivisor(int x,int y);
int LeastCommonMultiple(int a, int b);

#endif // FRACTION_H
