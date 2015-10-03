#ifndef __VECTOR_H__
#define __VECTOR_H__
#include<iostream>
#include<string>
using namespace std; 

template <class T>
class Vector {
	public:
        Vector();
        Vector(int size);
		virtual ~Vector();
        Vector(const Vector& v);
		T& operator[](int);
		int size();
		int inflate(int addSize);
	private:
		T* m_elements;
		int m_size;
};

template <class T>
Vector<T>::Vector()
{
    m_elements= new T[20];
    m_size=20;
}

template <class T>
Vector<T>::Vector(int size):m_size(size)
{
	m_elements= new T[m_size];
} 

template <class T>
Vector<T>::~Vector()
{
	delete m_elements;
}

template <class T>
Vector<T>::Vector(const Vector& v)
{
   int i;
   m_elements=new T[v.m_size];
   m_size=v.m_size;
   for(i=0;i<m_size;i++)
      m_elements[i]=v.m_elements[i];
}
 
template <class T>
T& Vector<T>::operator[](int index)
{
    if(index<m_size&&index>=0)
	{
		return m_elements[index];
	}
	else 
     throw("IndexOutofBounds");
}

template <class T>
int Vector<T>::size()
{
    return m_size;
}

template <class T>
int Vector<T>::inflate(int addSize)
{
   T* tmp;
   tmp=m_elements;
   m_elements=new T[m_size+addSize];
   for(int i=0;i<m_size;i++)
      m_elements[i]=tmp[i];
   delete tmp;
   m_size+=addSize;
   return m_size;
}

#endif
