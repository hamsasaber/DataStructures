#pragma once
#include "processor.h"
#include "Queue.h"
#include<string>
class RR_Processor :
    public Processor
{
private:
    LinkedQueue<Process> RDY; //if it's empty, processor is idle    getter?
public:
    RR_Processor();
    void SchedulingAlgo();
    void EnqueueReady(Process p);
    void MoveToRun(Process a); //check implementation
    void PrintRDY();
    string getName();
};