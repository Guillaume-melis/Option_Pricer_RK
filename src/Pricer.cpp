#include "OptionsParams.hpp"
#include "Pricer.hpp"
#include "Grid.hpp"
#include "BlackScholesPDE.hpp"
#include "RK4Solver.hpp"
#include "BoundaryConditions.hpp"
#include <algorithm>
#include <cmath>
#include <vector>

Pricer::Pricer(const OptionsParams params) : params_(params)
{

}

double Pricer::priceCall()
{
    //Initialisation de la grille 
    Grid grid(params_.Smax,params_.M);
    const auto& S = grid.get_S();
    double dS = grid.get_dS();
    double dtau = params_.T / params_.N; 

    //condition terminale 
    std::vector<double> V(params_.M + 1);
    for(int i=0; i<= params_.M; i++)
        V[i] = std::max(S[i] - params_.K, 0.0);
    
    //Intégration en temps 
    for(int n=0; n<params_.N; n++)
    {
        double tau = (n+1) * dtau;

        auto rhs = [&](const std::vector<double>& Vcurr){
            return BlackScholesPDE::rhs(Vcurr, S, params_.r, params_.sigma, dS);
        };

        RK4Solver::integrate(V, tau, dtau, rhs, [&](std::vector<double>& Vtemp, double tau){
            BoundaryConditions::applyCall(Vtemp, params_.K, params_.r, tau, params_.Smax);
        });
    }

    //Interpolation linéaire
    int idx = static_cast<int>(params_.S0/dS);
    double w = (params_.S0 - S[idx]) / dS;
    return (1 - w) * V[idx] + w * V[idx + 1];
}

double Pricer::pricePut()
{
    //Initialisation de la grille 
    Grid grid(params_.Smax,params_.M);
    const auto& S = grid.get_S();
    double dS = grid.get_dS();
    double dtau = params_.T / params_.N; 

    //condition terminale 
    std::vector<double> V(params_.M + 1);
    for(int i=0; i<= params_.M; i++)
        V[i] = std::max(params_.K - S[i], 0.0);
    
    //Intégration en temps 
    for(int n=0; n<params_.N; n++)
    {
        double tau = (n+1) * dtau;

        auto rhs = [&](const std::vector<double>& Vcurr){
            return BlackScholesPDE::rhs(Vcurr, S, params_.r, params_.sigma, dS);
        };

        RK4Solver::integrate(V, tau, dtau, rhs, [&](std::vector<double>& Vtemp, double tau){
            BoundaryConditions::applyPut(Vtemp, params_.K, params_.r, tau, params_.Smax);
        });
    }

    //Interpolation linéaire
    int idx = std::min(static_cast<int>(params_.S0/dS), params_.M - 1);
    double w = (params_.S0 - S[idx]) / dS;
    return (1 - w) * V[idx] + w * V[idx + 1];
}

