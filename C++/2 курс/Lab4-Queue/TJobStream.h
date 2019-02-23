#pragma once
const int MaxRange = 100000;
class TJobStream
{
	double chanceNewTask;
	double chanceCompleteTask;
public:
	TJobStream(double, double);
	bool GenerateNewTask();
	bool ComleteTask();
};
