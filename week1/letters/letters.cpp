#include <bitset>
#include <iostream>
#include <string>

// not working what does it mean for an ascii code to be even ???????
std::string maakGrootofKlein(const std::string bron)
{
    std::string output = "";

    for (unsigned int i = 0; i < bron.length(); i++) {
        int asciiWaarde = int(bron.at(i));
        std::cout << std::bitset<8>(asciiWaarde) << '\t' << asciiWaarde << '\t' << bron.at(i) << '\t' << std::bitset<8>(bron.at(i)) << std::endl;
        char uppercased = (char)asciiWaarde & ~(1101111);
        std::cout << uppercased << '\t' << std::bitset<8>(uppercased) << std::endl;
    }
}

int main()
{
    std::string str = "hello";
    std::string resultStr = maakGrootofKlein(str);
    std::cout << resultStr << std::endl;

    return 0;
}

/*
std::string out = "";

    for (unsigned int i = 0; i < bron.length(); i++) {
        int asciiCode = (int)bron.at(i);
        if (asciiCode % 2 == 0) {
            std::cout << (char)asciiCode << std::endl;
            std::cout << std::bitset<8>((char)asciiCode) << std::endl;
            asciiCode &= 11011111;
            out += (char)asciiCode;
            std::cout << (char)asciiCode << std::endl;
            std::cout << std::bitset<8>((char)asciiCode) << std::endl;

        } else {
            //std::cout << (char) asciiCode <<std::endl;
            //std::cout <<std::bitset<8>((char) asciiCode) <<std::endl;
            std::cout << "Here" << std::endl;
            asciiCode |= 0;
            //std::cout << (char) asciiCode <<std::endl;
            //std::cout <<std::bitset<8>((char) asciiCode) <<std::endl;
            out += (char)asciiCode;
            out += (char)asciiCode;
        }
    }
    return out;
*/