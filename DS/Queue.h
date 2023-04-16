#pragma once
template <class T>
class Queue
{
public:
	virtual bool isEmpty() const = 0;
	virtual bool enqueue(const T& newEntry) = 0;
	virtual bool dequeue(T& FrontEntry) = 0;
	virtual bool peek(T& FrontEntry) const = 0;
	virtual T print() const =0;
	virtual ~Queue()
	{}
};
