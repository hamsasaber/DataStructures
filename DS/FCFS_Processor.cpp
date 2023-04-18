#include "FCFS_Processor.h"
#include <iostream>
using namespace std;
FCFS_Processor::FCFS_Processor()
{}
void FCFS_Processor::SchedulingAlgo()
{}
void FCFS_Processor::EnqueueReady(Process p)
{
	RDY->InsertBeg(&p);
	setRDYCount(RDY->getCount());
}
void FCFS_Processor::MoveToRun()
{
	Process* a;
	if (!RDY->isEmpty())
	{
		RDY->DeleteNode(a);
		RUN = a;
		setSchedulingState(true);
		setRDYCount(RDY->getCount());
	}
}
void FCFS_Processor::PrintRDY()
{
	Node<Process*>* temp = RDY->getHead();
	while (temp)
	{
		cout << temp->getItem()->getPID() << "";
		temp = temp->getNext();
	}
}
string FCFS_Processor::getName()
{
	string n = "FCFS_P";
	return n;
}
void FCFS_Processor::CheckandKill()
{
	
}
void FCFS_Processor::Forking()
{

}