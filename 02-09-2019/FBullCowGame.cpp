#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(int32 MyMaxTries)
{
	this->MyMaxTries = MyMaxTries;
	reset();
}

void FBullCowGame::reset()
{
	MyCurrentTry = 1;
	return;   // for some reason ben wants us to add this 
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

/*void FBullCowGame::UpdateCurrentTry()
{
	MyCurrentTry++;
	return;
}*/




// 02 - 08 - 2019
/*
	1) I replaced all occurances of std::string with FString in FBullCowGame.h and FBullCowGame.cpp I used using Fstring = std::string to do this.
	2) I replace all the occurances of int for int32 to keep up with unreal standards
*/