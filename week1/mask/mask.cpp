#include <bitset>
#include <iostream>

typedef unsigned char Byte;
typedef unsigned int Uint;

Byte makeMask(Uint pos)
{
    Byte byte = 1;
    byte = byte << pos; // shift the one as much as asked
    return byte;
}

Byte setMask(Byte source, Byte mask)
{
    return source | mask;
}

//this is not working properly
Byte unsetMask(Byte source, Byte mask)
{
    return source & mask;
}

//this is not working properly
bool checkMask(Byte source, Byte mask)
{
    return source & mask == 0;
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
    std::cout << "maskUnSet\t" << std::bitset<8>(maskSet) << std::endl;

    return 0;
}