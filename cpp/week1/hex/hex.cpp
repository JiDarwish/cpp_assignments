#include <iostream>
#include <sstream>
#include <string>

std::string charToHex(char c)
{
    std::ostringstream buf;
    buf << std::hex << std::uppercase << (unsigned int)c << std::endl;

    std::string out = buf.str();

    if (out.length() <= 2)
    {
        out = "0" + out;
    }
    return out;
}

std::string intToHex(int x)
{
    std::ostringstream buf;
    buf << std::hex << std::uppercase << x << std::endl;

    std::string out = buf.str(); // convert to string to be able to prepend to it

    if (out.length() <= 2)
    {
        out = "0" + out;
    }
    return out;
}

std::string floatToHex(float f)
{

    union ConvertableFloat {
        long long myLong;
        float myFloat;
    };
    ConvertableFloat converter;
    converter.myFloat = f;

    std::ostringstream buf;
    buf << std::hex << std::uppercase << converter.myLong;
    return buf.str();
}

int main()
{
    std::string result = floatToHex(1.2);
    std::cout << result << std::endl;
    std::string result2 = intToHex(2);
    std::cout << result2 << std::endl;
    return 0;
}
