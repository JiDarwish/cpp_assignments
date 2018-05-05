#include <iostream>
#include <string>

std::string produceerReeks(int x)
{
    std::string output = std::to_string(x);

    while (x != 1) {

        if (x % 2 == 0) {
            x /= 2;
        } else {
            x = x * 3 + 1;
        }
        output += "," + std::to_string(x);
    }
    return output;
}

int main()
{
    std::cout << produceerReeks(3) << std::endl;
    return 0;
}