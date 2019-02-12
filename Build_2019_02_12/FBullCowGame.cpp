#include "FBullCowGame.h"
#include <vector>
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
	//this->MyMaxTries = MyMaxTries;
	reset();
}

void FBullCowGame::reset()
{
	MyHiddenWord = GetWord();
	bHaveYouWon  = false;
	MyCurrentTry = 1;
	return;   // for some reason ben wants us to add this 
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap <int32, int32> WordLengthNumberOfTries{ {1,2}, {2,3}, {3,4},
												 {4,10}, {5,11}, {6,10},
												 {7,12}, {8,13}, {9,10},
												 {10,11}, {11,12}, {12,13},
												 {13,14},  {14,15}, {15,16},
												 {16, 17}, {17,18}, {18, 19}};
	
	return WordLengthNumberOfTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

FString FBullCowGame::GetHiddenWord() const
{
	return MyHiddenWord;
}

bool FBullCowGame::IsIsogram(FString Word) const
{

	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	// setup a map
	TMap<char, bool> LetterSeen;
	// loop through all the letters of the word
	for (auto letter : Word)
	{
		letter = tolower(letter);  // makes letter lowercase
	// if the letter is in the map.
		if (LetterSeen[letter])
		{
			return false;
		}
		// we do not have an isogram
	// otherwise
		// add the letter to the map as seen
		else
		{
			LetterSeen[letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto letter : Word)
	{
		if (letter == tolower(letter))
		{
			return false;
		}
	}
	return true;
}

int32 FBullCowGame::RandomNumber265()
{
	int rn;
	srand(time(NULL));
	rn = rand() % 265;   // length of vector
	return rn;
}

bool FBullCowGame::IsGameWon() const
{
	return bHaveYouWon;
}

EGuessValidity FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // if not an isogram (can only contain one of every letter
	{
		return EGuessValidity::Not_isogram; 
	}
	else if (IsLowerCase(Guess)) // if not lower case
	{
		return EGuessValidity::lower_case; //TODO make function for this
	}
	else if (Guess.length() != MyHiddenWord.length() ) // if wrong length
	{
		return EGuessValidity::wrong_length;
	}
	else   // if okay
	{
		return EGuessValidity::Ok;
	}
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString guess)
{
	// increment the turn number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount; // already initialized
	// loop through all letters in the game
	int32 WordLength = MyHiddenWord.length(); // ben's code
	for (int32 i = 0; i < WordLength; i++) {
		// compare letters against the hidden word
		for (int32 j = 0; j < WordLength; j++) {
			 //if they match
			if (guess[i] == MyHiddenWord[j]) {     // if char guess[1] is in hiddenword
				// If they're in the same place
				if (i == j)                        // if at the same position
				{
					// increment bulls
					BullCowCount.Bulls++;
				}
				// else
				else
				{
				// increment cows
				BullCowCount.Cows++;
				}
			}
		}
	}

	// Check if there is a winner
	if (BullCowCount.Bulls == WordLength)
	{
		bHaveYouWon = true;
	}
	return BullCowCount;
}

FString FBullCowGame::GetWord()
{
	std::vector<FString> words;
	FString line;
	std::ifstream myfile("Names.txt");
	if (myfile.is_open())
	{
		
		FString container;
		while(!myfile.eof())
		{
			myfile >> container;
			words.push_back(container);
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
	
	
	return words[RandomNumber265()];
}






// 02 - 08 - 2019
/*
	1) I replaced all occurances of std::string with FString in FBullCowGame.h and FBullCowGame.cpp I used using Fstring = std::string to do this.
	2) I replace all the occurances of int for int32 to keep up with unreal standards
*/

// 02 - 09 - 2019
/*
	functions edited: 
		-submit guess
		-reset
	1) Made SubmitGuess method
		increment the turn number
		setup a return variable
		loop through all letters in the game
		compare letters against the hidden word
	2) Structs should have an F at the beginning for unreal format
	3) Added to for loops to SubmitGuess; it might be a bad idea to use a method in a for
	   loop declaration?

	4) There is an error which is that we can't use a word shorter
	than the hidden word

	Notes:
	Always use constants for things that will never change. You can use constexpr for literals
	and then const for references. 
	Ctrl + E + C to comment section

	When you initialize the FBullCowGame object at the beginning, it does the reset function in the constructor
	This makes it so that the program counts the number of letters in the word
	
*/

// 02 - 10 - 2019
/*
	1) change name of SubmitGuess to SubmitValidGuess
	Notes:
	I can use ctrl + r + r to change the name of a function and every instance of that function
*/

// 02 - 10 - 2019
/*

	1) IsoIsogram added
	2) You need to make this constant because CheckValidity is also constant
	3) F12 for jumping around code

	Notes:
	-Remember to not call a function if you already have a variable called
	-Ben went over hash tables it seems like a very interesting idea
	-He started getting into Hash Tables. They seem pretty cool
	-Here is a link to algorithm used for looking for an isogram
	-https://community.gamedev.tv/t/using-regex-for-isogram-checl/35881/10
	-IsoIsogram is asking a simple question. Is it an Isogram. We don't need to change data.


*/

// 02 - 12 - 2019
/*
	1) Setup a map
	2) made lower rase
	3) setup outlier conditions
	4) used range loop and then map
	5) Added a new function called IsLowerCase()
	6) Added a note for how many tries it is out of
	7) Added a TMap to GetMaxTries to make it so certain words higher the difficulty
	8) Got rid of MaxTries variable


	Notes:
	Be careful of the logic.
	With the IsLowerCase function, we could actually use the function islower(letter). This
	is a built in function in C++
	if(!islower(letter))
	{
		return false;
	}

	There is also a note about avoiding implicit dependencies. The checking order depends
	On which one is violated first. 

	Challenge:
	-Can we make it so that we could possibly write every check the user fails
	-Can we take in random data and use that as our private word. Then it would be
	a pretty fun game. 
	-Make it so that you can actually choose how many max tries you will have
	-Add some ASCII art

	#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main ()
{
    string array[5]; // creates array to hold names
    short loop=0; //short for loop for input
    string line; //this will contain the data read from the file
    ifstream myfile ("example.txt"); //opening the file.
    if (myfile.is_open()) //if the file is open
    {
        while (! myfile.eof() ) //while the end of file is NOT reached
        {
            getline (myfile,line); //get one line from the file
            array[loop] = line;
            cout << array[loop] << endl; //and output it
            loop++;
        }
        myfile.close(); //closing the file
    }
    else cout << "Unable to open file"; //if the file is not open output
    system("PAUSE");
    return 0;
}

string line;
  ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
	while ( getline (myfile,line) )
	{
	  cout << line << '\n';
	}
	myfile.close();
  }

  else cout << "Unable to open file";


  This supposedly will read it if space or newline
  int main()
{
    int m;
    while(cin>>m)
    {
    }
}

  return 0;
*/