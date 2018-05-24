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

void verwerkBits(std::string &regel, int &pos, char c)
{
  for (int i = 0; i < 8; i++)
  {
    if (c & (1 << i))
    {
      regel[pos] |= 1;
    }
    else
    {
      regel[pos] &= ~(1);
    }
    pos++;
  }
}

void schrijf(std::string &regel, std::string geheim)
{
  int pos = 0;
  for (int i = 0; i < geheim.length(); i++)
  {
    char c = geheim[i];
    verwerkBits(regel, pos, c);
  }
}

char haalChar(std::string subStr)
{
  char returned = 0;
  for (int i = 0; i < subStr.length(); i++)
  {
    if (subStr[i] & 1)
    {
      returned |= (1 << i);
    }
    else
    {
      returned &= ~(1 << i);
    }
  }
  return returned;
}

std::string lees(std::string regel)
{
  std::string out = "";
  int numLettersInOut = regel.length() / 8;
  std::cout << numLettersInOut << std::endl;
  for (int i = 0; i < numLettersInOut; i++)
  {
    int pos = i * 8;
    std::string subStr = regel.substr(pos, 8);
    out += haalChar(subStr);
  }
  return out;
}

int main()
{
  std::string geheim = "Denkend aan Holland";
  std::string regel = maakRegel(geheim.length() * 8);
  schrijf(regel, geheim);
  std::string ontvangst = lees(regel);
  std::cout << ontvangst << std::endl;
  return 0;
}