#include "Process.h"
template <typename T>
Process<T>::Process(int id, int at, int rt, int ct, int tt)
{
	PID = id;
	AT = at;
	RT = rt;
	CT = ct;
	TT = tt;
}
template <typename T>
int Process<T>::getPID() { return PID; }
template <typename T>
int Process<T>::getAT() { return AT; }
template <typename T>
int Process<T>::getRT() { return RT; }
template <typename T>
int Process<T>::getCT() { return CT; }
template <typename T>
int Process<T>::getTT() { return TT; }
template <typename T>
void Process<T>::seti_o(T i_o) { i_o = I_O; }
template <typename T>
int Process<T>::geti_o() { return I_O; }
template <typename T>
void Process<T> ::setTRT()
{
	TRT = TT - AT;
}
template <typename T>

int Process<T>::getTRT()
{
	return TRT;
}
template <typename T>

void Process<T>::setWT()
{
	WT = TRT - CT;
}
template <typename T>

int Process<T>::getWT()
{
	return WT;
}
template <typename T>

void Process<T>::setNEW(bool a)
{
	a = true;
}
template <typename T>

bool Process<T>::getNEW()
{}
template <typename T>

void Process<T>::setRDY(bool b)
{
	b = false;
}
template <typename T>

bool Process<T>::getRDY()
{}
template <typename T>

void Process<T>::setRUN(bool c)
{
	c = false;
}
template <typename T>

bool Process<T>::getRUN()
{}
template <typename T>

void Process<T>::setBLK(bool d)
{
	d = false;
}
template <typename T>

bool Process<T>::getBLK()
{}
template <typename T>

void Process<T>::setTRM(bool e)
{
	e = false;
}
template <typename T>

bool Process<T>::getTRM()
{}
template <typename T>

void Process<T>::setORPH(bool f)
{
	f = false;
}
template <typename T>

bool Process<T>::getORPH()
{}