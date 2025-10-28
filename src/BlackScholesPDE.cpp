#include <vector>
#include "BlackScholesPDE.hpp"

std::vector<double> BlackScholesPDE::rhs(const std::vector<double>& V, const std::vector<double>& S, double r, double sigma, double dS)
{
    int M = static_cast<int>(S.size());
    std::vector<double> dV(M,0.0);

    for(int i=0; i<M-1;i++)
    {
        double dVdS = (V[i+1] - V[i - 1])/(2.0 * dS);
        double d2Vd2S = (V[i + 1] - 2.0 * V[i] + V[i - 1]) / (dS * dS);

        double diff = 0.5 * sigma * sigma * S[i] * S[i] * d2Vd2S;
        double drift = r * S[i] * dVdS;
        double discount = -r * V[i];

        dV[i] = diff + drift + discount;
    }
    dV[0] = 0.0;
    dV[M-1] = 0.0;

    return dV;
}