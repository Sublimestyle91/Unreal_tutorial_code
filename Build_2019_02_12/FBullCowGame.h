#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>




using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessValidity
{
	Invalid_Status,
	Ok,
	Not_isogram,
	lower_case,
	wrong_length

};

class FBullCowGame {
public:
	FBullCowGame();

	// Getter Methods
	int32 GetMaxTries() const;
	int32 GetHiddenWordLength() const;
	int32 GetCurrentTry() const;
	FString GetHiddenWord() const;


	void reset(); // TODO make a more rich return value
	bool IsGameWon() const; 
	EGuessValidity CheckGuessValidity(FString) const; 
	FBullCowCount SubmitValidGuess(FString);
	FString GetWord();


private:
	int32 MyCurrentTry;
	//int32 MyMaxTries;
	FString MyHiddenWord;
	bool bHaveYouWon;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
	int32 RandomNumber265();
};







// 02 - 08 - 2019
/*
	I replaced all occurances of std::string with FString in FBullCowGame.h I used using Fstring = std::string to do this.


	Notes:
		never use namespace in a header file. It can really mess up things
		Ben actually says to just use the std codename infront and avoid namespaces altogether
		Also, for all classes in unreal tournment, we use F

*/

// 02 - 09 - 2019
/*
	1) Created a new struct type to hold the counts. BullCowCounts
	2) Made a new function called submit guess that returns a struct
	3) I think the submit guess is what counts the bulls and cows
	4) Added an Enum value to it. Enums must start with an Eaccording to unreal
	5) Gave CheckGuessValidity function a richer return type (EGuessValidity)
	
	Notes:
	Without class in enumerations, the scope of the enums value is global. If we had
	two enum variables with the same memember variable, then it wouldn't compile. 
	We could maybe us namespace

*/

// 02 - 10 - 2019
/*
	Notes:
	I notice that for structs and Enums, they are in this file
*/

// 02 - 11 - 2019
/*
	Notes:
		When making a private boolean variable you should preface it with b, such as
		bHaveYouwon
*/