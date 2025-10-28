#ifndef OPTION_PARAMS_HPP
#define OPTION_PARAMS_HPP 

struct OptionsParams
{
    double S0;
    double K; 
    double r; 
    double sigma; 
    double T; 
    double Smax; 
    int M; // Spatial Steps 
    int N; // Time Steps
};

#endif