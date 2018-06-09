#include <iostream>
#include <sstream>
#include <string>

std::string Regel(int lengte, int stap)
{
    std::stringstream buf;

    for (int i = 1; i <= lengte; i++)
    {
        if (i % stap == 0)
        {
            buf << "-";
        }
        else
        {
            buf << ".";
        }
    }
    return buf.str();
}

std::string Pagina(int min, int max, int stap, bool terug)
{
    if (min < 0 || max < min)
    {
        return "";
    }

    std::stringstream buf;

    for (int i = min; i < max; i++)
    {
        buf << Regel(i, stap) + "\n";
    }

    if (!terug)
    {
        return buf.str();
    }

    for (int i = max; i >= min; i--)
    {
        buf << Regel(i, stap) + "\n";
    }

    return buf.str();
}

int main()
{
    std::cout << Pagina(3, 7, 2, true) << std::endl;
    return 0;
}
