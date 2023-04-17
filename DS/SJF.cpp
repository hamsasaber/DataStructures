#include "SJF.h"
#include "Processor.h"
#include <iostream>

SJF::SJF()
{

}
void SJF::SchedulingAlgo()
{

}

void SJF::EnqueueReady(Process p, int CT)
{
	RDY_SJF.enqueue(p, CT);
	RDYCount++;
}

void SJF::MoveToRun(Process p)
{
	
	if (RDY_SJF.peek(p) == false)
	{
		cout << "RDY is empty";
	}
	else
	{
		RDY_SJF.dequeue(p);
		Run = &p;
		SchedulingState = true;
	}
}
string SJF::getName()
{
	string n = "SJF_P";
	return n;
}

void SJF::dequeueRDY(Process p)
{
	RDY_SJF.dequeue(p);
}

