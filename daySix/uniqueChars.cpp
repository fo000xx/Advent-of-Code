#include <iostream>
#include <fstream>
#include <set>

int findNonDupe(std::string line, int numChar)
{
    //loop through consecutive numChar and insert into a set
    for (int i = numChar - 1; i < line.size(); i++)
    {
        std::set<char> dupeCheck;
        int count { numChar };
        for (int j = i; count > 0; --j, --count)
        {
            dupeCheck.insert(line[j]);
        }
        //if no duplicates, set will == numChar searched. 
        if (dupeCheck.size() == numChar)
        {
            return i;
        }
        dupeCheck.clear();
    }
    return EXIT_FAILURE;
}

int main()
{
    std::ifstream inf { "input.txt" };

    if (!inf)
    {
        std::cerr << "Can't open file\n";
        return 1;
    }
    //getline to stream the inf
    std::string line;
    std::getline(inf, line);
    
    //set the number of characters to check
    int numChar { 14 };
    
    int ans { findNonDupe(line, numChar) };

    //print result
    std::cout << ans + 1 << '\n';
}
