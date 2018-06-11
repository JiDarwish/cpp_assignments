#include <bitset>
#include <iostream>
#include <sstream>
#include <string>

std::string maakGrootofKlein(const std::string bron)
{
    std::ostringstream result;
    int const SIXTH_POS = 32; // bit on the 6th position (masker)
    for (unsigned int i = 0; i < bron.length(); i++)
    {
        char newChar = bron.at(i);
        if ((int)newChar % 2 == 0)
        {
            newChar &= ~(SIXTH_POS); // clear bit
        }
        else
        {
            newChar |= SIXTH_POS; // set bit
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
