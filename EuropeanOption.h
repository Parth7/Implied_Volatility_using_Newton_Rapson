//
// Created by Parth Parakh on 08/01/21.
//

#ifndef IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_EUROPEANOPTION_H
#define IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_EUROPEANOPTION_H

#include<string>

class EuropeanOption
{
private:
    void init();
    void copy(const EuropeanOption &rhs);
    double callprice() const;
    double putprice() const;
    double calldelta() const;
    double putdelta() const;
    double r;
    double K;
    double sig;
    double T;
    double U;
    double b;

    std:: string optType;;
public:
    EuropeanOption();
    virtual ~EuropeanOption() = default;
    EuropeanOption(const EuropeanOption& rhs);
    EuropeanOption( const std::string &opt);

    EuropeanOption &operator=(const EuropeanOption &rhs);
    double Price() const;
    double Delta() const;

    void toggle();
};
#endif //IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_EUROPEANOPTION_H
