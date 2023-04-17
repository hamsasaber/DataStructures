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
	SchedulingState=u;
}

bool Processor::getSchedulingState()
{
	return SchedulingState;
}


int Processor::getFinishTime()
{
	return FinishTime;
}

int Processor::getRDYCount()
{
	return RDYCount;
}

void Processor::IncrementRDY()
{
	RDYCount++;
}

void Processor::setID(int x)
{
	ID = x;
}

Process* Processor::getRun()
{
	if (Run != NULL)
	{
		return Run;
	}
}

void Processor::setRun(Process*r)
{
	Run = r;
}

int Processor::GetRDY()
{
	return ID;
}


