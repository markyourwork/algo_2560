// YIEN WU and Padraic Burns 
// Project 3b
#pragma once

#ifndef Heap_h
#define Heap_h

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Heap
{
public:

	int parent(int i);	
	//index of the parent node
	int left(int i);	
	//index of left node
	int right(int i);	
	//infex of right node
	
	void initializeMaxHeap(std::vector<T> input);	 
	//initialize the max heap
	void maxHeapify(int i);			 
	//verify the heap
	void buildMaxHeap();	     
	//populate the max heap
	std::vector<T> heapsort();		 
	//sort the heap and return a vector

private:
	std::vector<T> heapVector;	
	//private vector to store values in the heap
	int heapSize;			
	//private int for size of the vector
};
#endif

//parent node index
template <typename T>
int Heap<T>::parent(int i)
{
	return floor((i - 1) / 2);
}

//left node index
template <typename T>
int Heap<T>::left(int i)
{
	return (i * 2) + 1;
}

//right node index
template <typename T>
int Heap<T>::right(int i)
{
	return (i * 2) + 2;
}

//node value
template <typename T>

T Heap<T>::getItem(int i)
{
	return heapVector[i];
}

// take a vector and copy as heap vector
template <typename T>
void Heap<T>::initializeMaxHeap(std::vector<T> input)
{
	heapVector = input;			
}

//create the max heap from the initialized vector
template <typename T>
void Heap<T>::buildMaxHeap()
{
	heapSize = heapVector.size() - 1;	// actual size of vector
	int i = floor(heapSize / 2);
	for (i; i >= 0; i--)
	{
		maxHeapify(i);
	}
}

//checks maxHeap properties
template <typename T>
void Heap<T>::maxHeapify(int i)
{
	int l = left(i);	//initialize l to equal the left node
	int r = right(i);	//initialize r to equal the right node
	int max = 0;

	//check if the index of the left node is less than or equal to the size of the vector and the value is greater than the value of node i
	if (l <= heapSize && heapVector[l] > heapVector[i])
	{
		max = 1;
	}
	else
	{
		max = i;
	}

	//repeat for right node
	if (r <= heapSize && heapVector[r] > heapVector[max])
	{
		max = r;
	}
	if (max != i)
	{
		swap(heapVector[i], heapVector[max]);
		maxHeapify(max);
	}
}

template <typename T>
std::vector<T> Heap<T>::heapsort()
{
	buildMaxHeap();

	//check for max heap
	for (int i = heapVector.size() - 1; i >= 1; i--)
	{
		swap(heapVector[0], heapVector[i]);

		//change size of heap vector to keep it in place
		heapSize--;

		//run max again from starting node
		maxHeapify(0);
	}

	return heapVector;
}