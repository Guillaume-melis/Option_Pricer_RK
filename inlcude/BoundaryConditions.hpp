#ifndef BOUNDARY_CONDITIONS_HPP
#define BOUNDARY_CONDITIONS_HPP

#include <vector>

struct BoundaryConditions
{
    static void applyCall(std::vector<double>& V, double K, double r, double tau, double Smax);
    static void applyPut(std::vector<double>& V, double K, double r, double tau, double Smax);
};

#endif