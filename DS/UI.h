#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Processor.h"
using namespace std;
class UI
{
private:
	int NumberOfProcesses; //scheduler??
	//sigkill????
public:
	UI();
	void InteractivePrint(int T, Processor** arr, int NF, int NS, int NR, LinkedQueue<Process> BLK, int BLKCount, LinkedQueue<Process> TRM, int TRMCount, int RUNCount, Process** Running);
	void SilentPrint();
	void StepByStepPrint();
};
