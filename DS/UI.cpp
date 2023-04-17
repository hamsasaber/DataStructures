#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include "UI.h"
using namespace std;


UI::UI()
{

}


void UI::InteractivePrint(int T, Processor** arr, int NF, int NS, int NR, LinkedQueue<Process>BLK, int BLKCount, LinkedQueue<Process>TRM, int TRMCount, int RUNCount, Process** Running)
{
	cout << "Current Timestep :" << T << endl;
	cout << "--------------------     RDY processes     --------------------" << endl;
	for (int i = 0; i < NF; i++)
	{
		cout << "processor " << i << " [FCFS]: ";
		cout << arr[i]->getRDYCount() << "RDY: ";
		arr[i]->GetRDY();
		cout << endl;
	}
	for (int i = NF; i < (NS + NF); i++)
	{
		cout << "processor " << i << " [SJF]: ";
		cout << arr[i]->getRDYCount() << "RDY: ";
		arr[i]->GetRDY();
		cout << endl;
	}
	for (int i = NS; i < (NR + NS + NF); i++)
	{
		cout << "processor " << i << " [RR]: ";
		cout << arr[i]->getRDYCount() << "RDY: ";
		arr[i]->GetRDY();
		cout << endl;
	}

	cout << "--------------------     BLK processes     --------------------" << endl;
	cout << BLKCount;
	cout << " BLK: ";
	BLK.print();
	cout << endl;
	cout << "--------------------     RUN processes     --------------------" << endl;
	cout << RUNCount;
	cout << "RUN: ";
	for (int i = 0; i < (NF + NS + NR); i++)
	{
		if (arr[i]->getRun() != NULL)
		{
			cout << arr[i]->getRun()->getPID() << arr[i]->getName();
		}
		if (i = RUNCount - 1)
		{
			cout << "";//break?
		}
		else
			cout << ",";

	}
	for (int i = 0; i < RUNCount; i++)
	{
		cout << Running[i]->getPID();  //last one will print, so use an if condition to stop that //need process to remove error
		if (i = RUNCount - 1)
		{
			cout << "";//break?
		}
		else
			cout << ",";
	}
	cout << endl;
	cout << "--------------------     TRM processes     --------------------" << endl;
	cout << TRMCount;
	TRM.print();
	cout << endl;
	cout << "PRESS ENTER TO MOVE TO NEXT STEP!";//enter
	while (1)
	{
		char x;
		cin >> x;
		if (x == '\n')
		{
			break;
		}
	}
}

void UI::SilentPrint()
{
	//same as interactive without the last line
}

void UI::StepByStepPrint()
{
	cout << "Silent Mode.........       Simulation Starts....." << endl << "Simulation ends, Output file created";
}