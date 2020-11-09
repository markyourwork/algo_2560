// YIEN WU and Padraic Burns 
// Project 3b
//Header for Dictionary Class
#pragma once
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
	int binarySearch(std::string key);
	int partition(int low, int high);
	void selectionSort();
	void heapSort();
	void quickSort(int low, int high);
	std::vector<std::string> getWordList();
};
#endif Dictionary_h