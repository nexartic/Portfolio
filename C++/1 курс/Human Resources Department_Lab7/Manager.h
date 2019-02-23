#ifndef B
#define B
#include"Employee.h"
#include"Heading.h"
#endif
using namespace employee;
namespace manager
{
	class Manager:public Employee
	{
	public:
		Manager(){}
		virtual void Project(int) = 0;
	protected:
		double personal_contr;
		int budget_of_project;
		string project;
	};
	class ProjectManager:public Manager
	{
	public:
		 ProjectManager(string id = "",string fio = "",string position = "",string project = "",int worktime = 0,int budget_of_project = 0)
		 {
			this->id = id;
			this->fio = fio;
			payment = 0;
			this->position = position;
			this->personal_contr = personal_contr;
			this->budget_of_project = budget_of_project;
			this->worktime = worktime;
			this->project = project;
		 }
		 virtual void contration(int mail,int intel,int steam);
		 void calc();
		 void Project(int);
	};
	class SeniorManager: public ProjectManager,public Heading
	{
	public:
		SeniorManager(string id = "",string fio = "",string position = "",string project = "",int worktime = 0, int budget_of_project = 0)
		{
			this->id = id;
			this->fio = fio;
			payment = 0;
			this->position = position;
			this->budget_of_project = budget_of_project;
			this->project = project;
			this->worktime = worktime;
		}
		void heading();
		void calc();
		void contration(int mail,int intel,int steam);
	private:
		static const int rate_for_people = 1100;
	};
}

