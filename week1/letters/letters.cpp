#include <bitset>
#include <iostream>
#include <sstream>
#include <string>

std::string maakGrootofKlein(const std::string bron)
{
    std::ostringstream result;

    for (int i = 0; i < bron.length(); i++)
    {
        char newChar = bron.at(i) ^ 32; // sixth position (xor will toggle 6th bit)
        result << newChar;
    }

    return result.str();
}

int main()
{

    std::string str = maakGrootofKlein("helloMan");
    std::cout << str << std::endl;
    return 0;
}
