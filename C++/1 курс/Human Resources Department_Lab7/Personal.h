#ifndef B
#define B
#include"Employee.h"
#endif
using namespace employee;
namespace personal
{
	class Personal:public Employee
	{
	public:
		Personal(){}
	protected:
		int rate;
	};
	//============================
	class Cleaner:public Personal
	{
	public:
		Cleaner(string id = "",string fio = "",string position = "",int rate = 0,int worktime = 0)
		{
			this->id = id;
			this->fio = fio;
			this->worktime = worktime;
			payment = 0;
			this->rate = rate;
			this->position = position;
		}
		void calc();
	};
	//=============================
	class Driver:public Personal
	{
	public:
		Driver(string id = "",string fio = "",string position = "",int rate = 0,int worktime = 0)
		{
			this->id = id;
			this->fio = fio;
			this->worktime = worktime;
			payment = 0;
			this->rate = rate;
			this->position = position;
		}
		void calc();
	};
}

