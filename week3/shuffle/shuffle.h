#ifndef SHUFFLE_H
#define SHUFFLE_H

#include <string>
#include <vector>

class shuffle
{
  private:
    // hier je eigen PRIVATE data items en methoden
    int numOfNumbers;
    uint score;
    std::vector<int> numbers;

  public:
    // constructor met de parameter geeft aan hoe lang de reeks getallen moet zijn.
    shuffle(uint);
    // de destructor
    ~shuffle();
    // de functie die de reeks getallen manipuleert volgens de opgave.
    bool manipuleer(uint);
    // geeft true als de reeks 1 ... N is , anders false
    bool isGeordend();
    // geeft de reeks van getallen , door een komma gescheiden. v.b. : 4,5,2,1,3 (geen spaties !)
    std::string tostring();
    // geef de score (= het aantal manipulaties)
    uint geefScore();
};

#endif // einde SHUFFLE_H
