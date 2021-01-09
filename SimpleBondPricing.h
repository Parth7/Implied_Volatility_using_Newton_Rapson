//
// Created by Parth Parakh on 08/01/21.
//
#ifndef IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_SIMPLEBONDPRICING_H
#define IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_SIMPLEBONDPRICING_H

#include<vector>

using namespace std;

namespace BondPricing
{
    typedef vector<double> Vector;

    double Power(double d, long n);
    double FutureValue(double P0,long nPeriods, double r);
    double FutureValueContinuous(double P0,long nPeriods, double r);
    double OrdinaryAnnuity(double A, long nPeriods, double r);
    double PresentValue(double Pn,long nPeriods, double r);
    double PresentValue(const Vector &prices, long nPeriods, double r);

}


#endif //IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_SIMPLEBONDPRICING_H
