#include <iostream>
#include <sstream>
#include <string>
#include "generator.h"
#include "stegano.h"
#include "generator.cpp"

generator gen(0, 25);
std::string alfabet = "abcdefghijklmnopqrstuvwxyz";

std::string maakRegel(size_t lengte)
{
  std::stringstream buf;
  for (int i = 0; i < lengte; i++)
  {
    int generated = gen.generate();
    buf << alfabet.at(generated);
  }
  return buf.str();
}

void schrijf(std::string &regel, std::string geheim)
{
}

std::string lees(std::string regel)
{
}

int main()
{
  std::string geheim = "Denkend aan Holland";
  std::string regel = maakRegel(geheim.length() * 8);
  std::cout << regel;
  // schrijf(regel, geheim);
  // std::string ontvangst = lees(regel);
  // std::cout << ontvangst << std::endl;
  return 0;
}