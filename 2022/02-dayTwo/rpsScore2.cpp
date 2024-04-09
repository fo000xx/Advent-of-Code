#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

std::vector<std::string> replaceVecVal(std::vector<std::string> vecReplace, std::vector<std::string> vecKey)
{
    //iterate through vector replace values based on the vecKey and whether I need to win/lose/draw
    for (int i = 0; i < vecKey.size(); i++)
    {
        if (vecReplace[i] == "X")
        {
            if (vecKey[i] == "A")
            {
                vecReplace[i] = "C";
            }
            else if (vecKey[i] == "B")
            {
                vecReplace[i] = "A";
            }
            else if (vecKey[i] == "C")
            {
                vecReplace[i] = "B";
            }
        }
        else if (vecReplace[i] == "Y")
        {
            if (vecKey[i] == "A")
            {
                vecReplace[i] = "A";
            }
            else if (vecKey[i] == "B")
            {
                vecReplace[i] = "B";
            }
            else if (vecKey[i] == "C")
            {
                vecReplace[i] = "C";
            }
        }
        else if (vecReplace[i] == "Z")
        {
            if (vecKey[i] == "A")
            {
                vecReplace[i] = "B";
            }
            else if (vecKey[i] == "B")
            {
                vecReplace[i] = "C";
            }
            else if (vecKey[i] == "C")
            {
                vecReplace[i] = "A";
            }
        }
    }

    return vecReplace;
}

int totalScore(std::vector<std::string> elfChoice, std::vector<std::string> myChoice)
{
   int score { 0 };

    //replace X/Y/Z with A/B/C when required to lose/win/draw based on elfChoice
    std::vector<std::string> newVals( {replaceVecVal(myChoice, elfChoice)} );
    
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

int shapeChoiceandScore()
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
        elfChoice.push_back(elf);
        myChoice.push_back(mine);
    }
    
    // Put arrays into score calculation function
    int score { totalScore(elfChoice, myChoice) };
        
    return score;
}

int main()
{
    //get score
    int score { shapeChoiceandScore() };
    
    //print score
    std::cout << "Final score is: " << score << '\n';

    return 0;
}