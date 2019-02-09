#include <iostream> 
#include <string>    
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

// Prototypes
void PrintIntro();
Ftext GetGuess();
void PrintGuess(Ftext guess);
void PlayGame();
bool AskToPlayAgain();

// Global instance of Class
FBullCowGame BCGame(5);   

int main()
{


	// functions
	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	

	return 0;
}

void PrintIntro() {

	// variables and constants
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to cows and bulls! A word game where you guess what word I am thinking.\n";
	std::cout << "The word will be " << WORD_LENGTH << " letters long. ";
	return; 
}

Ftext GetGuess() {
	Ftext guess;

	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "\nTry: " << CurrentTry << " What is your guess for the word: ";
	std::getline(std::cin, guess); 
	return guess;
}

void PrintGuess(Ftext guess)
{
	std::cout << "Your guess is: " << guess;
	std::cout << std::endl << std::endl;
}

void PlayGame()
{
	BCGame.reset();
	Ftext guess;
	int32 MaxTries = BCGame.GetMaxTries();
	
	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE once we are validating the tries
	for (int32 i = 0; i < MaxTries; i++)
	{
		guess = GetGuess(); // TDOD make loop checking valid

		// Submit valid guess to the game
		// print number of bulls and cows
		PrintGuess(guess);
	}

	// TODO summarize game
}

bool AskToPlayAgain()
{
	Ftext restart = "";
	std::cout << "Do you want to play again? (Y/N) ";
	std::getline(std::cin, restart);
	BCGame.reset();
	return (toupper(restart[0]) == 'Y');
}






// 02 - 08 - 2019
/*
	1) I replaced all occurances of std::string with Ftext in main.cpp. I used using Ftext = std::string to do this. 
	2) replaced int with int32 except for in the int main method for computer reasons
	Notes: 
		It seems std is the name space. There are so many things called cout, that we need to specify the space.
		Also, if we bring it in as a name space, can we remove std. I put it above
		if two different namespaces both use cout, then we run the risk of having an ambigous call 
		always a risk when using a namespace.
		be careful when using std::cin. If there is a space such as in donkey kong. Then you will still have something
		left in the strea.
		This file includes so many overloaded things that we need to specify the exact space we are using
		
		ctrl + h is used for replacing stuff
		ctrl + r + r is for refactoring tool, changing all names from one to another

		Ben says that we should always have a return statement
		You can put Todo's in your code for a task and the compile will actually find them for you
*/