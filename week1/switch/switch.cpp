#include "switch.h"
#include <iostream>
#include <unordered_map>

int processCode(int getal, int code)
{

    switch (code) {
    case 0:
        //shift left 2
        getal = getal << 2;
        break;
    case 1:
        //shift right 2
        getal = getal >> 2;
        break;
    case 3:
        getal *= 2;
        break;
    default:
        getal = 0;
    }

    return getal;
}

int processInstructie(int getal, std::string instructie)
{
    std::unordered_map<std::string, int> instrucRegister; // map with key value pairs of the instruction and itś corresponding key
    instrucRegister.insert(std::make_pair("shift left 3", 0));
    instrucRegister.insert(std::make_pair("kwadraat", 1));
    instrucRegister.insert(std::make_pair("deel door 2", 2));

    switch (instrucRegister[instructie]) {
    case 0:
        getal = getal << 3;
        break;
    case 1:
        getal *= getal;
        break;
    case 2:
        getal /= 2;
        break;
    default:
        getal = 0;
    }
    return getal;
}

int main()
{
    int getal = 38;
    int result = processInstructie(3, "kwadraat");
    std::cout << result << std::endl;
    return 0;
}