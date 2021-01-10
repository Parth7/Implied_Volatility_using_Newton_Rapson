//
// Created by Parth Parakh on 08/01/21.
//

#include "BlackScholes.h"
#include"bs_prices.h"
#include<iostream>

template<typename T>
Black_Scholes<T>::Black_Scholes(T S_, T K_, T r_, T t_) : S(S_), K(K_), r(r_), t(t_) {}

template<typename T>
T Black_Scholes<T>::option_price(T sigma) const
{
    return call_price(S,K,r,sigma,t);
}

template<typename T>
T Black_Scholes<T>::option_vega(T sigma) const
{
    return call_vega(S,K,r,sigma,t);
}
