#include <iostream>
#include "switch.h"

int processCode(int getal, int code) {

    switch(code) {
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

int getInstructieCode (std::string instructie) {
    if (instructie == "shift left 3") {
        return 0;
    } else if (instructie == "kwadraat") {
        return 1;
    } else if (instructie == "deel door 2"){
        return 2;
    } else {
        return 4;
    }
}


int processInstructie(int getal, std::string instructie){
    int code = getInstructieCode(instructie);
    switch (code) {
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

int main() { 
    int getal = 38;
    int result = processCode(getal, 0);
    std::cout << result << std::endl;
    return 0;
}