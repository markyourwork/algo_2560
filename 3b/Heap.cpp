// YIEN WU and Padraic Burns 
// Project 3b
//Heap class implementation

#include "Heap.h"
#include <fstream>

template <typename T>
Heap<T>::Heap(std::vector<std::string> wL)
{
	initializeMaxHeap(wL);
}

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
std::string Heap<T>::getItem(int i)
{
	return heapVector[i];
}

//take a vector and copy as heap vector
template <typename T>
void Heap<T>::initializeMaxHeap(std::vector<T> input)
{
	heapVector = input;
}

//create the max heap from the initialized vector
template <typename T>
void Heap<T>::buildMaxHeap()
{
	heapSize = heapVector.size() - 1;	
	// actual size of vector
	int i = floor(heapSize / 2);
	for (i; i >= 0; i--)
	{
		maxHeapify(i);
	}
}

//check maxHeap properties
template <typename T>
void Heap<T>::maxHeapify(int i)
{
	int l = left(i);	
	int r = right(i);	
	int max = 0;

	//if the index of the left node is less than or equal to the size of the vector and the value is greater than the value of node i
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

	//check heap properties for max heap
	for (int i = heapVector.size() - 1; i >= 1; i--)
	{
		swap(heapVector[0], heapVector[i]);

		//change size of heap vector to keep it in place
		heapSize--;

		//run max heapify agin from starting node 
		maxHeapify(0);
	}

	return heapVector;
}