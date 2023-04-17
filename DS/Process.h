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
	Process(int id=0, int at=0, int rt=0, int ct=0, int tt=0);
	int getPID();
	int getAT();
	int getRT();
	int getCT();
	int getTT();
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
	/*bool operator <=(Process&  Process2);
	bool operator >=(Process& Process2);*/
};


