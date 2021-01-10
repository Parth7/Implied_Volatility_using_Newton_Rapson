//
// Created by Parth Parakh on 10/01/21.
//

#ifndef IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_POINT_H
#define IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_POINT_H

#include<iostream>
template<typename T=int, typename T2=int>
class Point
{
private:
    T m_first;
    T m_second;
public:
    Point(T m_first_, T m_second_);
    Point();
    Point(const Point<T,T2> &P1);
    virtual ~Point()=default;
    T get_first()const ;
    T2 get_second()const ;
    void First(T & first)const ;
    void Second(T &second)const ;

    double Distance(const Point<T,T2> &rhs)const ;
    Point<T,T2> &operator =(const Point<T,T2> &rhs);

    friend std::ostream & operator <<(const std::ostream &os, const Point<T,T2> &rhs);
};
#endif //IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_POINT_H
