//Padraic Burns and Yi-En Wu, Problem Set 1

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <array>
#include <card.h>

using namespace std; 

//Effectively is just a linked list class 
class deck 
{

private:
cardDeck *top, *bottom;

public:
cardDeck head;

//creates an empty deck of cards with the cards in order
deck()
{
top = NULL;
bottom = NULL;
}
//creates an empty deck of cards with the cards in order
deck(string s)
{
top = NULL;
bottom = NULL;
string suits [4] = {"Clubs", "Diamonds", "Hearts", "Spades"};

for(int i = 0; i < 4; i++)
{
    string currentsuit = suits[i];
    for(int j = 13; j >= 1; j--)
    {
        this->add_card(card(currentsuit, j));
    }
}
}
//used to add a given Node
void add_card(card c)
{
cardDeck *temp = new cardDeck;
temp->Acard = c;
temp->next = NULL;
if(top == NULL)
{
    top = temp;
    bottom = temp;
}
else
{
    bottom->next = temp;
    bottom = bottom->next;
}
}

//overwritten output operator
friend ostream& operator<<(ostream& dex, deck* d)
{
    //h=d->
    /*
    void print(cardDeck* h)
{
    //kinda cludgy way to print the first one differnt from the rest
    if(h != NULL){
        cout<< h->Acard;
        h = h->next;
    }
    while(h != NULL)
    {
        cout<< "-->" <<h->Acard;
        h == h->next;
    }

}
    */
}
};

//Effectively is just a node but for this card game
struct cardDeck
{
card Acard;
struct cardDeck *next;
};