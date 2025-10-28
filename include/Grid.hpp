#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

class Grid
{
    double Smax_;
    int M_;
    double dS_;
    std::vector<double> S_;

    public :
    Grid(double Smax, int M);
    double get_Smax() {return Smax_;}
    double get_M() {return M_;}
    double get_dS() {return dS_;}
    std::vector<double> get_S() {return S_;}
};

#endif