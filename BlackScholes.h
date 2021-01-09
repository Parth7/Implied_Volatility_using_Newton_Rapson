//
// Created by Parth Parakh on 08/01/21.
//

#ifndef IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_BLACKSCHOLES_H
#define IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_BLACKSCHOLES_H

template<typename T>
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
};

#endif //IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_BLACKSCHOLES_H
