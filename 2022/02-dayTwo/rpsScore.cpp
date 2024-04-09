#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

std::vector<std::string> replaceVecVal(std::vector<std::string> vecReplace)
{
    std::replace(vecReplace.begin(), vecReplace.end(), "X", "A");
    std::replace(vecReplace.begin(), vecReplace.end(), "Y", "B");
    std::replace(vecReplace.begin(), vecReplace.end(), "Z", "C");

    return vecReplace;

}

int totalScore(std::vector<std::string> elfChoice, std::vector<std::string> myChoice)
{
   int score { 0 };

    //replace X/Y/Z with A/B/C where A/X are rock, B/Y are paper, C/Z are scissors
    std::vector<std::string> newVals( {replaceVecVal(myChoice)} );
    
    // calculate score based on w/d/l - iterate through and compare the values, assigning 3 for draw, 0 for loss, 6 for win
    for (int i = 0; i < elfChoice.size(); i++)
    {
        if (elfChoice[i] == newVals[i])
        {
            score += 3;
        }
        else if (((elfChoice[i] == "A") && (newVals[i] == "B")) || ((elfChoice[i] == "B") && (newVals[i] == "C")) || ((elfChoice[i] == "C") && (newVals[i] == "A")))
        {
            score += 6;
        }
        else if (((elfChoice[i] == "B") && (newVals[i] == "A")) || ((elfChoice[i] == "C") && (newVals[i] == "B")) || ((elfChoice[i] == "A") && (newVals[i] == "C")))
        {
            score += 0;
        } 
    }

    // add score for the symbol chosen
    for (int i = 0; i < newVals.size(); i++)
    {
        if (newVals[i] == "A")
        {
            score += 1;
        }
        else if (newVals[i] == "B")
        {
            score += 2;
        }
        else if (newVals[i] == "C")
        {
            score += 3;
        }
        else
        {
            score += 0;
        }
    }
    return score;
}

int shapeChoiceAndScore()
{
    //read file and print error if it can't be opened
    std::ifstream inf("input.txt");
    if (!inf)
    {
        std::cerr << "Can't open file\n";
        return 1;
    }

    //initialise vectors  to be used
    std::vector<std::string> elfChoice;
    std::vector<std::string> myChoice;
      
    //loop through .txt and save left column and right column to two vectors
    for (std::string elf, mine; std::getline(inf, elf, ' ') && std::getline(inf, mine);)
    {
        //std::cout << "Elf: " << elf << " Mine: " << mine << '\n';
        elfChoice.push_back(elf);
        myChoice.push_back(mine);
    }
    
    // Put arrays into score calculation function
    int score { totalScore(elfChoice, myChoice) };
        
    return score;
}

int main()
{
    int score { shapeChoiceAndScore() };
    
    std::cout << "Final score is: " << score << '\n';
    return 0;
}
