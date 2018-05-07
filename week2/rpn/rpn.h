#ifndef RPN_H
#define RPN_H

#include <stack>
#include <vector>
#include <string>

enum Operator
{
  ONBEKEND,
  PLUS,
  MIN,
  MAAL,
  DEEL
};

// -----------------
// de functie getTokens zal een regel splitsen in tokens.
// elke whitespace [ spatie, tab, etc ] is een scheidingsteken van tokens.
// !! de body van deze functie krijg je in de code file !!
std::vector<std::string> getTokens(std::string line);

// -----------------
// bepaal of een opgegeven string (token) een operator is en zo ja welke.
// is het token geen operator geef dan ONBEKEND return.
// anders  "+" => PLUS
//         "-" => MIN
//         "*" => MAAL
//         "/" => DEEL
Operator getOperator(std::string token);

// -----------------
// De stack van integers wordt gemanipuleerd volgens de aangeboden operator.
// is de operator ONBEKEND dan is de return waarde false.
// zijn de benodigde integers niet op de stapel te vinden, dan return false.
// anders, return true na het manipuleren van de stapel.
bool procesOperator(std::stack<int> &stapel, Operator oper);

// -----------------
// Deze functie krijgt een RPN string aangeboden en probeert de uitkomst te bepalen.
// worden fouten geconstateerd dan return false ( met uitkomst = 0 )
// in deze functie :
//    maak een lijst van tokens van de rpn-string
//    maak een lege stack van integers
//    bepaal van elk token of het een operator is of een integer.
//    plaats integers op de stack en
//                verwerk de operatoren mbv de functie: procesOperator.
//
// aan het einde van de rpn-string verwerking, mag er niet meer dan 1 integer op de stack staan.
//    dit is dan de uitkomst.
bool compute(std::string rpn, int &uitkomst);

#endif // einde RPN_H
