//Padraic Burns and Yi-En Wu, Problem Set 2
//this file include$ all of the code inside of the mastermind game

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>


class Code
{
private:
	int length = 0;
	int maxDigit = 0;
	std::vector<int> key;


public:
	Code(int n, int m);
	Code(std::vector<int>);
	Code();
	int getLength() const;
	void printCode() const;
	std::vector<int> getKey() const;
	int checkCorrect(Code guess) const;
	int checkIncorrect(Code guess) const;
	int getMaxDigit() const;
	std::vector<int> generateCode(int n, int m);


};
Code::Code(int n, int m)
//First Code object Constructor. 
{
	length = n;
	maxDigit = m - 1;
	key = generateCode(length, maxDigit);
}

Code::Code(std::vector<int> guessVector)
//Second Code object Constructor. 
{
	//Find length of guess
	length = guessVector.size();

	//a for loop to read digit so it can find max digit
	for (int i = 0; i < length; i++)
	{
		if (guessVector[i] > maxDigit)
			maxDigit = guessVector[i];
	}

	key = guessVector;
}

Code::Code()
//Default constructor 
{
	length = 5;
	maxDigit = 10;
}

std::vector<int> Code::generateCode(int n, int m)
//get random code based on user inputs 
{
	std::vector<int> answerVector;

	for (int i = 0; i < n; i++)
	{
		int digitToAdd = rand() % m;
		answerVector.push_back(digitToAdd);
	}

	return answerVector;
}

int Code::checkCorrect(Code guess) const
//return the digits in correct position 
{
	int countCorrect = 0;
	int guessLength = guess.getLength();
	std::vector<int> guessKey = guess.getKey();

	for (int i = 0; i < guessLength; i++)
	{
		if (guessKey[i] == key[i])
			countCorrect++;
	}

	return countCorrect;
}

int Code::checkIncorrect(Code guess) const
//return the digits in incorrect position 
{
	int countIncorrect = 0;
	std::vector<int> guessKey = guess.getKey();
	std::vector<bool> vBool(key.size(), false);
	for (int i = 0; i < guessKey.size(); i++)
	{
		for (int k = 0; k < key.size(); k++)
		{
			if ((k != i) && (key[i] == guessKey[k]))
			{
				std::cout << "value" << ", " << key[i] << ", " << guessKey[k] << std::endl;
				std::cout << "index" << ", " << i << ", " << k << std::endl;

				vBool[i] = true;
				break;

			}
		}
	}

	countIncorrect = count(vBool.begin(), vBool.end(), true);
	return countIncorrect;
}
int Code::getMaxDigit() const
//return the max digit
{
	return maxDigit;
}
int Code::getLength()const
//return the object length
{
	return length;
}
std::vector<int> Code::getKey() const
//return key
{
	return key;
}



