//Padraic Burns and yien wu 
//Project 3b
//Header for Dictionary Class

#pragma once
#ifndef Dictionary_h
#define Dictionary_h

#include <vector>
#include <string>

class Dictionary
{
private:
	std::vector<std::string> wordList;

public:
	Dictionary(std::string fileName);
	friend std::ostream& operator<< (std::ostream& ostr, const std::vector<std::string> wL);
	void selectionSort();
	int binarySearch(std::string key);
};
#endif Dictionary_h