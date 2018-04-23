#include <bitset>
#include <iostream>
#include <sstream>
#include <string>

union Convertable {
    char character;
    float myFloat;
};

std::string charToHex(char c)
{
    std::ostringstream buf;
    buf << std::hex << (unsigned int)c << std::endl;

    std::string out = buf.str();

    if (out.length() < 3) { // 3 because there is always a last character terminating a string which is '\n'
        out = "0" + out;
    }
    return out;
}

std::string intToHex(int x)
{
    std::ostringstream buf;
    buf << std::hex << x << std::endl;

    std::string out = buf.str();

    if (out.length() < 3) { // 3 because there is always a last character terminating a string which is '\n'
        out = "0" + out;
    }
    return out;
}

std::string floatToHex(float f)
{
    std::ostringstream buf;
    Convertable toBeConverted;
    toBeConverted.myFloat = f;
    buf << std::hex << (unsigned int)toBeConverted.character << std::endl; // what ???
    return buf.str();
}

int main()
{
    std::string result = charToHex('C');
    std::cout << result << std::endl;
    return 0;
}