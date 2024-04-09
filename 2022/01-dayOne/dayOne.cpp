#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream inf { "input.txt" };

    if (!inf)
    {
        std::cerr << "Can't open file\n";
        return 1;
    }

    int max = 0;
    int total = 0;
    std::string line;
    while (std::getline(inf, line))
    {
        if (line.size() == 0) 
        {
            max = std::max(max, total);
            total = 0;
        }
        else
        {
            total += std::stoi(line);
        }
    }
    max = std::max(max, total);
    std::cout << max << '\n';

    return 0;
}
