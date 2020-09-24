//Padraic Burns and Yi-En Wu, Problem Set 1
//this file include$ all of the code required to run a mastermind game

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "mindGame.h"

using namespace std; 

int length; 
int range; 


int main ()
{

    //First need to obtain the input to create the MindGame
    cout << "Please sepecify the length of the code n " << endl; 
    cin >> length; 
    cout << "Please sepecify the range of digits m, [0,m-1] " << endl;
    cin >> range; 

    //create the mind game
    MindGame game1(length, range);
    game1.inputGuess();
    cout << "Guess Code is ";
    game1.printCode(game1.guessCode);
    
    //a while loop that check the user input and secret code
    while(game1.guessNum<10 && game1.winCond == false)
    {
        game1.inputGuess();
        if (game1.rightPosrightNum() == game1.length)
        {
            game1.winCond = true;
        }
        else
        {
            cout<<"Not Quite! Here is a hint: ("<<game1.rightPosrightNum()<<", "<<game1.wrongPosrightNum()<<")\n";
            game1.guessCode.clear();
            game1.guessNum++;
        }      
    }

    if(game1.winCond == true)
    {
        cout<<"Congrats you guessed the code!\n";
    }
    else
    {
        cout<<"You didn't guess the code :(\n";
    }
    return 0; 
}

