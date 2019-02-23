#include"TProc.h"
#include<iostream>
#include<ctime>
using namespace std;


void TProc::Print()
{
	cout << "Program result:" << endl;
	cout << "Work time simulation : " << timeExperiment << " tact"<<endl;
	cout << "Number of tasks resived = " << countTask << endl;
	cout << "Number of tasks canceled = " << countCancel <<"%"<< endl;
	cout << "Medium work time = " << mediumWorkTime <<" tact"<< endl;
	cout << "Number of processor downtime = " << countStopTact <<"%"<< endl;
}

TProc::TProc()
{

	timeExperiment = 1000000;
	countTask = 0;
	countCancel = 0;
	mediumWorkTime = 0;
	countStopTact = 0;
};

void TProc::WorkSystem()
{
	int size = 10;
	TQueue queue(size);
	TJobStream job(0.5, 0.5);
	float countGenerateTask = 1;

	for (int i = 0; i<timeExperiment;i++)
	{
	 if (job.GenerateNewTask())
	 {
		countGenerateTask+=1;
		if (queue.IsFull())
		{
			countCancel++;
		}
		else
		{
			queue.Put(1);
			countTask++;
		}
	 }

		if (job.ComleteTask())
		{
			
			if (queue.IsEmpty())
			{
				countStopTact++;
			}
			else
			{
				queue.Get();
			}
		}


	}
	countStopTact = (countStopTact / timeExperiment) * 100;
	mediumWorkTime = timeExperiment/ countTask;
	countCancel = countCancel / countGenerateTask * 100;
}