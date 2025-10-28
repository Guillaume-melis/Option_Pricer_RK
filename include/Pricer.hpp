#ifndef OPTION_PRICER_HPP
#define OPTION_PRICER_HPP

#include "OptionsParams.hpp"

class Pricer
{
    OptionsParams params_;

    public :
    explicit Pricer(const OptionsParams params);
    double priceCall(); 
    double pricePut();
};

#endif