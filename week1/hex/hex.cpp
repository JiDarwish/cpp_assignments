#include <iostream>
#include <sstream>
#include <string>

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

    union ConvertableFloat {
        long long myLong;
        float myFloat;
    };
    ConvertableFloat converter;
    converter.myFloat = f;

    std::ostringstream buf;
    buf << std::hex << converter.myLong;
    return buf.str();
}

int main()
{
    std::string result = floatToHex(1.2);
    std::cout << result << std::endl;
    return 0;
}