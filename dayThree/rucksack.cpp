#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>

std::map<char, std::size_t> buildMap()
{
    std::map<char, std::size_t> charValue;
    for (int i = 0; i < 26; i++)
    {
        charValue['a' + i] = i + 1;
        charValue['A' + i] = i + 27;
    }
    return charValue;
}

int findDupeAndValue(std::map<char, std::size_t> charValue)
{
    std::ifstream inf ("input.txt");
    if (!inf)
    {
        std::cout << "Can't open file\n";
    }

    std::set<char> charSet;
    std::string line;
    int sumTotal = 0;

    while (std::getline(inf, line))
    {
        for (int i = 0; i < line.size() / 2; i++)
        {
            charSet.insert(line[i]);
        }
        for (int i = line.size() / 2; i < line.size(); i++)
        {
            if (charSet.contains(line[i]))
            {
                sumTotal += charValue[line[i]];
                break;
            }
        }
        charSet.clear();
    }
    return sumTotal;
}

int main()
{
    //build a map of a-Z and associated priorities(values)
    std::map<char,std::size_t> charValue {buildMap()};
    
    //find total of values
    int sumTotal { findDupeAndValue(charValue) };

    //print total
    std::cout << sumTotal << '\n';
    return 0;
}
