#include <iostream> // This file includes so many overloaded things that we need to specify the exact space we are using
#include <string>    // So I can use the string class
#include "FBullCowGame.h"
//using namespace std;   // We don't actually need this, but this will specify which functions we want from iostream.
//using namespace std; // if not here all couts would look like std:: cout. We are actually going to replace all these wtih std:: cout


void PrintIntro(); // prototype: remember about proper programming // also make capital for methods
std::string GetGuess();
void PrintGuess(std::string guess);
void PlayGame();
bool AskToPlayAgain();


FBullCowGame BCGame(5);    // a global instance. Is this okay. The five is the max tries you can guess the word

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
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to cows and bulls! A word game where you guess what word I am thinking.\n";
	std::cout << "The word will be " << WORD_LENGTH << " letters long. ";
	return; // for some reason ben says to return even if it is void
}

std::string GetGuess() {
	std::string guess;

	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "\nTry: " << CurrentTry << " What is your guess for the word: ";
	std::getline(std::cin, guess);  // even though this words, you should still use std::std::getline
	BCGame.UpdateCurrentTry();
	return guess;
}

void PrintGuess(std::string guess)
{
	std::cout << "Your guess is: " << guess;
	std::cout << std::endl << std::endl;
}

void PlayGame()
{
	BCGame.reset();
	std::string guess;
	int MaxTries = BCGame.GetMaxTries();
	
	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE once we are validating the tries
	for (int i = 0; i < MaxTries; i++)
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
	std::string restart = "";
	std::cout << "Do you want to play again? (Y/N) ";
	std::getline(std::cin, restart);
	BCGame.reset();
	return (toupper(restart[0]) == 'Y');
}



// It seems std is the name space. There are so many things called cout, that we need to specify the space.
// Also, if we bring it in as a name space, can we remove std. I put it above
// if two different namespaces both use cout, then we run the risk of having an ambigous call 
// always a risk when using a namespace.

/* be careful when using std::cin. If there is a space such as in donkey kong. Then you will still have something
   left in the strea.*/

// ctrl + h is used for replacing stuff
// ctrl + r + r is for refactoring tool, changing all names from one to another