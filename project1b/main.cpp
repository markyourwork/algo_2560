//Padraic Burns and Yi-En Wu, Problem Set 2
//this file include$ all of the code inside of the mastermind game

#include "Mastermind.h"

int main()
{
	int answerCodeLength, answerCodeMaxDigit;

	
	std::cout << "Mastermind Game" << std::endl;

	
	std::cout << "Please enter a code length: " << std::endl;
	std::cin >> answerCodeLength;
	std::cout << "Please enter the range " << std::endl;
	std::cin >> answerCodeMaxDigit;

	Mastermind m = Mastermind(answerCodeLength, answerCodeMaxDigit);

	m.playGame();
	//End
}