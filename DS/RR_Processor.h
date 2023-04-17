#pragma once
#include "Processor.h"
#include "Queue.h"
#include<string>
#include "Process.h"
class RR_Processor :public Processor
{
private:
    LinkedQueue<Process> RDY; //if it's empty, processor is idle    getter?
public:
    RR_Processor();
    void SchedulingAlgo();
    void EnqueueReady(Process p);
    void MoveToRun(Process a); //check implementation
    void dequeueRDY(Process p);
    string getName();
};