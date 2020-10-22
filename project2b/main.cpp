// YIEN WU and Padraic Burns 
// Project 2b
// Define the main function and execute program

#include <iostream>
#include <cmath>
#include <vector>
#include "Deck.h"


double playFlip(Deck& currHand)
{
	double score = 0;
	int userInput, numCards = 24;
	std::vector<bool> v(25, false);

	while (1)
	{
		std::cout << "Print out deck for reference" << std::endl;
		std::cout << currHand << std::endl;

		std::cout << "Enter an integer value from 1 to" << numCards << "to choose a card from";
		std::cout << "Entering a 0 will exit the game" << std::endl;

		do
		{
			std::cin >> userInput;

			if ((userInput < 0) || (userInput > 24))
			{
				std::cout << "The number you entered is out of range." << std::endl;
			}

			else if (v[userInput])
			{
				std::cout << "This is a repeat card:" << std::endl;
				std::cout << currHand.getCard(userInput) << std::endl;
				std::cout << "Please enter a different number" << std::endl;
			}

		} while ((userInput < 0) || (userInput > 24) || (v[userInput]));

		if (userInput == 0)
			break;
		else
		{
			v[userInput] = true;
			Card currCard = currHand.getCard(userInput);

			std::cout << "You picked this card: " << std::endl;
			std::cout << currHand.getCard(userInput) << std::endl;

			// calculate score based on project sheet

			switch (currCard.getValue())
			{
			case 1:
				score += 10;
				break;
			case 2:
				score = 0;
				break;
			case 3:
				score = 0;
				break;
			case 4:
				score = 0;
				break;
			case 5:
				score = 0;
				break;
			case 6:
				score = 0;
				break;
			case 7:
				score = score / 2;
			case 8:
			case 9:
			case 10:
			case 11:
				score = 0;
				break;
			case 12:
				score = 0;
				break;
			case 13:
				score += 5;
				break;
			}

			if (currCard.getSuit() == 'H')
			{
				score++;
			}
		}

		std::cout << "Current Score: " << score << std::endl;

		return score;
	}
}

int main()
{
	int numShuffles = 5;

	// start a new deck
	std::cout << "Creating an initial deck..." << std::endl;
	std::cout << "Deck pre-shuffle";
	Deck d("true");
	std::cout << d << std::endl;

	// shuffle the deck
	for (int i = 1; i <= numShuffles; i++)
	{
		d.shuffle();

	}

	// post shuffle deck
	std::cout << "Post-shuffle" << d << std::endl;

	playFlip(d);

	return 0;
}