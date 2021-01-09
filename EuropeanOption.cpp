//
// Created by Parth Parakh on 08/01/21.
//

#include "EuropeanOption.h"
#include<math.h>

double EuropeanOption::putprice() const
{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    double d2 = d1 - tmp;
    return (K * exp(-r * T)* N(-d2)) - (U * exp((b-r)*T) * N(-d1));
}

double EuropeanOption::callprice() const
{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    double d2 = d1 - tmp;
    return (U * exp((b-r)*T) * N(d1)) - (K * exp(-r * T)* N(d2));
}

double EuropeanOption::calldelta() const
{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    return exp((b-r)*T) * N(d1);
}

double EuropeanOption::putdelta() const
{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    return exp((b-r)*T) * (N(d1) - 1.0);
}

void EuropeanOption::init()
{
    r = 0.08;
    sig = 0.30;
    K = 65.0;
    T = 0.25;
    U = 60.0;
    b = r;
    optType = 'C';
}

void EuropeanOption::copy(const EuropeanOption &rhs)
{
    r = rhs.r;
    sig = rhs.sig;
    K = rhs.K;
    T = rhs.T;
    U = rhs.U;
    b = rhs.b;
    optType = rhs.optType;
}

EuropeanOption::EuropeanOption()
{
    init();
}

EuropeanOption::EuropeanOption(const EuropeanOption &rhs)
{
    copy(rhs);
}

EuropeanOption::EuropeanOption(const std::string &opt)
{
    init();
    optType = opt;
}

EuropeanOption &EuropeanOption::operator=(const EuropeanOption &rhs)
{
    if(this==&rhs) return *this;
    copy(rhs);
    return *this;
}

double EuropeanOption::Price() const
{
    if((*this).optType=="C") return callprice();
    return putprice();
}

double EuropeanOption::Delta() const
{
    if((*this).optType=="C") return calldelta();
    return putdelta();
}

void EuropeanOption::toggle()
{
    if(optType=="P") optType="C";
    else optType="P";
}