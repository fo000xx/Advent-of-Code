#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
    //open file
    std::ifstream inf ("input.txt");
    if (!inf)
    {
        std::cout << "Can't open file\n";
        return 1;
    }

    int startRange1 {0};
    int endRange1 {0};
    int startRange2 {0};
    int endRange2 {0};
    int rangeCount {0};
    int sumTotalOne {0};
    int sumTotalTwo {0};

    std::string line;
    std::string firstNum;
    std::string lastNum;
    
    while (getline(inf, line))
    {
        //read left column and right column as two strings with ',' as delim
        std::stringstream streamLine(line);
        std::string cleanRange;
        while (getline(streamLine, cleanRange, ','))
        {
            //split by '-', use switch statement for left/right columns
            std::stringstream ssRange(cleanRange);
            switch (rangeCount)
            {
            //read strings on either side of the '-' and convert to an int that's saved as start/end
            //of the range.
            case 0:
                getline(ssRange, firstNum, '-');
                getline(ssRange, lastNum, '-');
                startRange1 = std::stoi(firstNum);
                endRange1 = std::stoi(lastNum);
                break;
            case 1:
                getline(ssRange, firstNum, '-');
                getline(ssRange, lastNum, '-');
                startRange2 = std::stoi(firstNum);
                endRange2 = std::stoi(lastNum);
                break;
            }
            ++rangeCount;
            if (rangeCount == 2)
            {
                rangeCount = 0;
            } 
        }
        
        if ((startRange1 >= startRange2 && endRange1 <= endRange2) || (startRange2 >= startRange1 && endRange2 <= endRange1))
        {
            ++sumTotalOne;
        }
        if ((startRange1 >= startRange2 && startRange1 <= endRange2) || (startRange2 >= startRange1 && startRange2 <= endRange1))
        {
            ++sumTotalTwo;
        }
    }
    
    
    std::cout << "Answer to part one is: " << sumTotalOne << '\n';
    std::cout << "Answer to part two is: " << sumTotalTwo << '\n';

    return 0;
}
