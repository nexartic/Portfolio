#include"Engineer.h"
#include"Manager.h"
#include"Personal.h"
using namespace engineer;
using namespace manager;
using namespace personal;
const int Size = 65,MAX = 150;
Employee ** create_staff(int &mail,int &intel ,int &steam )
{
	ifstream file("Employee.txt");
	if(!file)
	{
		cout<<"файл закрыт";
		file.open("Employee.txt");
	}
	else
	{
		random_device rand;
		char buf[MAX];
		Employee **staff = new  Employee*[Size];
		int index = 0;
		int slesh = 0;
		buf[0] = '1';
		int count = 0;// дл€ создание управл€ющих должностей
		string project_name;
		int rate,worktime,number_project,budget;
		while(buf[0])
		{
			slesh = 0;
			file.getline(buf,MAX);
			string bufer;
			bufer = buf;
			string id,fio,position;
			for(int i = 0; i<bufer.length(); i++)
			{
				if(bufer[i] == '|')
				{
					slesh++;
					continue;
				}
				if(slesh == 0)
					id += bufer[i];
				if(slesh == 1)
					fio += bufer[i];
				if(slesh == 2)
					position += bufer[i];
			}
			if(position == "Cleaner")
			{
				rate = 100;
				worktime = rand()%50 + 10;
				staff[index] = new Cleaner(id,fio,position,rate,worktime);
			}
			else if(position == "Driver")
			{
				rate = 150;
				worktime = rand()%50 + 10;
				staff[index] = new Driver(id,fio,position,rate,worktime);
			}
			else if(position == "Tester" || position == "Programmer")
			{
				worktime = rand()%50 + 10;
				number_project = rand()%3;
				switch(number_project)
				{
				case 0:
				   mail++;
				   rate = 80;
				   budget = 100000;
				   project_name = "mail";
				   if(position == "Tester")
					   staff[index] = new Tester(id,fio,position,project_name,rate,worktime,budget);
				   else
					   staff[index] = new Programmer(id,fio,position,project_name,rate,worktime,budget);
				   break;
				case 1:
				   intel++;
				   rate = 100;
				   budget = 120000;
				   project_name = "intel";
				   if(position == "Tester")
					   staff[index] = new Tester(id,fio,position,project_name,rate,worktime,budget);
				   else
					   staff[index] = new Programmer(id,fio,position,project_name,rate,worktime,budget);
				   break;
				case 2:
				   steam++;
				   rate = 120;
				   budget = 110000;
				   project_name = "steam";
				   if(position == "Tester")
					   staff[index] = new Tester(id,fio,position,project_name,rate,worktime,budget);
				   else
					   staff[index] = new Programmer(id,fio,position,project_name,rate,worktime,budget);
				   break;
				}
			}
			else if(position == "TeamLeader" || position == "SeniorManager")
			{
				worktime = rand()%50 + 10;
				switch(count%3)
				{
				case 0:
					mail++;
					project_name = "mail";
				    budget = 100000;
					if(position == "TeamLeader")
					{
						rate = 80;
						staff[index] = new TeamLeader(id,fio,position,project_name,rate,worktime,budget);
					}
					else
					{
						staff[index] = new SeniorManager(id,fio,position,project_name,worktime,budget);
					}
					break;
				case 1:
					intel++;
					project_name = "intel";
				    budget = 120000;
					if(position == "TeamLeader")
					{
						rate = 100;
						staff[index] = new TeamLeader(id,fio,position,project_name,rate,worktime,budget);
					}
					else
					{
						staff[index] = new SeniorManager(id,fio,position,project_name,worktime,budget);
					}
					break;
				case 2:
					steam++;
					project_name = "steam";
				    budget = 110000;
					if(position == "TeamLeader")
					{
						rate = 120;
						staff[index] = new TeamLeader(id,fio,position,project_name,rate,worktime,budget);
					}
					else
					{
						staff[index] = new SeniorManager(id,fio,position,project_name,worktime,budget);
					}
					break;
				}
				count++;
			}
			else if(position == "ProjectManager")
			{
				number_project = rand()%3;
				worktime = rand()%50 + 10;
				switch(number_project)
				{
				case 0:
				   mail++;
				   budget = 100000;
				   project_name = "mail";
				   staff[index] = new ProjectManager(id,fio,position,project_name,worktime,budget);
				   break;
				case 1:
				   intel++;
				   budget = 120000;
				   project_name = "intel";
				   staff[index] = new ProjectManager(id,fio,position,project_name,worktime,budget);
				   break;
				case 2:
				   steam++;
				   budget = 110000;
				   project_name = "steam";
				   staff[index] = new ProjectManager(id,fio,position,project_name,worktime,budget);
				   break;
				}
			}
		    index++;
		}
		file.close();
	    return staff;
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	int mail = 0,intel = 0, steam = 0;
	Employee **staff = create_staff(mail,intel,steam);
	string position;
	for(int i = 0; i<Size;i++)
	{
		position = staff[i]->position;
		if(position == "Tester" || position == "Programmer" || position == "TeamLeader" || position == "SeniorManager" || position == "ProjectManager")
			staff[i]->contration(mail,intel,steam);
	}
	for(int i = 0; i<Size; i++)
	{
		staff[i]->calc();
		staff[i]->print_employee();
	}
	system("pause");
	return 1;
}