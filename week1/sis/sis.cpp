#include <iostream>

bool heeftToegang(float lab1, float lab2, float lab3, float toets1, 
float toets2){

    float grens = 6.0;
    float som = 0;
    float const GEWICHT = 1 + 1 +1 + 3 + 3;

    float alleLabs[] = { lab1, lab2, lab3 };
    float alleToetsen[] = { toets1, toets2 };

    // size of array in bytes / size of one cell = num of cells
    for (unsigned int i = 0; i < sizeof(alleLabs)/sizeof(alleLabs[0]); i++) {
        if (alleLabs[i] > 10.0 || alleLabs[i] == 0.0) {
            return false;
        }
        som += alleLabs[i];
        if (alleLabs[i] > 8.0) {
            grens -= 0.5;
            som += 1;
        }
    }

    for (unsigned int i = 0; i < sizeof(alleToetsen)/sizeof(alleToetsen[0]); i++) {
        if (alleToetsen[i] > 10.0 || alleToetsen[i] == 0.0 || alleToetsen[i] < 4.0) {
            return false;
        }
        som += alleToetsen[i] * 3;
    }
    float avg = som / GEWICHT;

    if (avg < grens) return false;

    return true;
}

int main() {
    float lab1 = 6.0;
    float lab2 = 6.0;
    float lab3 = 6.0;
    float toets1 = 4.0;
    float toets2 = 6.0;

    bool isGeslaagd = heeftToegang(lab1, lab2, lab3, toets1, toets2);

    std::string melding = isGeslaagd ? "=> Deelname oke" : "Geen deelname";

    std::cout << "Lab:" << lab1 << ";" << lab2 << ";" << lab3 << "Toets:" << toets1
              << ";" << toets2 << "  " << melding << std::endl;

    return 0;
}