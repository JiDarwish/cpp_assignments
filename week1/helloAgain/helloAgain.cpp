#include <iostream>
#include <string>

std::string samenvoegen(std::string eerste, std::string tweede)
{
  return eerste + " " + tweede;
}

int main()
{
  std::cout << samenvoegen("Hallo", "wereld") << std::endl;
  return 0;
}