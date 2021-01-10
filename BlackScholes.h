//
// Created by Parth Parakh on 08/01/21.
//

#ifndef IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_BLACKSCHOLES_H
#define IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_BLACKSCHOLES_H

#include<iostream>

template<typename T=double>
class Black_Scholes
{
private:
    T S;
    T K;
    T r;
    T t;
public:
    Black_Scholes(T S_, T K_, T r_, T t_);
    T option_price(T sigma) const;
    T option_vega(T sigma) const;
    friend std::ostream &operator << (std::ostream &os, const Black_Scholes &BC);
};

#endif //IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_BLACKSCHOLES_H
