#pragma once
#include <string>
using FString = std::string;
using int32 = int;


class FBullCowGame {
public:
	FBullCowGame(int32 MyMaxTries);
	void reset(); // TODO make a more rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString); // TODO make a more rich return value
	//void UpdateCurrentTry();
	// provide a method for counting bulls, and cows, and increasing turn #


private:
	int32 MyCurrentTry;
	int32 MyMaxTries;

};







// 02 - 08 - 2019
/*
	I replaced all occurances of std::string with FString in FBullCowGame.h I used using Fstring = std::string to do this.


	Notes:
		never use namespace in a header file. It can really mess up things
		Ben actually says to just use the std codename infront and avoid namespaces altogether
		Also, for all classes in unreal tournment, we use F

*/