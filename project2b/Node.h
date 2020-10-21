// YIEN WU and Padraic Burns 
// Project 2b
// Header for Node class


#ifndef NODE_CLASS
#define NODE_CLASS
#ifndef NULL
#endif  

// linked list node
template <typename T>
class Node
{
public:
	T nodeValue;      // data held by the node
	Node<T>* next;    // next node in the list


	Node() : next(NULL)
	{}


	Node(const T& item, Node<T>* nextNode = NULL) :
		nodeValue(item), next(nextNode)
	{}
};

#endif   