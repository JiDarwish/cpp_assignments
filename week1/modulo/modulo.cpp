#include <iostream>
#include "modulo.h"

unsigned int getFactor(unsigned int basis, unsigned int getal) {
    return getal / basis;
}

unsigned int getRest( unsigned int basis, unsigned int getal) {
    return getal % basis;
}

std::string Representeer(unsigned int basis, unsigned int getal) {
    std::string representation = "";
    while (getal != 0) {
        int rest = getal % basis;
        representation = std::to_string(rest) + representation;
        getal /= basis;
    }

    return representation;
}

int main() {
    std::string str = Representeer(3, 19);
    std::cout << str << std::endl;
    return 0;
}