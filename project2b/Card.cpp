// YIEN WU and Padraic Burns 
// Project 2b
// Card class definition
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <array>

class Card
{
private:
	// value of card
	int value;

	// C for clubs, D for diamonds, S for spades, H for hearts
	char suit;

public:
	Card(int v, char s);
	Card(const Card& t);
	void setValue(int value);
	void setSuit(char suit);
	int getValue() const;
	char getSuit() const;
	friend std::ostream& operator<< (std::ostream& ostr, const Card& t);
	Card& operator= (const Card& t);

};

#endif Card_h
Card::Card(int v, char s)
{
	value = v;
	suit = s;
}

Card::Card(const Card& v)
{
	value = v.value;
	suit = v.suit;
}

void Card::setValue(int v)
{
	if (v < 1 || v > 13)
	{
		std::cout << "Unable to set card value. Invalid input." << std::endl;
		return;
	}
	value = v;
}


void Card::setSuit(char s)

{

	char acceptedLetter[8] = { 'C', 'D', 'H', 'S', 'c', 'd', 'h', 's' };
	int acceptedLetterSize = sizeof(acceptedLetter) / sizeof(char);
	int idx = 0;
	bool flag = false;

	while (flag == false && idx < acceptedLetterSize)
	{
		if (s == acceptedLetter[idx])
			flag = true;
		idx++;
	}

	if (flag == true)
	{
		suit = s;
	}

	else
		std::cout << "Unable to set card suit. Invalid input." << std::endl;
}

int Card::getValue() const

{
	return value;
}

char Card::getSuit() const

{
	return suit;
}

std::ostream& operator<< (std::ostream& ostr, const Card& t)

{

	int val = t.getValue();


	if (val >= 2 && val <= 10)
	{
		ostr << "Value: " << val << ", Suit: " << t.getSuit();
	}
	else
	{
	
		char charVal;

	
		switch (t.getValue())
		{
		case 1: // if value = 1
			charVal = 'A';
			break;

		case 11:
			charVal = 'J';
			break;

		case 12:
			charVal = 'Q';
			break;

		case 13:
			charVal = 'K';
			break;

		default:
			charVal = t.getValue();
		}

		ostr << "Value: " << charVal << ", Suit: " << t.getSuit();
	}

	return ostr;
}

Card& Card::operator= (const Card& t)

{
	value = t.value;
	suit = t.suit;

	return *this;
}