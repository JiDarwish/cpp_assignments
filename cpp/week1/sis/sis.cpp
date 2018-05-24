#include <iostream>

bool heeftToegang(float lab1, float lab2, float lab3, float toets1,
                  float toets2)
{
  float grens = 6.0;

  float alleLabs[] = {lab1, lab2, lab3};
  float alleToetsen[] = {toets1, toets2};

  // check toetsen voor fraude of onvoldoende
  for (int i = 0; i < sizeof(alleToetsen) / sizeof(alleToetsen[0]); i++)
  {
    if (alleToetsen[i] > 10.0 || alleToetsen[i] == 0 || alleToetsen[i] < 4.0)
    {
      return false;
    }
  }

  // Check cijfers van labs voor fraude of boven 8.0
  for (int i = 0; i < sizeof(alleLabs) / sizeof(alleLabs[0]); i++)
  {
    if (alleLabs[i] > 10.0 || alleLabs[i] == 0)
    {
      return false;
    }
    else if (alleLabs[i] > 8.0)
    {
      grens -= 1;       // verlaag de grens
      alleLabs[i] += 1; // verhoog dat cijfer -> de gemiddelde van dat onderdeel
    }
  }

  float somOnderdeel1 = alleLabs[0] + alleLabs[1] + alleToetsen[0] * 3; // lab1 + lab2 + toets1 * 3
  const int GEWICHT_ONDERDEEL1 = 1 + 1 + 3;                             // lab1 + lab2 + toets1
  float somOnderdeel2 = alleLabs[2] + alleToetsen[1] * 3;               // lab3 + toets2 * 3
  const int GEWICHT_ONDeRDEEL2 = 1 + 3;                                 // lab3 + toets2

  float avgOnderdeel1 = somOnderdeel1 / GEWICHT_ONDERDEEL1; // gemiddelde onderdeel1
  float avgOnderdeel2 = somOnderdeel2 / GEWICHT_ONDeRDEEL2; // gemiddelde onderdeel2

  if (avgOnderdeel1 < grens || somOnderdeel2 < grens)
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