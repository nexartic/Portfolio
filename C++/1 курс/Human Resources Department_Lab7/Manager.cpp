#include "Manager.h"
using namespace manager;

void ProjectManager::Project(int budget)
	{
		payment += budget*personal_contr;
	}
void ProjectManager::calc()
{
	Project(budget_of_project);
}
void SeniorManager::heading()
	{
		payment += amount_people*rate_for_people;
	}
void SeniorManager::calc()
{
	Project(budget_of_project);
	heading();
}
void ProjectManager::contration(int mail,int intel,int steam)
	{
		if(project == "mail")
		{
			personal_contr = 1.0/mail;
		}
		if(project == "intel")
		{
			personal_contr = 1.0/intel;
		}
		if(project == "steam")
		{
			personal_contr = 1.0/steam;
		}

		
	}
	void SeniorManager::contration(int mail,int intel,int steam)
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