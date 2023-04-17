#pragma once
#include "NodeI_O.h"
#include "Queue.h"

class Process
{
private:
	int PID;
	int AT;
	int RT;
	int CT;
	int TT;
	int TRT;
	int WT;
	bool NEW;
	bool RDY;
	bool RUN;
	bool BLK;
	bool TRM;
	bool ORPH;
	Queue <NodeI_O>I_O;
public:
	Process(int id, int at, int rt, int ct, int tt);
	int getPID();
	int getAT();
	int getRT();
	int getCT();
	int getTT();
	int geti_o();
	void seti_o(T i_o);
	void setTRT();
	int getTRT();
	void setWT();
	int getWT();
	void setNEW(bool a);
	bool getNEW();
	void setRDY(bool b);
	bool getRDY();
	void setRUN(bool c);
	bool getRUN();
	void setBLK( bool d);
	bool getBLK();
	void setTRM(bool e);
	bool getTRM();
	void setORPH(bool f);
	bool getORPH();
};


