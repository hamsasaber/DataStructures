#include "Processor.h"
#include"LinkedList.h"
#include"Queue.h"
#include<string>

class FCFS_Processor :public Processor
{
private:
	LinkedList<Process*>* RDY;
	Process*RUN;

	Queue<NodeI_O> kill;
public:
	FCFS_Processor();
	void SchedulingAlgo();
	void EnqueueReady(Process p);
	void MoveToRun();
	void PrintRDY();
	string getName();
	void CheckandKill();
	void Forking();

};