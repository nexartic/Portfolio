#include<random>
#include<iostream>
#include"TJobStream.h"
using namespace std;

TJobStream::TJobStream(double newTask, double completeTask)
{
	if (newTask < 1 && newTask>0 && completeTask > 0 && completeTask < 1)
	{
		chanceNewTask = newTask * MaxRange;
		chanceCompleteTask = completeTask * MaxRange;
	}
	else
	{
		chanceCompleteTask = 0.5;
		chanceNewTask = 0.5;
	}
}

bool TJobStream::ComleteTask()
{
	random_device rand;

	if (rand() % (MaxRange + 1) <= chanceCompleteTask)
		return true;
	return false;
}

bool TJobStream::GenerateNewTask()
{
	random_device rand;

	if (rand() % (MaxRange + 1) <= chanceNewTask)
		return true;
	return false;
}