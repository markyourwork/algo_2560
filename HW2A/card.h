//Padraic Burns and Yi-En Wu, Problem Set 1

#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std; 

class card
{
public:
string suit;
string color;
int value;
//creates a random card
card();
//creates a specified card
card(string s, int v);

void setValue();
void setSuit();

int getValue() const;
string getSuit() const;
string getColor() const;

friend ostream& operator<<(ostream& dealer, const card& c);

private:
void setColor();
};

card ::card()
{
value = 1;
suit = "CLUBS";
this->setColor();
}
card::card(string s, int v)
{
value = v;
suit = s;
this->setColor();
}
void card::setColor()
 {
     if(this->suit == "HEARTS"||this->suit == "DIAMONDS")
        this->color = "red";
     else
     {
        this->color = "black";
     }
 }
void card::setValue()
{
    srand(time(0));
    this->value = rand() % 13 +1;
}
void card::setSuit()
{
srand(time(0));
int hold = rand() % 4 + 1;
switch (hold)
{
    case 1:
      this->suit = "CLUBS";
      break;
    case 2:
      this->suit = "DIAMONDS";
      break;
    case 3:
      this->suit = "HEARTS";
      break;
    case 4:
      this->suit = "SPADES";
      break;
}   
}
int card::getValue() const
{
    return this->value;
}
string card::getSuit() const
{
    return this->suit;
}
string card::getColor() const
{
    return this->color;
}
ostream& operator<<(ostream& dealer, const card& c)
{
  string name;
  if(c.getValue()>10)
  {
    if(c.getValue()==11)
    {
      name = "Jack";
    }
    else if(c.getValue()==12)
    {
      name = "Queen";
    }
    else if(c.getValue()==13)
    {
      name = "Ace";
    }
  }
  else{
    name = c.getValue();
  }
  dealer << name << " of " << c.getSuit();
  return dealer;
}
