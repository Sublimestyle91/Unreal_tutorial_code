#pragma once
#include <string>
// never use namespace in a header file. It can really mess up things
// Ben actually says to just use the std codename infront and avoid namespaces altogether
// Also, for all classes in unreal tournment, we use F

class FBullCowGame {
public:
	FBullCowGame(int MyMaxTries);
	void reset(); // TODO make a more rich return value
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string); // TODO make a more rich return value
	//void UpdateCurrentTry();
	// provide a method for counting bulls, and cows, and increasing turn #


private:
	int MyCurrentTry;
	int MyMaxTries;

};