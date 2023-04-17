#pragma once
#include "Process.h"
#include "LinkedList.h"
#include"Node.h"
#include"LinkedQueue.h"
#include"Queue.h"
#include<string>
#include "Scheduler.h"
class Processor
{
protected:
	Process* Run;
	int ID; //setter and getter?
	bool SchedulingState; //idle is 0 and busy is 1
	//int TotalRurnAroundTime;//total time the processor is working till it'
	int ProcessorBusyTime;//total time the processor is actually busy
	float PLoad;
	float PUtil;
	int FinishTime; //same as turnaround time?
	int RDYCount;
	string name; //returns typename and order of processor
	Scheduler* p;
	//expected finish time?document page 6
public:
	Processor();
	virtual void SchedulingAlgo() = 0;
	virtual void EnqueueReady(Process p) = 0; //same as add process  NOT pure virtual it's the same implementation in all?
	virtual void MoveToRun() = 0; //what process will i give it
	virtual void setSchedulingState(bool u); //sets the processor running state
	virtual string getName()=0;
	bool getSchedulingState(); //returns the processor's running state
	int getFinishTime(); //allowed?
	int getRDYCount(); //give it as a parameter to enqueueready by reference
	void IncrementRDY();
	void setID(int x);
	 virtual void PrintRDY() = 0;
	//virtual void DeleteProcess(Process p) = 0; //deletes a process after it moves it to termination or BLK ???
	//do i have a copy of the process to delete it?
	Process* getRun(); //gets the process that's running
	void setRun(Process*r);
	
	
};

