#include "Scheduler.h"
#include"Processor.h"
#include"LinkedQueue.h"
#include<fstream>

Scheduler::Scheduler()
{
    //fill new
    TimeSlice = 0;
    TimeStep = 0; //starts from 1??
    //loaded from input file
    processor = new Processor * [NF + NS + NR]; //revise dynamic allocation
    Running = new Process * [RUNCount];
    //array of pointers to processors?
}

void Scheduler::MoveToRDY(Process p)
//need process count? for loop or while?
//corner cases?
//shortest queue thing???
{
    while (!New.isEmpty())
    {
        New.dequeue(p); //????
        for (int i = 0; i <= (NF + NS + NR); i++)
        {
            if (!New.isEmpty())
            {
                processor[i]->EnqueueReady(p); //how are they distributed amongst the 3 processors??
            }
        }
    }
    //New.dequeue(); what is it's parameter i simply want it to dequeue it's first element**
}

void Scheduler::MoveToBLK(Process a)
{
    BLK.enqueue(a);
}

void Scheduler::MoveToTRM(Process b)
{
    TRM.enqueue(b);
}

void Scheduler::Simulate()
{

}

int Scheduler::getTimeSlice()
{
    return TimeSlice;
}

//LinkedQueue Scheduler::getNew()
//{
    //return Queue();
//}

void Scheduler::Stealing()
{

}

void Scheduler::CreateProcessor()
{
    for (int i = 0; i < NF; i++)
    {
        FCFS_Processor P1;
        processor[i] = &P1;
    }
    for (int i = NF; i < NS; i++)
    {
        SJF P2;
        processor[i] = &P2;
    }
    for (int i = NS; i < NR; i++)
    {
        RR_Processor P1;
        processor[i] = &P1;
    }

}

void Scheduler::Load()
{
    ifstream Input;
    Input.open("ReadMe.txt", ios::in);
    if (Input.is_open())
    {
        Input >> NF >> NS >> NR;
        Input >> TimeSlice;
        Input >> RTF >> MaxW >> STL >> ForkProbability;
        Input >> NumberOfProcesses;
    }
    if (Input.is_open())
    {
        for (int j = 1; j <= NumberOfProcesses; j++)
        {
            //Input >> AT >> PID >> CT >> N;
            /*for (int i = 0; i <= N; i++)
            {
                Input.ignore(1);
                Input >> IO_R[i]; Input.ignore(1);
                Input >> IO_D[i];  Input.ignore(1);
            }*/
        }
        for (int y = 1; y <= NumberOfProcesses; y++)
        {
            //cout << AT << " " << PID << " " << CT << " " << N << '\n';
            /*for (int k = 0; k < N; k++)
            {
                cout << "(" << IO_R[k] << "," << IO_D[k] << ")" ;
            }
            cout << endl;*/
        }

    }
    while (Input >> num1)
    {
        Input >> num2; //input pid of which of the processes i created?or create new process?
    }
    Input.close();
    //Input_.close();
    //else???
}

//void Scheduler::PrintBLK()
//{
//    BLK.print(BLK);
//}

void Scheduler::CreateRunningArr()
{
    for (int i = 0; i < (NF + NS + NR); i++)
    {
        if (processor[i]->getRun() != NULL)
        {
            Running[i] = processor[i]->getRun();
        }
    }
}