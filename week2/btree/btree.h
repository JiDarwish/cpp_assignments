#ifndef BTREE_H
#define BTREE_H

#include <string>

struct Node {
        std::string woord = "";
        Node* rechts = NULL;
        Node* links = NULL;
};

// ----------------------------------
// zie de voorbeeld functie in de opdracht pdf
int intCompare(int eerste, int tweede);

// ----------------------------------
// deze compare fie geeft -1, 0, 1 return
//      volgens de alfabetische ordening
//      voorbeeld: compare("aap","zee")   => -1
//                 compare("noot","mies") => 1
//                 compare("noot","aap")  => 1
int strCompare(std::string eerste, std::string tweede);

// ----------------------------------
// hier kijken we alleen naar de lengte van de beide strings.
// deze compare fie geeft -1, 0, 1 return
//      volgens de integer vergelijking van deze lengtes.
//      voorbeeld: compare("aap","zee")   => 0
//                 compare("noot","mies") => 0
//                 compare("noot","aap")  => 1
int strLengteCompare(std::string eerste, std::string tweede);

// ----------------------------------
// eerst bepalen we de juiste positie in de binairy tree
//      om een node (met het opgegeven woord) toe te voegen.
//      hierbij gebruiken we de opgegeven compare functie, bij elke node,
//      om te bepalen of het woord links of rechts moet worden toegevoegd.
//      geeft de compare functie <= 0 , dan links , anders rechts!
// de compare parametr is hier een pointer naar een functie!
void addToBtree( Node** rootptr, std::string woord, int (*compare)(std::string, std::string ));

// ----------------------------------
// hier schrijven we alle woorden naar de opgegeven stream
// met volgorde voor elke node:
//      eerst wat links staat ,
//      dan het 'eigen' woord,
//      vervolgens alles wat rechts staat
void exportBTree(Node* root, std::stringstream& ss);

#endif // einde BTREE_H
