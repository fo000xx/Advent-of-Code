#include <iostream>
#include <set>
#include <fstream>
#include <map>

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

int findCommonValue(std::map<char, std::size_t> charValue)
{
    std::ifstream inf ("input.txt");
    if (!inf)
    {
        std::cout << "Can't open file\n";
    }

    std::multiset<char> firstElf;
    std::multiset<char> secondElf;
    std::string line;
    int sumTotal { 0 };

    int lineCount { 0 };
    while (std::getline(inf, line))
    {
        switch (lineCount) 
        {
        case 0:
            for (int i = 0; i < line.size(); i++)
            {
                firstElf.insert(line[i]);
            }
            break;
        case 1:
            for (int i = 0; i < line.size(); i++)
            {
                secondElf.insert(line[i]);
            }
            break;
        case 2:
            for (int i = 0; i < line.size(); i++)
            {
                if (firstElf.contains(line[i]) && secondElf.contains(line[i]))
                {
                    sumTotal += charValue[line[i]];
                    break;
                }
            }
            break;
        }
        
        ++lineCount;
        if (lineCount == 3) 
        {
            lineCount = 0;
            firstElf.clear();
            secondElf.clear();
        }
    }
    return sumTotal;
}

int main()
{
    //build a map of a-Z and associated priorities(values)
    std::map<char,std::size_t> charValue {buildMap()};
   
    // find total values of letters that are shared between three line sets
    int sumTotal { findCommonValue(charValue) };
    
    //print total
    std::cout << sumTotal << '\n';
    return 0;
}
