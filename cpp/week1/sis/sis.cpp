#include <iostream>

bool heeftToegang(float lab1, float lab2, float lab3, float toets1,
                  float toets2)
{
  // constants
  float const MAX_CIJFER = 10.0;
  float const MIN_CIJFER = 4.0;
  float const GRENS_BONUS = 8.0;
  float const GRENS_VERLAGING = 0.5;
  float const CIJFER_OPHOGIN = 1;
  int const LAB_GEWICHT = 1;
  int const TOETS_GEWICHT = 3;
  // end constants

  float grens = 6.0;

  float alleLabs[] = {lab1, lab2, lab3};
  float alleToetsen[] = {toets1, toets2};

  // check toetsen voor fraude of onvoldoende
  for (unsigned int i = 0; i < sizeof(alleToetsen) / sizeof(alleToetsen[0]); i++)
  {
    if (alleToetsen[i] > MAX_CIJFER || alleToetsen[i] == 0 || alleToetsen[i] < MIN_CIJFER)
    {
      return false;
    }
  }

  // Check cijfers van labs voor fraude of boven 8.0
  for (unsigned int i = 0; i < sizeof(alleLabs) / sizeof(alleLabs[0]); i++)
  {
    if (alleLabs[i] > MAX_CIJFER || alleLabs[i] == 0)
    {
      return false;
    }
    else if (alleLabs[i] > GRENS_BONUS)
    {
      grens -= GRENS_VERLAGING;      // verlaag de grens
      alleLabs[i] += CIJFER_OPHOGIN; // verhoog dat cijfer -> de gemiddelde van dat onderdeel
    }
  }

  float somOnderdeel1 = alleLabs[0] + alleLabs[1] + alleToetsen[0] * TOETS_GEWICHT; // lab1 + lab2 + toets1 * 3
  const int GEWICHT_ONDERDEEL1 = LAB_GEWICHT + LAB_GEWICHT + TOETS_GEWICHT;         // lab1 + lab2 + toets1
  float somOnderdeel2 = alleLabs[2] + alleToetsen[1] * TOETS_GEWICHT;               // lab3 + toets2 * 3
  const int GEWICHT_ONDeRDEEL2 = LAB_GEWICHT + TOETS_GEWICHT;                       // lab3 + toets2

  float avgOnderdeel1 = somOnderdeel1 / GEWICHT_ONDERDEEL1; // gemiddelde onderdeel1
  float avgOnderdeel2 = somOnderdeel2 / GEWICHT_ONDeRDEEL2; // gemiddelde onderdeel2

  if (avgOnderdeel1 < grens || avgOnderdeel2 < grens)
  {
    return false;
  }

  return true;
}

int main()
{
  float lab1 = 8.0;
  float lab2 = 8.0;
  float lab3 = 6.0;
  float toets1 = 5.0;
  float toets2 = 6.0;

  bool isGeslaagd = heeftToegang(lab1, lab2, lab3, toets1, toets2);

  std::string melding = isGeslaagd ? "=> Deelname oke" : "Geen deelname";

  std::cout << "Lab:" << lab1 << ";" << lab2 << ";" << lab3 << "Toets:" << toets1
            << ";" << toets2 << "  " << melding << std::endl;

  return 0;
}