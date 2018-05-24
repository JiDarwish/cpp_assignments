#ifndef STEGANO_H
#define STEGANO_H
#include <string>

//-------------------------
// maak en string van opgegeven lengte.
//    vul deze string met willekeurige letters uit het 'alfabet'.
//    gebruik de gegeven random generator (klasse generator)
std::string maakRegel(size_t lengte);

//-------------------------
// deze functie lees de bytes van het geheim en neemt elke bit alzonderlijk.
//    deze wordt steeds geschreven naar de LSB van een character uit de  regel.
//    gebruik hier de bitwise operatoren &= en |= voor het zetten van de 1-bit of de 0-bit.
void schrijf( std::string& regel, std::string geheim);

//-------------------------
// deze functie leest van elke byte in de regel de LSB en combineert deze tot een character.
//    deze chars worden geschreven naar de return string.
std::string lees(std::string regel);

#endif // einde STEGANO_H
