#pragma once
#include "LinkedQueue.h"
#include"Processor.h"
#include "RR_Processor.h"
#include "FCFS_Processor.h"
#include "SJF.h"
class Scheduler
{
private:
	LinkedQueue<Process> New;
	LinkedQueue<Process> BLK;
	LinkedQueue<Process> TRM; //queue? //order doesnt matter so linked list
	//is trm number in order?
	Processor**processor;
	int BLKCount;
	int TRMCount;
	int RUNCount;
	float StealLimit; //here?
	int TimeStep;
	int NF, NS, NR;
	int TimeSlice;
	int RTF, MaxW, STL, ForkProbability;
	//int ForkProbability;//float?
	int NumberOfProcesses; ///N???
	int  SIGKILLCount; 
	//int SIGKILL here or ui?
	//int n; //number of processors? already 3ndy
	Process** Running; 
	//array of running processors here //processes wala processors??
public:
	Scheduler();
	void AddNew(Process p);
	void MoveToRDY(int processorid); //revise
	void MoveToBLK(Process p);
	void MoveToTRM(Process b);
	void Simulate();
	void Load();
	int getTimeSlice(); //allowed???
	//LinkedQueue<Process> getNew();
	//function that fills ready?
	//function that calls finish time of each processor (loops 3alehom) then sees which time is the shortest by calculating steallimit then moving process to
	//the rdy queue of that processor , sees which queue is longest too
	//so do all this, check on steal limit, then move it
	void Stealing();
	void CreateProcessor();
	void Load();
	//void PrintBLK();
	void CreateRunningArr();//itterate on each processor and add running process to it  and increment counter
	bool IsTerminated();

};

