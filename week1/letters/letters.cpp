#include <iostream>
#include <string>
#include <bitset>

// not working what does it mean for an ascii code to be even ???????
std::string maakGrootofKlein(const std::string bron){
    std::string out = "";

    for (int i = 0; i < bron.length(); i++) {
        int asciiCode = int(bron.at(i));
        if (asciiCode % 2 == 0) {
            std::cout << (char) asciiCode <<std::endl; 
            std::cout <<std::bitset<8>((char) asciiCode) <<std::endl; 
            asciiCode |= 10000;
            out += (char) asciiCode;
            std::cout << (char) asciiCode <<std::endl;            
            std::cout <<std::bitset<8>((char) asciiCode) <<std::endl;

        } else {
            //std::cout << (char) asciiCode <<std::endl; 
            //std::cout <<std::bitset<8>((char) asciiCode) <<std::endl;                                   
            asciiCode |= 0;
            //std::cout << (char) asciiCode <<std::endl;            
            //std::cout <<std::bitset<8>((char) asciiCode) <<std::endl;
            out += (char) asciiCode;
            out += (char) asciiCode;
        }
    }
    return out;
}

int main(){
    std::string str = "asWfxSg";
    std::string resultStr = maakGrootofKlein(str);
    std::cout << resultStr << std::endl;
    
    return 0;
}