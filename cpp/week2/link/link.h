#ifndef LINK_H
#define LINK_H

#include <string>

struct element {
        std::string woord;
        struct element * next = NULL;
};

// ---------------------
// elke nieuwe string (tekst) wordt opgenomen in een struct element
// het einde van de lijst wordt bepaald en daar wordt het nieuwe element geplaatst.
void VoegToeAanEindeLijst(element ** lijst, std::string tekst );


// ---------------------
// elke nieuwe string (tekst) wordt opgenomen in een struct element
// het nieuwe element wordt geplaatst aan het begin van de lijst.
// De rest van de lijst wordt hierachter geplaatst.
void VoegToeAanBeginLijst(element ** lijst, std::string tekst );

// ---------------------
// elke nieuwe string (tekst) wordt opgenomen in een struct element
// Dit elemnt wordt op de juiste plaats tussengevoegd.
//      (volgens de alfabetische ordening van de woorden)
void VoegToeAlfabetisch(element ** lijst, std::string tekst );

// ---------------------
// de woorden worden in een string geplaatst, gescheiden door komma's, (zonder spaties!)
// de gehele string staat tussen rechte haken, '[' en ']'.
std::string ToonLijst( element * lijst );

#endif // einde LINK_H
