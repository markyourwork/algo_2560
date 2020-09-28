//Padraic Burns and Yi-En Wu, Problem Set 2
//this file include$ all of the code inside of the mastermind game
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std; 


class Response 
{
//
    public: 

    Response(); 

    void setCorrect(int x); 
    void setIncorrect(int y); 

    int getCorrect();
    int getIncorrect(); 
    void printCode(vector <int> c0de)
//prints a given code, useful for debugging
{
    for(int i = 0; i < c0de.size(); i++)
        cout << c0de[i]<<", ";
}
     private: 

     int numCorrect; 
     int numIncorrect; 
};


Response::Response()
{
int numCorrect = 0; 
int numIncorrect = 0; 
}

void Response::setCorrect(int x)
{
//cout << "enter a number" << endl; 
//cin >> x; 
numCorrect = x; 
}

void Response::setIncorrect(int y)
{
numIncorrect = y;     
}

int Response::getCorrect()
{
    return numCorrect; 
}

int Response::getIncorrect()
{
    return numIncorrect; 
}

