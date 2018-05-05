#include <iostream>
#include <sstream>
#include <iterator>
#include "rpn.h"

std::vector<std::string> getTokens(std::string line);
Operator getOperator(std::string token);
bool procesOperator(std::stack<int> &stapel, Operator oper);
bool compute(std::string rpn, int &uitkomst);

int main()
{
  std::string rpn_line = "12 3 4 * + 7 - 3 /";
  int uitkomst = 0;
  bool resultaat = compute(rpn_line, uitkomst);
  return 0;
}