#ifndef GENERATOR_H
#define GENERATOR_H

#include <chrono>
#include <random>

class generator {
private:
std::mt19937_64 gen;
std::uniform_int_distribution<int> distrib;
public:
generator(int min, int max);
int generate();
};

#endif // einde GENERATOR_H
