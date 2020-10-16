//Padraic Burns and Yi-En Wu, Problem Set 1

#ifndef cardDeck
#define cardDeck

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <array>
#include <card.h>
#include "d_node.h"

using namespace std; 

class deck 
{

private:
node<card>* topCard;
node<card>* bottomCard;
public:

//creates an deck of ordered cards
deck()
{
    topCard = NULL;
    //bottomCard = NULL;
    string suits [4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    for(int i = 0; i < 4; i++)
    {
        string currentsuit = suits[i];
        for(int j = 13; j >= 1; j--)
        {
            topCard = new node<card>(card(currentsuit, j), topCard);
        }
    }
}

/*Doesn't work, might impliment at a later time
void add_card(card c)
{
    node <card> *temp = new node;
    temp->Acard = c;
    temp->next = NULL;
    if(topCard == NULL)
    {
        topCard = temp;
        bottomCard = temp;
    }
    else
    {
        bottomCard->next = temp;
        bottomCard = bottomCard->next;
    }
}*/
void shuffle()
{
    srand(time(NULL));
    //large number of shuffles
    int numShuffles = rand() % 61; 
        node<card>* fiftyTwo = NULL;
        //repeatedly halves and interleaves the deck
        for (int i = 1; i <= numShuffles; i++) 
        {
            fiftyTwo = fiftyfifty();
            flipFlop(fiftyTwo);
        }
}
//segments the deck like a dealer would into halves
 node<card>* fiftyfifty()
    {
        node<card>* current = topCard;
        for (int i = 1; i <= 26; i++)
        {
            current = current->next;
        }
        node<card>* topOfHalf = current->next;
        current->next = NULL;
        return topOfHalf;
    }
//interleaves the cards from the two halves of the deck
void flipFlop(node<card>* top_bottom_half)
    {
            //current highest card in the top 50%
            node<card>* curr_top_half = topCard;
            //current highest card in the bottom 50%
            node<card>* curr_bottom_half = top_bottom_half;
            //placeholder card for the top
            node<card>* new_top = new node<card>(card(), NULL);
            node<card>* curr_new_top = new_top;
            
            //itterate over half the deck
            for (int i = 1; i <= 26; i++)
            {
                //add card from top half of the deck to new smaller deck
                curr_new_top->next = curr_top_half;
                //reassign the top
                curr_new_top = curr_new_top->next;
                //reassing top for deck since it was moved
                curr_top_half = curr_top_half->next;

                //add card from second half of the list to new list
                curr_new_top->next = curr_bottom_half;
                //reassign the top
                curr_new_top = curr_new_top->next;
                //reassign top of deck since we moved the card 
                curr_bottom_half = curr_bottom_half->next;

            }
            new_top = new_top->next;
            topCard = new_top;
        } 
    

//overwritten output operator
friend ostream& operator<<(ostream& dex, const deck& d)
{
    node<card>* pointer = d.topCard;
    for (int i = 1; i <= 52; i++)
    {
        //ostr << "Card Value: " << p->nodeValue.getValue() << " Card Suit: ";
        //ostr << p->nodeValue.getSuit() << endl;
        dex << pointer->nodeValue;
        pointer = pointer->next;
    }
    return dex;
}
};

#endif