#include <vector> 
#include "BoundaryConditions.hpp"

void BoundaryConditions::applyCall(std::vector<double>& V, double K, double r, double tau, double Smax)
{
    V.front() = 0.0;

    V.back() = Smax - K*std::exp(-r*tau);
}

void BoundaryConditions::applyPut(std::vector<double>& V, double K, double r, double tau, double Smax)
{
    V.front() = K*std::exp(-r*tau);

    V.back() = 0.0;
}