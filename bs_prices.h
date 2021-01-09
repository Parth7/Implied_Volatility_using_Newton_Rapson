//
// Created by Parth Parakh on 08/01/21.
//

#include<iostream>
#include<cmath>

using namespace std;

typedef double T;

T norm_pdf(const T x)
{
    return (1/(pow(2*M_PI,0.5)))*exp(0.5*x*x);
}


T norm_cdf(const T x)
{
    T k = 1.0/(1.0 + 0.2316419*x);
    T k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

    if (x >= 0.0)
    {
        return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * k_sum);
    }
    else
    {
        return 1.0 - norm_cdf(-x);
    }
}

T d_j(const int j, const T S, const T K, const T r, const T sigma, const T t)
{
    return ( (log(S/K)+(r+(j)*0.5*sigma*sigma)*t)/(sigma*(pow(t,0.5))) );
}


T call_price(const T S, const T K, const T r, const T sigma, const T t)
{
    return S*norm_cdf(d_j(1, S, K, r, sigma, t))- K*exp(-r*t)*norm_cdf(d_j(-1, S, K, r, sigma, t));
}


T call_vega(const T S, const T K, const T r, const T sigma, const T t)
{
    return S*sqrt(t)*norm_pdf(d_j(1, S, K, r, sigma, t));
}
