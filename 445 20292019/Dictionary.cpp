//Padraic Burns and yien wu 
//Project 3a
//Dictionary class definition

#include "Dictionary.h"
#include <fstream>
#include <iostream>

Dictionary::Dictionary(std::string fileName)
//Dictionary constructor
{

	std::fstream fin(fileName);

	while (fin)
	{
		std::string dictWord;
		fin >> dictWord;
		wordList.push_back(dictWord);
	}
	//wordList now has all the words in the dictionary
}

std::ostream& operator<< (std::ostream& ostr, const std::vector<std::string> wL)
//Build ostr to contain all the words in the wordList vector
{
	for (int i = 0; i < wL.size(); i++)
	{
		ostr << wL[i] << std::endl;
	}

	return ostr;
}

void Dictionary::selectionSort()
//Implement a selection sort to sort the words in the dictionary file from A-Z
{
	//Index of next smallest element
	int min = 0;

	for (int i = 0; i < wordList.size() - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < wordList.size()-2; j++)
		{
			//If wordList[j] is less than wordList[min]
			if (wordList[j] < wordList[min])
			{
				min = j;
				std::cout << "wordList[min]: " << wordList[min] << std::endl;
			}
		}
		//Swap min element to current index
		swap(wordList[i], wordList[min]);
	}

	//Test if selection sort worked
	for (int i = 0; i < wordList.size(); i++)
	{
		std::cout << "selectionSort complete " << wordList[i] << std::endl;
	}
}

int Dictionary::binarySearch(std::string key)
//Implement a binary search to look up words in the dictionary
//Return index in the dictionary if word is found.
//Return -1 otherwise
{
	int first = 0;
	int last = wordList.size() - 1;
	int mid;
	std::string midStr;

	while (first <= last)
	{
		mid = (first + last) / 2;
		midStr = wordList[mid];

		//If found, return true
		if (key.compare(midStr) == 0)
			return mid;
		else if (key.compare(midStr) < 0)
			last = mid - 1;
		else
			first = mid + 1;
	}

	//If not found, return false
	return -1;
}