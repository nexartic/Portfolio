#pragma once
#include"TJobStream.h"
#include"TQueue.h"
class TProc
{
	int countTask;
	int countCancel;
	int mediumWorkTime;
	int countStopTact;
	float timeExperiment;
public:
	TProc();
	void WorkSystem();
	void Print();
};