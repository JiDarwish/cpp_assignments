#ifndef ARRAY_H
#define ARRAY_H

typedef unsigned int uint;

// bepaal de index van de grootste integer waarde in de reeks.
uint getMaxPos(int reeks[], uint lengte);

// bepaal de index van de kleinste integer waarde in de reeks.
uint getMinPos(int reeks[], uint lengte);

// verwissel de waarden van de integers op de 2 opgegeven posities.
void verwissel(int reeks[], uint pos1, uint pos2);

// toon de reeks van integers, gescheiden door een komma
//      de hele reeks staat tuusen '[' en ']'.
//      geen spaties !!
// voorbeeld: [1,5,4,7,3,2,9]
void toonReeks(int reeks[], uint lengte);

#endif // einde van ARRAY_H
