#ifndef RK4_SOLVER_HPP
#define RK4_SOLVER_HPP

#include <vector>
#include <functional>

struct RK4Solver
{
    static void integrate(
        std::vector<double>& V, 
        double tau, 
        double dtau, 
        const std::function<std::vector<double>(const std::vector<double>&)>& rhs, 
        const std::function<void(std::vector<double>&, double)>& applyBC
    );
}; 

#endif