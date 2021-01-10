#include <iostream>
#include"BlackScholes.h"
#include"NewtonRapson.h"

using namespace std;

ostream& operator << ( ostream &os, const Black_Scholes<double> & BS )
{
    os << BS.option_price(BS.S) <<endl;
}

void generic_function( double xy, double yx, double(*func)(double a, double b))
{
    double result = (*func)(xy,yx);
    cout<<result<<endl;
}

double print(double a, double b)
{
    return a+b;
}

double print2(double a,double b)
{
    return a*b;
}

int main()
{
    double S = 100.0;
    double K = 100.0;
    double r = 0.05;
    double T = 1.0;
    double C_M = 10.5;

    generic_function(1.2,2.3,print);
    generic_function(2.3,6.5,print2);
    Black_Scholes<double> bsc(S, K, r, T);

    double init = 0.3; // initial guess for sigma
    double epsilon = 0.001;

    auto sigma = newton_rapson<double,Black_Scholes<double>,&Black_Scholes<double>::option_price,&Black_Scholes<double>::option_vega>
            (C_M, init, epsilon, bsc);

    std::cout << "Implied Vol: " << sigma << std::endl;

    return 0;
}
