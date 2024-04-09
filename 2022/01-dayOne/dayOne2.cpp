#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream inf { "input.txt" };

    if (!inf)
    {
        std::cerr << "Can't open file\n";
        return 1;
    }

    std::vector<int> totals(1,0);
    std::string line;
    while (std::getline(inf, line))
    {
        if (line.size() == 0) 
        {
            totals.push_back(0);
        }
        else
        {
            totals.back() += std::stoi(line);
        }
    }

    std::nth_element(std::begin(totals), std::begin(totals) + 2, std::end(totals), std::greater<int>());
    const auto sum = totals[0] + totals[1] + totals[2];
    std::cout << sum << '\n';

    return 0;
}
