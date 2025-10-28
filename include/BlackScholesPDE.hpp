#ifndef BLACK_SCHOLES_PDE_HPP
#define BLACK_SCHOLES_PDE_HPP

#include <vector>

struct BlackScholesPDE
{
    static std::vector<double> rhs(
        const std::vector<double>& V, 
        const std::vector<double>& S, 
        double r, 
        double sigma, 
        double dS
    );
};

#endif