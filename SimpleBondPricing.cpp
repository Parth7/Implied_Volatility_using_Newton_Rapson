//
// Created by Parth Parakh on 08/01/21.
//

#include "SimpleBondPricing.h"

double BondPricing::FutureValue(double P0,long nPeriods, double r)
{
    double factor = 1.0 + r;
    return P0 * BondPricing::Power(factor,nPeriods);
}

double BondPricing::Power(double d, long n)
{
    if (n == 0) return 1.0;
    if (n == 1) return d;
    double result = d;
    for (long j = 1; j < n; j++)
    {
        result *= d;
    }
    return result;
}

double BondPricing::PresentValue(const Vector &prices, long nPeriods, double r)
{
    assert (nPeriods == prices.size());
    double factor = 1.0 + r;
    double PV = 0.0;
    for (long t = 0; t < nPeriods; t++)
    {
        PV += prices[t] / BondPricing::Power(factor, t+1);
    }
    return PV;
}
