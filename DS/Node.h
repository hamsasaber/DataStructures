#pragma once
template <typename T>
class Node
{
private:
	T item;
	T priority;
	Node<T>* next;
public:
	Node();
	Node(const T& r_Item);
	Node(const T& r_Item, Node<T>* nextNodePtr);
	void setItem(const T& r_Item);
	void setNext(Node<T>* nextNodePtr);
	void setpriority(const T& value);
	T getItem() const;
	T getpriority();

	Node<T>* getNext() const;

};

template <typename T>
Node<T> ::Node()
{
	next = nullptr;
}

template <typename T>
Node<T>::Node(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
}

template<typename T>
Node<T>::Node(const T& r_Item, Node<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}

template <typename T>
void Node<T>::setItem(const T& r_Item)
{
	item = r_Item;
}
template <typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template <typename T>
void Node<T>::setpriority(const T& value)
{
	priority = value;
}

template<typename T>
T Node<T>::getItem() const
{
	return item;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
}

template <typename T>
T Node<T>::getpriority()
{
	return priority;
}