#include "Processor.h"

//Process* Processor::getRun()
//{
//	return nullptr;
//}

Processor::Processor()
{
	Run = nullptr;
	ID = 0;
	SchedulingState = 0;
	ProcessorBusyTime = 0;
	PLoad = 0;
	PUtil = 0;
	FinishTime = 0;
	//setting queue? its already done in class queue?
}


void Processor::setSchedulingState(bool u)
{
	u = SchedulingState;
}

bool Processor::getSchedulingState()
{
	return false;
}

void Processor::EnqueueReady(Process p)
{
}

int Processor::getFinishTime()
{
	return 0;
}

int Processor::getRDYCount()
{
	return RDYCount;
}

string getName()
{
	string n = " name";
	return n;
}