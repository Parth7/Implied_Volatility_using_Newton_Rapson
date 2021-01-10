//
// Created by Parth Parakh on 10/01/21.
//
#include"Point.h"
#include<cmath>

template<typename T,typename T2>
Point<T,T2>::Point(const Point<T, T2> &P1)
{
    m_first = P1.m_first;
    m_second = P1.m_second;
}

template<typename T,typename T2>
Point<T, T2>::Point()
{
    m_first=get_first();
    m_second=get_second();
}

template<typename T,typename T2>
Point<T,T2>::Point(T m_first_, T m_second_):m_first(m_first_),m_second(m_second_){}

template <typename T, typename T2>
T Point<T,T2>::get_first() const
{
    return (*this).m_first;
}

template <typename T, typename T2>
T2 Point<T,T2>::get_second() const
{
    return (*this).m_second;
}

template <typename T, typename T2>
void Point<T,T2>::First(T &first)const
{
    m_first = first;
}

template <typename T, typename T2>
void Point<T,T2>::Second(T &first)const
{
    m_second = first;
}

template <typename T, typename T2>
double Point<T, T2>::Distance(const Point<T,T2>&p) const
{
    T a=p.m_first-m_first;
    T2 b=p.m_second-m_second;
    return ::sqrt(a*a + b*b);
}

template <class TFirst, class TSecond>
Point<TFirst, TSecond>& Point<TFirst, TSecond>::operator = (const Point<TFirst, TSecond>& source)
{
    if (this == &source)
        return *this;
    m_first=source.m_first;
    m_second=source.m_second;
    return *this;
}

template <class TFirst, class TSecond>
std::ostream& operator << (std::ostream& os, const Point<TFirst, TSecond>& p)
{
    os << "(" << p.m_first << "," << p.m_second << ")\n";
    return os;
}