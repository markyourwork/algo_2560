#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Code.h"

class Response
{
private:
	int numberCorrect;
	int numberIncorrect;


public:
	Response(Code guessCode, Code answerCode);
	Response();

	void setCorrect(Code guessCode, Code answerCode);
	void setIncorrect(Code guessCode, Code answerCode);
	int getCorrect();
	int getIncorrect();

	friend bool operator== (Response lhs, Response rhs);
	friend std::ostream& operator<< (std::ostream& ostr, Response r);


};

Response::Response(Code guessCode, Code answerCode)
//response object Constructor. 
{
	setCorrect(guessCode, answerCode);
	setIncorrect(guessCode, answerCode);
}

Response::Response()
//Default Response object Constructor
{
	numberCorrect = 0;
	numberIncorrect = 0;
}

void Response::setCorrect(Code guessCode, Code answerCode)
//set value of numberCorrect
{
	numberCorrect = answerCode.checkCorrect(guessCode);
}

void Response::setIncorrect(Code guessCode, Code answerCode)
//set value of numberIncorrect
{
	numberIncorrect = answerCode.checkIncorrect(guessCode);
}

int Response::getCorrect()
//get the value of numberCorrect
{
	return numberCorrect;
}

int Response::getIncorrect()
//get the value of numberIncorrect
{
	return numberIncorrect;
}

bool operator== (Response lhs, Response rhs)
{
	if (lhs.getCorrect() == rhs.getCorrect() &&
		lhs.getIncorrect() == rhs.getIncorrect())
		return true;
	else
		return false;
}

std::ostream& operator<< (std::ostream& ostr, Response r)
{
	ostr<< "Number digits in right place: " << r.getCorrect()
		<<"; Number digits in wrong place: "<< r.getIncorrect();
	return ostr;
}

