//#include <iostream> 
#include <string>    
#include "FBullCowGame.h"


using Ftext = std::string;
using int32 = int;

// Prototypes
void PrintIntro();
Ftext GetValidGuess();
Ftext GuessPrompt();
void PrintGuess(Ftext guess);
void PlayGame();
bool AskToPlayAgain();
void PrintWinOrLose();
void PrintHiddenWord();

// Global instance of Class
FBullCowGame BCGame;   // 5 is the number of tries one can have

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
	std::cout << "Welcome to cows and bulls! A word game where you guess what word I am thinking.\n";
	std::cout << "The word will be " << BCGame.GetHiddenWordLength() << " letters long. ";
	return; 
}

Ftext GuessPrompt()
{
	Ftext guess;

	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "\nTry: " << CurrentTry << " of " << BCGame.GetMaxTries();
	std::cout << ". What is your guess for the word: ";
	std::getline(std::cin, guess);
	return guess;
}

void PrintWinOrLose()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "YOU Win! \n";
	}
	else
	{
	std::cout << "\nBetter Luck Next time Cowboy! \n";
	PrintHiddenWord();
	}
}

Ftext GetValidGuess() {
	Ftext guess;
	EGuessValidity Status = EGuessValidity::Invalid_Status;
	do {
		guess = GuessPrompt();
		Status = BCGame.CheckGuessValidity(guess);
		switch (Status)
		{
		case EGuessValidity::wrong_length:
			std::cout << "Please enter a word with " << BCGame.GetHiddenWordLength() << " letter(s).\n";
			break;
		case EGuessValidity::lower_case:
			std::cout << "Please enter an all lower-case word.\n";
			break;
		case EGuessValidity::Not_isogram:
			std::cout << "Please enter a word that doesn't have repeat letters in it.\n";
			break;
		default:
			break;
		}

	} while (Status != EGuessValidity::Ok);

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
	
	// loop for max tries
	// game not one
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		guess = GetValidGuess(); // TDOD make loop checking valid


		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(guess);
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;
		PrintGuess(guess);
	}

	PrintWinOrLose();
	return;
}

bool AskToPlayAgain()
{
	Ftext restart = "";
	std::cout << "Do you want to play again? (Y/N) ";
	std::getline(std::cin, restart);
	BCGame.reset();
	return (toupper(restart[0]) == 'Y' && restart.length() == 1);
}

void PrintHiddenWord()
{
	std::cout << "The hidden word was " << BCGame.GetHiddenWord() << ".";
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

// 02 - 09 - 2019
/*
	functions edited:
		-playgame function

	1) Submit function added
	
	Notes:
		Only store data when you need to store data
*/

// 02 - 10 - 2019
/*
	1) Changed Get guess to GetValid guess
	Notes:
	I put a do while loop in the GetValidGuess loop. To get rid of the return error I had
	I made sure to initialize a variable at the top called Ftext guess. This made it so 
	I can have the variable in scope outside the while loop. The while loop acts like a function
	Variables inside will not necessarily show up outside.
*/

// 02 - 11 - 2019
/*
	1) change for loop in playgame to while loop
	Notes:
	2) Made prototypes for the new methods ( don't forget to make prototypes)
	3) Got rid of Todos. Nice

	Notes:
	-!!!!!!!!!!!!!!!!!! I could make the program read a file so I can get random words
	for the game. Then it would be a pretty cool game
*/