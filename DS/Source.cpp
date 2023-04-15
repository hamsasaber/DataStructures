#include <iostream>
using namespace std;
#include "LinkedQueue.h"
#include "Queue.h"
#include "Node.h"


int main()
{
	LinkedQueue<int > Q;
	int x;
	
	cout << "testing Q:" << endl;
	cout << "inserting 5 values into Q:" << endl;

	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		Q.enqueue(x);
	}
	cout << "print funtion" << endl;
	Q.print();
	return 0;
}