#include <bitset>
#include <iostream>

typedef unsigned char Byte;
typedef unsigned int Uint;

Byte makeMask(Uint pos)
{
    return 1 << pos;
}

Byte setMask(Byte source, Byte mask)
{
    return source | mask;
}

Byte unsetMask(Byte source, Byte mask)
{
    return source & ~(mask);
}

bool checkMask(Byte source, Byte mask)
{
    return (bool)(source & mask);
}

int main()
{
    Byte myMask = makeMask(4);
    Byte mySource = 7;
    Byte maskSet = setMask(mySource, myMask);
    Byte maskUnSet = unsetMask(mySource, myMask);
    std::cout << "Source\t\t" << std::bitset<8>(mySource) << std::endl;
    std::cout << "Mask\t\t" << std::bitset<8>(myMask) << std::endl;
    std::cout << "maskSet\t\t" << std::bitset<8>(maskSet) << std::endl;
    std::cout << "isMasked?\t\t" << checkMask(maskSet, myMask) << std::endl;
    std::cout << "maskUnSet\t" << std::bitset<8>(maskUnSet) << std::endl;
    std::cout << "isMasked?\t\t" << checkMask(mySource, myMask) << std::endl;

    return 0;
}