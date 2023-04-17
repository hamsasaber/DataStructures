#include "Process.h"
Process::Process(int id, int at, int rt, int ct, int tt)
{
	PID = id;
	AT = at;
	RT = rt;
	CT = ct;
	TT = tt;
}
int Process::getPID() { return PID; }
int Process::getAT() { return AT; }
int Process::getRT() { return RT; }
int Process::getCT() { return CT; }
int Process::getTT() { return TT; }
void Process::seti_o(int i_o) { i_o = I_O; }
int Process::geti_o() { return I_O; }

void Process ::setTRT()
{
	TRT = TT - AT;
}

int Process::getTRT()
{
	return TRT;
}


void Process::setWT()
{
	WT = TRT - CT;
}


int Process::getWT()
{
	return WT;
}

void Process::setNEW(bool a)
{
	a = true;
}


bool Process::getNEW()
{}

void Process::setRDY(bool b)
{
	b = false;
}


bool Process::getRDY()
{}


void Process::setRUN(bool c)
{
	c = false;
}

bool Process::getRUN()
{}


void Process::setBLK(bool d)
{
	d = false;
}

bool Process::getBLK()
{}

void Process::setTRM(bool e)
{
	e = false;
}


bool Process::getTRM()
{}

void Process::setORPH(bool f)
{
	f = false;
}

bool Process::getORPH()
{}