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
	bool isEmpty()
	{
		return (frontPtr == nullptr);
	}

	bool enqueue(const T& newEntry, int value)
	{
		Node<T>* newNodeptr = new Node<T>(newEntry);
		Node<T>* ptr = new Node<T>;
		newNodeptr->setItem = newEntry;
		newNodeptr->setpriority = value;
		if (frontPtr == NULL || priority <= frontPtr->getpriority())
		{
			newNodeptr->getNext() = frontPtr;
			frontPtr = newNodeptr;
		}
		else
		{
			ptr = frontPtr;
			while (ptr->getNext() && priority >= ptr->getpriority())
			{
				ptr = ptr->getNext();
				newNodeptr->getNext() = ptr->getNext();
				ptr->getNext() = newNodeptr;
			}
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
	T print()
	{
		T Pq;
		cout << "Priority Queue contents:";
		while (dequeue(Pq))
			cout << Pq << " ";
		cout << endl;
	}
	~PriorityQueue()
	{
		T temp;
		while (dequeue(temp));
	}

};
