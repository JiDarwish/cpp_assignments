#include <iostream>
#include <sstream>
#include <iterator>
#include "rpn.h"

std::vector<std::string> getTokens(std::string line)
{
  std::istringstream iss(line);
  std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                  std::istream_iterator<std::string>{}};
  return tokens;
}

Operator getOperator(std::string token)
{
  switch (token.at(0))
  {
  case '+':
    return Operator::PLUS;
  case '-':
    return Operator::MIN;
  case '*':
    return Operator::MAAL;
  case '/':
    return Operator::DEEL;
  default:
    return Operator::ONBEKEND;
  }
}

bool procesOperator(std::stack<int> &stapel, Operator oper)
{

  if (oper == Operator::ONBEKEND || stapel.size() < 2)
  {
    return false;
  }

  int num1 = stapel.top();
  stapel.pop();
  int num2 = stapel.top();
  stapel.pop();

  int resultaat = 0;

  switch (oper)
  {
  case Operator::PLUS:
    resultaat = num2 + num1;
    break;
  case Operator::MIN:
    resultaat = num2 - num1;
    break;
  case Operator::DEEL:
    resultaat = num2 / num1;
    break;
  case Operator::MAAL:
    resultaat = num2 * num1;
    break;
  }
  stapel.push(resultaat);
  return true;
}

bool compute(std::string rpn, int &uitkomst)
{
  std::vector<std::string> strAlsVec = getTokens(rpn);
  std::stack<int> integers; // gebruikt om de nummers te houden

  for (int i = 0; i < strAlsVec.size(); i++)
  {
    Operator oper = getOperator(strAlsVec[i]); // returns the Operator (Enum)

    bool isOperator = procesOperator(integers, oper);
    if (!isOperator)
    {
      int intFromStr = atoi(strAlsVec[i].c_str());
      integers.push(intFromStr);
    }
  }
  uitkomst = integers.top();
}

int main()
{
  std::string rpn_line = "12 3 4 * + 7 - 3 /";
  int uitkomst = 0;
  bool resultaat = compute(rpn_line, uitkomst);
  std::cout << "Uitkomst is: " << uitkomst << std::endl;
  return 0;
}