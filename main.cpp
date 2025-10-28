#include "Pricer.hpp"
#include "OptionsParams.hpp"
#include <iostream>

int main() {
    OptionsParams p{100.0, 100.0, 0.05, 0.2, 1.0, 300.0, 200, 5000};
    Pricer pricer(p);
    double price = pricer.priceCall();
    std::cout << "Call price (RK4 PDE): " << price << std::endl;
    return 0;
}
