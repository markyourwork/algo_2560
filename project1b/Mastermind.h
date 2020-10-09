//Padraic Burns and Yi-En Wu, Problem Set 2
//this file include$ all of the code inside of the mastermind game


#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Code.h"
#include "Response.h"

class Mastermind
{
private:
	Code answerCode;
	Response accurateResponse;
	int answerLength;
	int answerMaxDigit;

	Code humanGuess();

public:
	int guessesRemaining = 10;
	Code humGuess;

	Mastermind(int n, int m);
	Mastermind();
	void playGame();
	Response getResponse(Code guessCode) const;
	bool isSolved(Response r) const;
	void printSecretCode(Code answerCode) const;



};

Mastermind::Mastermind(int n, int m)
//user can take control of the game 
{
	answerLength = n;
	answerMaxDigit = m;
}

Mastermind::Mastermind()
//if user did not give input, default constructor 
{
	answerLength = 5;
	answerMaxDigit = 10;
}

void Mastermind::printSecretCode(Code answerCode) const
//print the secret code 
{
	std::string printString = "";
	std::vector<int>keyToStr = answerCode.getKey();
	
	for (int i = 0; i < keyToStr.size(); i++)
	{
		printString.append(std::to_string(keyToStr[i]));
	}

	std::cout << "The secret code length: " << answerCode.getLength()
		<< ", and up to digit, " << answerCode.getMaxDigit() + 1 << ", is: " << printString
		<< std::endl;
}

Code Mastermind::humanGuess()
//read the guess 
{
	std::vector<int> guessVector;
	std::string guessStr;
	int currentDigit;

	std::cout << " still have " << guessesRemaining << " chances " << std::endl;
	std::cout << "Please enter your guesses " << std::endl;
	std::cin >> guessStr;

	for (int i = 0; i < guessStr.length(); i++)
	{
		currentDigit = guessStr[i] - '0';
		guessVector.push_back(currentDigit);
	}

	Code guessCode = Code(guessVector);
	guessesRemaining--;
	return guessCode;
}

Response Mastermind::getResponse(Code guessCode) const
//return response 
{
	Response r = Response(guessCode, answerCode);

	return r;
}

bool Mastermind::isSolved(Response r) const
//return response if the game is over
	if (r == accurateResponse)
		return true;
	else
		return false;
}

void Mastermind::playGame()
{
	Code ansCode = Code(answerLength, answerMaxDigit);
	answerCode = ansCode;

	//print Code
	printSecretCode(answerCode);

	//Sets accurateResponse 
	Response accurateResponse = Response(answerCode, answerCode);
	std::cout << "Accurate response: " << accurateResponse << std::endl;

	//Give 10 tries to the codebreaker
	for (int tries = 10; tries > 0; tries--)

		Code hGuess = humanGuess();
		humGuess = hGuess;

		Response toCheck = Response(humGuess, answerCode);
		std::cout << toCheck << std::endl;

		if (isSolved(toCheck))
		{
			std::cout << "Congratulations! You won" << std::endl;
			break;
		}
		//If not solved and there are tries remaining
		else if (!isSolved(toCheck) && tries != 0)
		{
			std::cout << "Incorrect." << std::endl;
		}
		//Not solved and no tries remaining
		else
		{
			std::cout << "Game over. " << std::endl; 
		}
	}
}
