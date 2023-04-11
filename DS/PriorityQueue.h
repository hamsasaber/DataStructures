#pragma once
#include "Node.h"
#include "Queue.h"
#include "LinkedQueue.h"
#include <vector>
using namespace std;

template <typename T>
class PriorityQueue : public Queue <T>
{
public:
	Node<T>* frontPtr;
	Node<T>* backPtr;
	int priority;
	PriorityQueue()
	{
		backPtr = nullptr;
		frontPtr = nullptr;
	}
	bool enqueue(const T& newEntry, int value)
	{
		Node<T>* newNodePtr = new Node<T>(newEntry);
		Node* ptr;
		ptr = new Node;
		newNodePtr->setItem = newEntry;
		newNodePtr->priority = value;
		if (frontPtr == NULL || priority <= frontPtr->priority)
		{
			newNodePtr->getnext() = frontPtr;
			frontPtr = newNodePtr;
		}
		else
		{
			ptr = frontPtr;
			while (ptr->getnext() && priority >= ptr->priority)
				ptr = ptr->getnext();
			newNodePtr->getnext() = ptr->getnext();
			ptr->getnext() = newNodePtr;
		}
	}
	bool dequeue(const T& frontEntry)
	{
		if (isEmpty())
			return false;
		Node<T>* nodeToDeletePtr = frontPtr;
		frontEntry = frontPtr->getItem();
		frontPtr = frontPtr->getNext();

		if (nodeToDeletePtr == backPtr)
			backPtr = nullptr;
		delete nodeToDeletePtr;
		return true;
	}
	bool peek(T& frontEntry) const
	{
		if (isEmpty())
			return false;
		frontEntry = frontPtr->getItem();
		return true;
	}
	T print(PriorityQueue <T> Q)
	{
		T Pq;
		cout << "Priority Queue contents:";
		while (Q.dequeue(Pq))
			cout << Pq << " ";
		cout << endl;
	}
	~PriorityQueue()
	{
		T temp;
		while (dequeue(temp));
	}

};
