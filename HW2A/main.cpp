//Padraic Burns and Yi-En Wu, Problem Set 1
//this file include$ all of the code required to run a mastermind game

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "cardDeck.h"
using namespace std; 

int main(){
    card num1 = card();
    cout<<num1<<"\n";
    cout<<num1.getColor()<<" <- this should be random\n";
    card num2 = card("Clubs", 1);
    cout<<num2<<"\n";
    cout<<num2.getColor()<<" <-this should be black\n";


    deck demonstration = deck();
    cout << "Ordered Deck: \n";
    cout << demonstration;
    demonstration.shuffle();
    cout << "Shuffled Deck: \n";
    cout << demonstration;


}