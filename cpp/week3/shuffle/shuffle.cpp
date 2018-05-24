#include <iostream>
#include "shuffle.h"
#include <random>
#include <algorithm>
#include <sstream>

shuffle::shuffle(uint num)
{
  numOfNumbers = num;
  score = 0;

  for (int i = 1; i <= numOfNumbers; i++)
  {
    numbers.push_back(i);
  }
  std::random_shuffle(numbers.begin(), numbers.end());
}

std::string shuffle::tostring()
{
  std::stringstream buf;

  for (int i = 0; i < numbers.size(); i++)
  {
    if (i == numbers.size() - 1)
    {
      buf << numbers[i];
    }
    else
    {
      buf << numbers[i] << ", ";
    }
  }

  return buf.str();
}

bool shuffle::isGeordend()
{
  int num = numbers[0];
  for (int i = 1; i < numbers.size(); i++)
  {
    if (num + 1 != numbers[i])
    {
      return false;
    }
    num = numbers[i];
  }
  return true;
}

uint shuffle::geefScore()
{
  return score;
}

shuffle::~shuffle()
{
}

bool shuffle::manipuleer(uint num)
{
  std::reverse(numbers.begin(), numbers.begin() + num);
  score++;
  return isGeordend();
}

int main()
{
  uint numOfNumbers = 7;
  shuffle shuf(numOfNumbers);
  std::cout << shuf.tostring() << std::endl;
  std::cout << shuf.manipuleer(5) << std::endl;
  std::cout << shuf.tostring() << std::endl;

  return 0;
}