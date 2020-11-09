// YIEN WU and Padraic Burns 
// Project 3b
//Dictionary class definition

#include "Dictionary.h"
#include "Heap.h"
#include <vector>
#include <iostream>
#include <fstream>

Dictionary::Dictionary(std::string fileName)
//Dictionary constructor
{
	
	//Open provided Dictionary file
	std::fstream fin(fileName);

	while (fin)
	{
		std::string dictWord;
		fin >> dictWord;
		wordList.push_back(dictWord);
	}
	//wordList has all the words in the dictionary
}

std::ostream& operator<< (std::ostream& ostr, const std::vector<std::string> wL)
//to contain all the words in the wordList vector
{
	for (int i = 0; i < wL.size(); i++)
	{
		ostr << wL[i] << std::endl;
	}

	return ostr;
}

void Dictionary::selectionSort()
//to sort the words in the dictionary file from A-Z
{
	int min = 0;

	for (int i = 0; i < wordList.size() - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < wordList.size() - 2; j++)
		{
			
			if (wordList[j] < wordList[min])
			{
				min = j;
				std::cout << "wordList[min]: " << wordList[min] << std::endl;
			}
		}
		//Swap element to current index
		swap(wordList[i], wordList[min]);
	}

	//see if selection sort worked
	for (int i = 0; i < wordList.size(); i++)
	{
		std::cout << "selectionSort complete " << wordList[i] << std::endl;
	}
}

int Dictionary::binarySearch(std::string key)
//binary search to look up words in the dictionary
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

int Dictionary::partition(int left, int right)
{

	std::string pivot = wordList[right];
	int i = (left - 1); 

	for (int j = left; j <= right - 1; j++)
	{
		if (wordList[j] <= pivot)
		{
			i++; 
			swap(wordList[i], wordList[j]);
		}
	}
	swap(wordList[i + 1], wordList[right]);

	return (i + 1);
}

void Dictionary::quickSort(int left, int right)
{
	if (left < right)
	{
		int idx = partition(left, right);

		quickSort(left, idx - 1);
		quickSort(idx + 1, right);
	}
}

void Dictionary::heapSort()
{

	Heap <std::string> h;
	h.initializeMaxHeap(wordList);

	std::cout << "Start heap sort" << std::endl;

	//heap sort the word list string
	wordList = h.heapsort();
	std::cout << "Heap sort complete" << std::endl;
}

std::vector<std::string> Dictionary::getWordList()
{
	return wordList;
}