#include <iostream>
#include <string>
#include <sstream>

std::string Teller(int max, int stappen)
{
    // Werkt alleen als max tussen 1 en 9 zit
    if (max <= 1 || max > 9)
    {
        return "foutje";
    }

    int wiel3 = 0, wiel2 = 0, wiel1 = 0;

    for (int i = 0; i < stappen; i++)
    {
        wiel1++;
        if (wiel1 == max)
        {
            wiel2++;
            wiel1 = 0;
        }
        if (wiel2 == max)
        {
            wiel3++;
            wiel2 = 0;
        }
    }
    std::stringstream buf;
    buf << wiel3 << wiel2 << wiel1;
    return buf.str();
}

int main()
{
    std::cout << Teller(9, 128) << std::endl;
    return 0;
}