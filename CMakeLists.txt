cmake_minimum_required(VERSION 3.17)
project(Implied_Volatility_using_Newton_Rapson)

set(CMAKE_CXX_STANDARD 17)

add_executable(Implied_Volatility_using_Newton_Rapson main.cpp bs_prices.h BlackScholes.cpp BlackScholes.h NewtonRapson.h EuropeanOption.cpp EuropeanOption.h SimpleBondPricing.cpp SimpleBondPricing.h ComplexArray.h Point.cpp Point.h)