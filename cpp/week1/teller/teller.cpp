#include <iostream>
#include <string>

std::string Teller(int max, int stappen)
{
    if (max <= 1)
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
    return std::to_string(wiel3) + std::to_string(wiel2) + std::to_string(wiel1);
}

int main()
{
    std::cout << Teller(9, 128) << std::endl;
    return 0;
}