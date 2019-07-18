#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n You are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room.\n You need to enter the correct code to continue.\n\n"; 
}

bool PlayGame(int Difficulty)
{

PrintIntroduction(Difficulty);

    // Welcome to the numbers game 
    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    // Print CodeSum and CodeProduct to the terminal
    
    std::cout << "\n + There are 3 numbers in the code";
    std::cout << "\n + The codes add up to " << CodeSum;
    std::cout << "\n + The codes multiply to give " << CodeProduct << std::endl;

    // Store Player Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    // Check if the players guess is correct
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "Correct proceed" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Access denied\n";
        return false;
    }
}
int main() 
{   
    srand(time(NULL)); // Create new random sequence based on the time of day
    
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop until all the levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear(); //Clears any errors
    std::cin.ignore(); // Discard the buffer

        if  (bLevelComplete) 
        {
            ++LevelDifficulty;
        }

    }
    std::cout << "Well done you're in! Get the files and leave";
    return 0; 
}