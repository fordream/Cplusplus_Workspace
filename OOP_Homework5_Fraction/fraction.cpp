#include "fraction.h"

fraction::fraction(const int a,const int b)
{
    if(b==0)
      exit(0);
    int  GCD=GreatestCommonDivisor(a,b);
    if(GCD==1)
    {
        numerator=a;
        denominator=b;
    }
    else
    {
        numerator=a/GCD;
        denominator=b/GCD;
    }
}

fraction::fraction(const fraction &f)
{
   numerator=f.numerator;
   denominator=f.denominator;
}

fraction::~fraction()
{
}

fraction fraction::operator +(const fraction& a) const
{
  int tmpNumerator;
  int tmpDenominator;
  int GCD;
  int cnt1,cnt2;
  tmpDenominator=LeastCommonMultiple(denominator,a.denominator);
  cnt1=tmpDenominator/denominator;
  cnt2=tmpDenominator/a.denominator;
  tmpNumerator=cnt1*numerator+cnt2*a.numerator;
  GCD=GreatestCommonDivisor(tmpNumerator,tmpDenominator);
  if(GCD==1)
  return fraction(tmpNumerator,tmpDenominator);
  else
  return fraction(tmpNumerator/GCD,tmpDenominator/GCD);
}

fraction fraction::operator -(const fraction& a) const
{
    int tmpNumerator;
    int tmpDenominator;
    int GCD;
    int cnt1,cnt2;
    tmpDenominator=LeastCommonMultiple(denominator,a.denominator);
    cnt1=tmpDenominator/denominator;
    cnt2=tmpDenominator/a.denominator;
    tmpNumerator=cnt1*numerator-cnt2*a.numerator;
    GCD=GreatestCommonDivisor(tmpNumerator,tmpDenominator);
    if(GCD==1)
    return fraction(tmpNumerator,tmpDenominator);
    else
    return fraction(tmpNumerator/GCD,tmpDenominator/GCD);
}

fraction fraction::operator *(const fraction& a) const
{
   int tmpNumerator=numerator*a.numerator;
   int tmpDenominator=denominator*a.denominator;
   int GCD;
   GCD=GreatestCommonDivisor(tmpNumerator,tmpDenominator);
   if(GCD==1)
   return fraction(tmpNumerator,tmpDenominator);
   else
   return fraction(tmpNumerator/GCD,tmpDenominator/GCD);
}

fraction fraction::operator /(const fraction& a) const
{
    int tmpNumerator=numerator*a.denominator;
    int tmpDenominator=denominator*a.numerator;
    int GCD;
    GCD=GreatestCommonDivisor(tmpNumerator,tmpDenominator);
    if(GCD==1)
    return fraction(tmpNumerator,tmpDenominator);
    else
        return fraction(tmpNumerator/GCD,tmpDenominator/GCD);
}

bool fraction::operator >(const fraction &a) const
{
    int tmpDenominator;
    int cnt1,cnt2;
    tmpDenominator=LeastCommonMultiple(denominator,a.denominator);
    cnt1=tmpDenominator/denominator;
    cnt2=tmpDenominator/a.denominator;
    if(cnt1*numerator>cnt2*a.numerator)
        return true;
    else
        return false;
}

bool fraction::operator <(const fraction &a) const
{
    int tmpDenominator;
    int cnt1,cnt2;
    tmpDenominator=LeastCommonMultiple(denominator,a.denominator);
    cnt1=tmpDenominator/denominator;
    cnt2=tmpDenominator/a.denominator;
    if(cnt1*numerator<cnt2*a.numerator)
        return true;
    else
        return false;
}

bool fraction::operator >=(const fraction &a) const
{
    int tmpDenominator;
    int cnt1,cnt2;
    tmpDenominator=LeastCommonMultiple(denominator,a.denominator);
    cnt1=tmpDenominator/denominator;
    cnt2=tmpDenominator/a.denominator;
    if(cnt1*numerator>=cnt2*a.numerator)
        return true;
    else
        return false;
}

bool fraction::operator <=(const fraction &a) const
{
    int tmpDenominator;
    int cnt1,cnt2;
    tmpDenominator=LeastCommonMultiple(denominator,a.denominator);
    cnt1=tmpDenominator/denominator;
    cnt2=tmpDenominator/a.denominator;
    if(cnt1*numerator<=cnt2*a.numerator)
        return true;
    else
        return false;
}

bool fraction::operator ==(const fraction &a) const
{
    int tmpDenominator;
    int cnt1,cnt2;
    tmpDenominator=LeastCommonMultiple(denominator,a.denominator);
    cnt1=tmpDenominator/denominator;
    cnt2=tmpDenominator/a.denominator;
    if(cnt1*numerator==cnt2*a.numerator)
        return true;
    else
        return false;
}

istream &operator>>(istream &is, fraction &a)
{
   string str;
   string tmp1;
   string tmp2;
   int i=0;
   is>>str;
   while(str[i]!='/')
   {
       tmp1+=str[i];
       i++;
   }
   i++;
   int j=0;
   while(str[i])
   {
       tmp2+=str[i];
       i++;
       j++;
   }
   int x=0;
   int y=0;
   stringstream ss;
   ss<<tmp1;
   ss>>x;
   stringstream ss1;
   ss1<<tmp2;
   ss1>>y;
   fraction b(x,y);
   a=b;
   return is;
}

ostream& operator<<(ostream& os,const fraction &a)
{
    os<<a.numerator<<"/"<<a.denominator<<endl;
    return os;
}

string fraction::toString()
{
    stringstream ss;
    string str;
    ss<<numerator<<"/"<<denominator;
    ss>>str;
    return str;
}

int GreatestCommonDivisor(int x, int y)
{
   if(y == 0) return x;
   if(x < y)   return GreatestCommonDivisor(y,x);
   else        return GreatestCommonDivisor(y, x%y);
}

int LeastCommonMultiple(int a, int b)
{
    int i=1;
    int j=1;
    while(a*i!=b*j)
    {
        if(a*i<b*j)
            i++;
        else
            j++;
    }
    return a*i;
}
