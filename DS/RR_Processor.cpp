#include "RR_Processor.h"

RR_Processor::RR_Processor()
{
//initialize run??
}


void RR_Processor::SchedulingAlgo()
{
}
void RR_Processor::EnqueueReady(Process p)
{
	//by reference?
	RDY.enqueue(p); //function in queue takes it by reference?
	RDYCount++;
}

void RR_Processor::MoveToRun(Process a)
{
	if (!RDY.isEmpty())
	{
		RDY.dequeue(a);
		Run = &a;
		SchedulingState = true;
	}
}

void RR_Processor::PrintRDY()
{
	RDY.print();
}

string RR_Processor::getName()
{
	string n = "RR_P";
	return n;
}