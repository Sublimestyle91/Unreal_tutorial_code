#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(int MyMaxTries)
{
	this->MyMaxTries = MyMaxTries;
	reset();
}

void FBullCowGame::reset()
{
	MyCurrentTry = 1;
	return;   // for some reason ben wants us to add this 
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

/*void FBullCowGame::UpdateCurrentTry()
{
	MyCurrentTry++;
	return;
}*/

