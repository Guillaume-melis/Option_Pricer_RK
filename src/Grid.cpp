#include <vector> 
#include "Grid.hpp"

Grid::Grid(double Smax, int M) : Smax_(Smax), M_(M)
{
    dS_ = Smax_ / static_cast<double> (M_);
    S_.resize(M_+1);

    for(int i=0; i< M_; i++)
    {
        S_[i] = i * dS_;
    }
}