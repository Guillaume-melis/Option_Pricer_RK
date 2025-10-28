#include <functional>
#include <vector>
#include "RK4Solver.hpp"

void RK4Solver::integrate(std::vector<double>& V,
    double tau, 
    double dtau, 
    const std::function<std::vector<double>(const std::vector<double>&)>& rhs,
    const std::function<void(std::vector<double>&, double)>& applyBC
    )
{
    int M = static_cast<int>(V.size());
    std::vector<double> k1(M), k2(M), k3(M), k4(M), Vtemp(M);

    k1 = rhs(V);

    for(int i=0; i < M; i++)
    {
        Vtemp[i] = V[i] + 0.5 * dtau * k1[i];
    }
    applyBC(Vtemp, tau + 0.5 * dtau);
    k2 = rhs(Vtemp);

    for(int i=0; i < M; i++)
        Vtemp[i] = V[i] + 0.5 * dtau * k2[i];
    applyBC(Vtemp, tau + 0.5 * dtau);
    k3 = rhs(Vtemp);

    for(int i=0; i<M; i++)
        Vtemp[i] = V[i] + dtau * k3[i];
    applyBC(Vtemp, tau + dtau);
    k4 = rhs(Vtemp);

    for(int i=0; i<M; i++)
        V[i] += dtau / 6.0 * (k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
    applyBC(V, tau+dtau);
}