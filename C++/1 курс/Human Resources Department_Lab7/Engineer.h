#ifndef B
#define B
#include"Employee.h"
#include"Heading.h"
#endif
using namespace employee;
namespace engineer
{
	class Engineer:public Employee
	{
	public:
		Engineer(){}
		virtual void WorkTime();
		virtual void Project(int);
		virtual void contration(int ,int ,int ); 
	protected:
		int rate;// ставка в час
		double personal_contr; // персональный вклад
		int budget_of_project;
		string project;
	};
	class Programmer:public Engineer
	{
	public:		
		virtual void calc();
		Programmer(string id = "",string fio = "",string position = "",string project = "",int rate = 0,int worktime = 0,int budget_of_project = 0)
			{
				this->id = id;
				this->fio = fio;
				this->worktime = worktime;
				payment = 0;
				this->rate = rate;
				this->position = position;
				this->budget_of_project =  budget_of_project;
				this->project = project;
			}
	};
	class Tester:public Engineer
	{
	public:
		void calc();
		Tester(string id = "",string fio = "",string position = "",string project = "",int rate = 0,int worktime = 0,int budget_of_project = 0)
			{
				this->id = id;
				this->fio = fio;
				this->worktime = worktime;
				payment = 0;
				this->rate = rate;
				this->position = position;
				this->budget_of_project =  budget_of_project;
				this->project = project;
			}
	};
	class TeamLeader : public Programmer,public Heading
	{
	public:
		void calc();
		TeamLeader(string id = "",string fio = "",string position = "",string project = "",int rate = 0,int worktime = 0,int budget_of_project = 0)
			{
				this->id = id;
				this->fio = fio;
				this->worktime = worktime;
				payment = 0;
				this->rate = rate;
				this->position = position;
				this->budget_of_project =  budget_of_project;
				this->project = project;
			}
		void heading();
		void contration(int ,int ,int );
	private:
		static const int rate_for_people = 1000;
	};
}