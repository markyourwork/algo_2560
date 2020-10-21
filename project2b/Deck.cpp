// YIEN WU and Padraic Burns 
// Project 2b
// Define the Deck class with definitions for Deck, Shuffle,
// and overloads the << operator


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Card.h"
#include "Node.h"

class Deck
{
public:
	
	Deck(std::string deckType);
	
	
	~Deck();


	void shuffle();


	Card getCard(int cardIdx);

	void replace(Node <Card>* rep);


	Node <Card>* deal();


	friend std::ostream& operator << (std::ostream& ostr, const Deck& d);

private:

	Node <Card>* topN;
};

Deck::Deck(std::string deckType)

{

	topN = NULL;


	srand(time(NULL));

	if (deckType.compare("true")==0)
	{

		for (int i = 1; i <= 13; i++)
		{

			topN = new Node<Card>(Card(i, 'C'), topN);

			topN = new Node<Card>(Card(i, 'D'), topN);

			topN = new Node<Card>(Card(i, 'H'), topN);

			topN = new Node<Card>(Card(i, 'S'), topN);
		}
	}
}

Deck::~Deck()

{
	std::cout << "Destruct deck" << std::endl;
	Node <Card>* curr = topN;
	Node <Card>* temp;


	while (curr != NULL)
	{
		temp = curr->next;
		delete curr;
		curr = NULL;
		curr = temp;
	}
}
void Deck::shuffle()

{
	int currIdx = 0, shuffleTimes = 10000, targetCardIdx = 0;

	Node <Card> *curr;
	Node <Card> *prev;
	Node <Card> *last = topN;
	Node <Card> *switchedCard;
	curr = topN;
	prev = topN;
	switchedCard = topN;


	while (last->next != NULL)
	{
		last = last->next;
	}

	for (int i = 0; i <= shuffleTimes; i++)
	{

		currIdx = 0;
		prev = topN;
		curr = topN;


		targetCardIdx = std::rand() % 51;


		if (targetCardIdx == 51)
		{

			break;
		}

		else if (targetCardIdx == 0)
		{

			switchedCard = topN;

			topN = topN->next;

			switchedCard->next = NULL;

			last->next = switchedCard;
			last = last->next;
		}

		else
		{

			while (currIdx != targetCardIdx -1)
			{
				prev = prev->next;
				currIdx++;
			}


			curr = prev->next;


			prev->next = prev->next->next;

			last->next = curr;
			last = last->next;
			last->next = NULL;
		}
	}
}

Card Deck::getCard(int cardIdx)
{
	int currIdx = 0;
	Node <Card> *curr;
	curr = topN;

	while (currIdx != cardIdx)
	{
		curr = curr->next;
		currIdx++;
	}

	return curr->nodeValue;
}

Node <Card>* Deck::deal()
{
		
	Node <Card>* curr;

	curr = topN;

	topN = topN->next;
	
	return curr;
}

	
void Deck::replace(Node <Card>* rep)
{

	Node <Card>* back = topN;

		
	rep->next = NULL;


	if (topN == NULL)
	{
		topN = rep;
		return;
	}

	
	while (back->next != NULL)
		back = back->next;


	back->next = rep;
}


std::ostream& operator << (std::ostream& ostr, const Deck& d)
{

	Node <Card>* curr;
	curr = d.topN;
	std::cout << "curr: " << curr << std::endl;


		while (curr!=NULL)
		{
			ostr << curr->nodeValue << std::endl;
			curr = curr->next;
		}
	return ostr;
}