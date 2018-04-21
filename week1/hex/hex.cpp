#include <string>
#include <iostream>
#include <bitset>
#include <sstream>

union Convertable {
    char character;
    float myFloat;
};

std::string charToHex(char c){
    std::ostringstream buf;
    buf << std::hex << (unsigned int) c << std::endl;
    return buf.str();
}

std::string intToHex(int x){
    std::ostringstream buf;
    buf << std::hex << x << std::endl;
    return buf.str();
}

std::string floatToHex(float f){
    std::ostringstream buf;
    Convertable toBeConverted;
    toBeConverted.myFloat = f;
    buf << std::hex << (unsigned int) toBeConverted.character << std::endl; // what ???
    return buf.str();
}

int main() {
    std::string result = floatToHex(0.1);
    return 0;
}