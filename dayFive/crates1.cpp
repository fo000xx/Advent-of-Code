#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

/*
[V]         [T]         [J]        
[Q]         [M] [P]     [Q]     [J]
[W] [B]     [N] [Q]     [C]     [T]
[M] [C]     [F] [N]     [G] [W] [G]
[B] [W] [J] [H] [L]     [R] [B] [C]
[N] [R] [R] [W] [W] [W] [D] [N] [F]
[Z] [Z] [Q] [S] [F] [P] [B] [Q] [L]
[C] [H] [F] [Z] [G] [L] [V] [Z] [H]
 1   2   3   4   5   6   7   8   9 
*/

//void move(int numMove, std::vector<std::string> fromStack, std::vector<std::string> toStack, int size)
//{

//}

void printAns(std::vector<std::vector<std::string>> crateLayout)
{
    int numStacks = crateLayout.size();
    for (int i = 0; i < numStacks; ++i)
    {
        std::cout << crateLayout[i].back();
    }
    std::cout << '\n';
}

int main()
{
    // create vector of vectors for above design
    std::vector<std::vector<std::string>> crateLayout 
                                        {   {"C","Z","N","B","M","W","Q","V"},
                                            {"H","Z","R","W","C","B"},
                                            {"F","Q","R","J"},
                                            {"Z","S","W","H","F","N","M","T"},
                                            {"G","F","W","L","N","Q","P"},
                                            {"L","P","W"},
                                            {"V","B","D","R","G","C","Q","J"},
                                            {"Z","Q","N","B","W"},
                                            {"H","L","F","C","G","T","J"}
                                        };

    // read input.txt
    std::ifstream inf ("input.txt");
    if (!inf)
    {
        std::cout << "Can't open file\n";
        return 1;
    }

    // read each line as a stream 1 at a time & save to a vector {instructions vector}
    std::string line;
    
    while (getline(inf, line))
    {
        std::stringstream linestream(line);
        std::string word;
        std::vector<std::string> instruct;
        while(getline(linestream, word, ' '))
        {
            //vector of the format {"move"}, {"1"}, {"from"}, {"2"}, {"to"}, {"1"}
            instruct.push_back(word);
        }  
        //asign vector entrants to int to be used within movement loop
        int crateStart = std::stoi(instruct[3]) - 1;
        int crateEnd = std::stoi(instruct[5]) - 1;
        int numMove = std::stoi(instruct[1]);
        int size = crateLayout[crateStart].size();

        //move(numMove, crateLayout[crateStart], crateLayout[crateEnd], size);
            if (numMove > size)
    {
        numMove = size;
    }
    for (int i = 1; i <= numMove; ++i)
    {
        crateLayout[crateEnd].push_back(crateLayout[crateStart][size - i]);
    }          
    for (int i = 0; i < numMove; ++i)
    {
        crateLayout[crateStart].pop_back();
    }
    }
    printAns(crateLayout);
    return 0;
}
