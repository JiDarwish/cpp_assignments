#include "array.h"
#include <iostream>
#include <sstream>

typedef unsigned int uint;

uint getMaxPos(int reeks[], uint lengte)
{
    uint maxPos = 0;
    int maxElement = reeks[0];

    for (int i = 1; i < lengte; i++)
    {
        if (reeks[i] > maxElement)
        {
            maxElement = reeks[i];
            maxPos = i;
        }
    }
    return maxPos;
}

uint getMinPos(int reeks[], uint lengte)
{
    uint minPos = 0;
    int minElement = reeks[0];
    for (int i = 1; i < lengte; i++)
    {
        if (reeks[i] < minElement)
        {
            minElement = reeks[i];
            minPos = i;
        }
    }
    return minPos;
}

void verwissel(int reeks[], uint pos1, uint pos2)
{
    int temp = reeks[pos1];
    reeks[pos1] = reeks[pos2];
    reeks[pos2] = temp;
}

std::string toonReeks(int reeks[], uint lengte)
{
    std::stringstream buf;
    buf << "["; // opening

    for (int i = 0; i < lengte; i++)
    {
        buf << reeks[i];
        if (i != lengte - 1)
        {
            // it's not last element
            buf << ",";
        }
    }

    buf << "]"; // closing
    return buf.str();
}

void ordenOplopend(int reeks[], uint lengte)
{
    uint deLengte = lengte;
    for (int i = 0; i < lengte; i++)
    {
        int maxPost = getMaxPos(reeks, deLengte);
        verwissel(reeks, deLengte - 1, maxPost);
        deLengte--;
    }
}

void ordenAflopend(int reeks[], uint lengte)
{
    uint deLengte = lengte;
    for (int i = 0; i < lengte; i++)
    {
        int maxPost = getMinPos(reeks, deLengte);
        verwissel(reeks, deLengte - 1, maxPost);
        deLengte--;
    }
}

void ordenReeks(int reeks[], uint lengte, bool oplopend = true)
{
    if (oplopend)
    {
        ordenOplopend(reeks, lengte);
    }
    else
    {
        ordenAflopend(reeks, lengte);
    }
}

int main()
{
    const short LENGTE = 5;
    int arr[LENGTE] = {1, 6, 3, 7, 2};
    std::cout << toonReeks(arr, LENGTE) << std::endl;
    ordenReeks(arr, LENGTE, false);
    std::cout << "Aflopend" << toonReeks(arr, LENGTE) << std::endl;
    ordenReeks(arr, LENGTE, true);
    std::cout << "Oplopend" << toonReeks(arr, LENGTE) << std::endl;

    return 0;
}