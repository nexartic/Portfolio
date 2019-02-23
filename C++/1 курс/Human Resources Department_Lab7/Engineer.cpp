#include "Engineer.h"
namespace engineer
{
	void Engineer::WorkTime()
	{
		payment += worktime*rate;
	}
	void Engineer::Project(int budget)
	{
		payment += budget*personal_contr;
	}
	void Programmer::calc()
	{
		Project(budget_of_project);
		WorkTime();
	}
	void Tester::calc()
	{
		Project(budget_of_project);
		WorkTime();
	}
	void TeamLeader::heading()
	{
		payment += rate_for_people*amount_people;
	}
	void TeamLeader::calc()
	{
		Project(budget_of_project);
		WorkTime();
		heading();
	}
	void Engineer::contration(int mail,int intel,int steam)
	{
		if(project == "mail")
			personal_contr = 1.0/mail;
		if(project == "intel")
			personal_contr = 1.0/intel;
		if(project == "steam")
			personal_contr = 1.0/steam;
	}
	void TeamLeader::contration(int mail,int intel,int steam)
	{
		if(project == "mail")
		{
			personal_contr = 1.0/mail;
			amount_people = mail-1;
		}
		if(project == "intel")
		{
			personal_contr = 1.0/intel;
			amount_people = intel-1;
		}
		if(project == "steam")
		{
			personal_contr = 1.0/steam;
			amount_people = steam-1;
		}
	}
}