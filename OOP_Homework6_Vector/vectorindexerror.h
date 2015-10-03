#ifndef VECTORINDEXERROR_H
#define VECTORINDEXERROR_H
#include <iostream>
using namespace std;

class VectorIndexError
{
public:
    VectorIndexError(int v):m_badValue(v){}
    ~VectorIndexError(){}
    void diagnostic()
    {
        cerr<<"index "<<m_badValue<<"Out of range";
    }
private:
    int m_badValue;
};

#endif // VECTORINDEXERROR_H
