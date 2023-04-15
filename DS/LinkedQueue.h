#pragma once
#include "Node.h"
#include "Queue.h"
#include <vector>
using namespace std;

template <typename T >
class LinkedQueue :public Queue<T>
{
private:
	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frontEntry);
	bool peek(T& frontEntry) const;
	T print();
	~LinkedQueue();
	LinkedQueue(const LinkedQueue<T>& LQ);

};


template <typename T >
LinkedQueue<T>::LinkedQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;
}

template <typename T >
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

template <typename T >
bool LinkedQueue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	if (isEmpty())
		frontPtr = newNodePtr;
	else
		backPtr->setNext(newNodePtr);
	backPtr = newNodePtr;
	return true;
}

template <typename T >
bool LinkedQueue<T>::dequeue(T& frontEntry)
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

template <typename T >
bool LinkedQueue<T>::peek(T& frontEntry) const
{
	if (isEmpty())
		return false;
	frontEntry = frontPtr->getItem();
	return true;
}

template <typename T>
T LinkedQueue <T> ::print()
{
	T Q;
	cout << "Linked Queue contents:";
	while (dequeue(Q))
		cout << Q<< " ";
	cout << endl;
	return 0;
}

template <typename T >
LinkedQueue<T>::~LinkedQueue()
{
	T temp;
	while (dequeue(temp));
}
template <typename T >
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& LQ)
{
	Node<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr)
	{
		frontPtr = backPtr = nullptr;
		return;
	}
	Node<T>* ptr = new Node<T>(NodePtr->getItem());
		frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();

	while(NodePtr)
	{
		Node<T>* ptr = new Node<T>(NodePtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePtr = NodePtr->getNext();

	}
}