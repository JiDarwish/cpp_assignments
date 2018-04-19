#include <iostream>
#include <string>
#include <sstream>

std::string Regel(int lengte, int stap){
    std::string output = "";

    for (int i = 1; i <= lengte; i++) {
        if (i % stap) {
            output += "-";
        } else {
            output += ".";
        }
    }
    return output;
}

std::string Pagina(int min, int max, int stap, bool terug){
    std::string output = "";
    if (min < 0 || max < min) {
        return "";
    }
    int origineelMinParam = min;

    while (min < max) {
        output += Regel(min, stap) + "\n";
        min++;
        
    }
    if (!terug) {
        return output;
    }

    while( max >= origineelMinParam) {
        output += Regel(max, stap) + "\n";
        max--;
    }

    return output;
}

int main()
{
    std::cout << Pagina(3, 7, 2, true) << std::endl;
    return 0;
}