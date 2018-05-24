#include <bitset>
#include <iostream>
#include <sstream>
#include <string>

std::string maakGrootofKlein(const std::string bron)
{
    std::ostringstream result;

    for (int i = 0; i < bron.length(); i++)
    {
        char newChar = bron.at(i);
        if ((int)newChar % 2 == 0)
        {
            newChar |= 32; // set bit
        }
        else
        {
            newChar &= ~(32); // clear bit
        }

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
