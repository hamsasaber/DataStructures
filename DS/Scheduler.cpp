#include "Scheduler.h"
#include"Processor.h"
#include"LinkedQueue.h"
#include<fstream>

Scheduler::Scheduler()
{
    //fill new
    TimeSlice = 0;
    TimeStep = 1; //starts from 1??
    //loaded from input file
    processor = new Processor * [200]; //revise dynamic allocation
    Running = new Process * [RUNCount];
    //array of pointers to processors?
}

void Scheduler::AddNew(Process p)
{
    New.enqueue(p);
}

void Scheduler::MoveToRDY(int Processorid)
//need process count? for loop or while?
//corner cases?
//shortest queue thing???
{
    Process temp;
    //while (!New.isEmpty())
    //{
    if (!New.isEmpty())
    {
        New.peek(temp);
        if (temp.getAT() == TimeStep)
        {
            New.dequeue(temp); //????
            //for (int i = 0; i <= (NF + NS + NR); i++)
           // {
                //if (!New.isEmpty())
                //{
            processor[Processorid]->EnqueueReady(temp); //how are they distributed amongst the 3 processors??
        //}
   // }
        }
    }
    //}
    //New.dequeue(); what is it's parameter i simply want it to dequeue it's first element****
}

void Scheduler::MoveToBLK(Process p)
{
    //enqueue pointers not objects
   // if(processor[id]->getRun()!=NULL)
    BLK.enqueue(p);
}

void Scheduler::MoveToTRM(Process b)
{
    TRM.enqueue(b);
}

void Scheduler::Simulate()
{
    Load();
    //fill new list of processes in load after creating them.
    CreateProcessor();
    int count = 0; //for processorid in movetordy function
    while (!IsTerminated) {
        for (int i = 0; i < NumberOfProcesses; i++)
        {
            MoveToRDY(count);
            count++;
            if (count == NF + NS + NR)
            {
                count = 0;
            }
        }
        for (int j = 0; j < (NF + NS + NR); j++)
        {
            if (processor[j]->getRun() != NULL)
                return;
            processor[j]->MoveToRun();
        }
        for (int i = 0; i < (NF + NS + NR); i++)
        {
            if (processor[i]->getRun() != NULL) 
            {
                if (processor[i]->getRun()->getCT() == 0)
                {
                    MoveToTRM(*processor[i]->getRun());
                    processor[i]->setRun(NULL);
                    processor[i]->setSchedulingState(0);
                    RUNCount--;
                    TRMCount++;
                }
                srand(time(0));
                int x = (1 + (100 - 1)) * rand();
                if (1 <= x <= 15)
                {
                    MoveToBLK(*processor[i]->getRun());
                    processor[i]->setRun(NULL);
                    processor[i]->setSchedulingState(0);
                    RUNCount--;
                    BLKCount++;
                }
                if (20 <= x <= 30)
                {
                    MoveToRDY(i);
                    processor[i]->setRun(NULL);
                    processor[i]->setSchedulingState(0);
                    processor[i]->IncrementRDY();
                }
                if (50 <= x <= 60)
                {
                    MoveToTRM(*processor[i]->getRun());
                    processor[i]->setRun(NULL);
                    processor[i]->setSchedulingState(0);
                }
                if (processor[i]->getRun() != NULL)
                {
                    //processor[i]->getRun()->//DecrementCPUTime(); function in process
                }
            }
            srand(time(0));
            int Probability = (1 + (100 - 1)) * rand(); //iv
            if (Probability < 10)
            {
                Process temp; //?
                BLK.dequeue(temp);
                srand(time(0));
                int x = (0 + ((NF+NS+NR) - 0)) * rand();
                processor[x]->EnqueueReady(temp);
                BLKCount--;
                processor[x]->IncrementRDY();
            }
            
           
            
        }
        TimeStep++;
    }
    //    int numNewProcesses = generateRandomNumber();
    //    for (int i = 0; i < numNewProcesses; i++) {
    //        Process* newProcess = new Process(getchildID(), timestep);
    //        addToNewList(newProcess);
    //        incrementchildID();
    //    }

    //    // Add processes from the new list to the ready lists
    //    addProcessesToReadyLists(timestep);

    //    // Check for any blocked processes that have completed their I/O operations
    //    checkBlockedProcesses(timestep);

    //    // Schedule processes for execution
    //    scheduleProcesses(timestep);

    //    // Print the current state of the system
    //    cout << "Timestep " << timestep << ":" << endl;
    //    cout << "============================================" << endl;
    //    printProcessorList();
    //    printReadyLists();
    //    printBlockedList();
    //    printTerminatedList();
    //    cout << "============================================" << endl << endl;

    //    timestep++;

    //    // Check if all processes have terminated
    //    allIsTerminated = checkAllProcessesTerminated();
    //}
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
        P1.setID(i + 1);
        processor[i] = &P1;

    }
    for (int i = NF; i < NS+NF; i++)
    {
        SJF_Processor P2;
        processor[i] = &P2;
    }
    for (int i = NS; i < NR+NF+NS; i++)
    {
        RR_Processor P1;
        P1.setID(i+1);
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

bool Scheduler::IsTerminated()
{
    if (NumberOfProcesses == TRMCount)
    {
        return true;
    }
    else
        return false;
}
