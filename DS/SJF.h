#pragma once
#include "Processor.h"
#include "PriorityQueue.h"
#include<string>
class SJF :
    public Processor
{
private:
    PriorityQueue<Process> RDY_SJF;
public:
    SJF();
    void SchedulingAlgo();
    void EnqueueReady(Process p, int CT);
    void MoveToRun(Process a); 
    void PrintRDY(Process p);
    string getName();
};
