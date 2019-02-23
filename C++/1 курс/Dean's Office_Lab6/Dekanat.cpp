#include "Dekanat.h"
const int MAX = 100;
ifstream Stud_fp("students.txt");
ifstream Gr_fp("group.txt");
ofstream Save("New Date.txt");
void Dekanat::create_ST_of_file()
{
	if(!Stud_fp.is_open())
	{
		Stud_fp.open("students.txt");
		return;
	}
	else
	{
		
		if(amount_Stud == 0)
		{
			mass_ST = new Student*[amount_Stud+1];
		}
		else
		{
		   Student** stek = new Student* [amount_Stud];
		   for(int i = 0 ; i<amount_Stud; i++)
		   {
			   stek[i] = mass_ST[i];
		   }
		   delete[] mass_ST;
		   mass_ST = new Student* [amount_Stud+1];
		   for(int i = 0 ; i<amount_Stud; i++)
		   {
			   mass_ST[i] = stek[i];
		   }
		   delete[] stek;
		}
		
		//----------------------------------------
		random_device rand;
		string fiop="",idp="";
		int space = 0;
		char buf[MAX];
		Stud_fp.getline(buf,MAX);
		int lenght = strlen(buf);
		if(buf[0] == 0)
		{
			Stud_fp.close();// если кончились студенты
			return;
		}
		for(int i = 0; i<lenght; i++)
		{
			if(buf[i]>='0' && buf[i]<='9')
			{		
			    idp+=buf[i];
			}
			else if(space == 0 && buf[i] == ' ')
			{
				space = 1;
				continue;
			}
			else
			{
				fiop+=buf[i];
			}
		}
		mass_ST[amount_Stud] = new Student(idp,fiop);
		space = rand()%15+1;// колличество оценок у студента
		for(int i = 0; i<space; i++)
		{
			mass_ST[amount_Stud]->add_mark();
		}
		amount_Stud++;
	}	
}
void Dekanat::create_GR_of_file()
{
	if(!Gr_fp.is_open())
	{
		Gr_fp.open("groups.txt");
		return;
	}
	else
	{
		char buf[MAX];
		Gr_fp.getline(buf,MAX);
		if(buf[0] == 0)
		{
			Gr_fp.close();
			return;
		}
		if(amount_groups == 0)
		{
			groups = new Group* [amount_groups+1];
		}
		else
		{
			Group **stek = new Group* [amount_groups];
			for(int i = 0; i<amount_groups; i++)
			{
				stek[i] = group[i];
			}
			delete[] group;
			group = new Groups*[amount_group+1];
			for(int i = 0; i<amount_group; i++)
			{
				groups[i] = stek[i];
			}
			delete[] stek;
		}
		groups[amount_groups] = new Group(buf);
		int z = (amount_groups)*10;
		for(int i = z; i<z+10; i++)
		{
			groups[amount_groups]->add_student(mass_ST[i],groups[amount_groups]);
		}
		amount_groups++;
	}
}
void Dekanat::statistic(STR face)
{
	if(face[0] >='0' && face[0]<='9')// Если ввели студента
	{
		for(int i = 0; i<amount_Stud; i++)
		{
			if(mass_ST[i]->id == face)
			{
				cout<<"(id-ФИО-Колличество оценок-Оценки-Средняя оценка)";
				mass_ST[i]->print_st();
				cout<<"Группа:"<<mass_ST[i]->gr->Title;
			}
		}
	}
	else//если ввели группу
	{
		for(int i = 0; i<amount_groups; i++)
		{
			if(groups[i]->Title == face)
			{
				cout<<"(id-ФИО-Колличество оценок-Оценки-Средняя оценка)\n";
				groups[i]->print_gr();
			}
		}
	}
}
void Dekanat::group_to_group(STR id,STR Title)
{
	for(int i = 0; i<amount_groups; i++)
	{
		for(int j = 0; j<amount_Stud; j++)
		{
			if(groups[i]->mass_st[j]->id == id)
			{
				for(int k = 0; k<amount_groups; k++)
				{
					if(groups[k]->Title == Title)
					{
						groups[k]->add_student(groups[i]->mass_st[j],groups[i]);
						break;
					}
				}
				groups[i]->Delete_st(groups[i]->mass_st[j]->id);
				return;
			}
		}
	}
}
void Dekanat::Remove_students()
{
	for(int i = 0; i<amount_groups; i++)
	{
		for(int j = 0; j<groups[i]->amount_st; j++)
		{
			if(groups[i]->mass_st[j]->medium_mark() < 3.5)
			{
				groups[i]->Delete_st(groups[i]->mass_st[j]->id);
				j--;// очень,очень,ОЧЕНЬ важная мелочь
			}
		}
	}
}
void Dekanat::save_date()
{
	Save.clear();
	Save<<"(id-ФИО-Колличество оценок-Оценки-Средняя оценка-группа)\n";
	for(int i = 0; i<amount_groups; i++)
	{
		for(int j = 0; j<groups[i]->amount_st; j++)
		{
			Save<<groups[i]->mass_st[j]->id<<" |";
			Save<<groups[i]->mass_st[j]->fio<<" |";
			Save<<groups[i]->mass_st[j]->amount_marks<<" |";
			for(int k = 0; k<groups[i]->mass_st[j]->amount_marks; k++)
			{
				Save<<groups[i]->mass_st[j]->marks[k];
			}
			Save<<" |"<<groups[i]->mass_st[j]->medium_mark();
			Save<<" |"<<groups[i]->mass_st[j]->gr->Title<<"\n";
		}
	}
}
void Dekanat::Selection_Heads()
{
	for(int i = 0; i<amount_groups; i++)
	{
		groups[i]->selection_Head();
	}
}
void Dekanat::PRINT()
{
	Student St;
	cout<<"Демонстрация методов класса Student:\n-------------------------------------------------\n";
	cout<<"Создаем Иванова Петра Семеновича с номером 1234\n";
	cout<<"Добавляем ему оценки,  выводим среднюю оценку\n";
	cout<<"(ФИО-id-Колличество оценок-Оценки-Средняя оценка)";
	St.create_ST("1234","Иванов Петр Семенович");
	for(int i = 0; i<10; i++)
	{
	   St.add_marks();
	}
	St.medium_mark();
	St.print_st();
	cout<<"\n-------------------------------------------------\n\n\n\n";


	cout<<"Демонстрация методов класса Group:\n-------------------------------------------------\n";
	Group G;
	Student stud;
	stud.create_ST("4321","Бенедиктов Роман Антонович");
	for(int i = 0; i<10; i++)
	{
	   stud.add_mark();
	}
	stud.medium_mark();
	cout<<"1) Создаем группу \"Прикладная информатика\"\n";
	G.create_group("Прикладная информатика");
	cout<<"2) Добавляем в нее студентов\n";
	G.add_student(&St,&G);
	G.add_student(&stud,&G);
	cout<<"3) Выбраем старосту в группе\n";
	G.selection_Head();
	cout<<"4) Узнаем среднюю оценку группы\n";
	G.medium_mark_group();
	cout<<"5) Выводим  группy :\n";
	G.print_gr();
	cout<<"\n4) Осуществляем поиск студента с номером 1234\n";
	G.search_st("1234")->print_st();
	cout<<"6) Удаляем студента с номером 4321 из группы\n";
	string a = "4321";
	G.Delete_st(a);
	cout<<"Выводим  группy :\n";
	G.print_gr();
	cout<<"\n-------------------------------------------------\n\n\n\n";

	Dekanat D;
	cout<<"Демонстрация методов класса Dekanat:\n-------------------------------------------------\n";
	cout<<"1) Создаем 30 студентов  из файла и выводим их\n\n";
	for(int i = 0; i<30; i++)
	{
		D.create_ST_of_file();
		D.mass_ST[i]->print_st();
	}
	cout<<"\n2) Создаем группы из файла\n";
	for(int j = 0; j<3;j++)
	{
		D.create_GR_of_file();
	}
	cout<<"Просим вывести информацию о (студенте с номером 10) и о (группе ПМИ)\n";
	D.statistic("10");
	cout<<endl;
	D.statistic("ПМИ");
	cout<<"\nПереводим студента с номером 3(Васильев Денис Филиппович) в группу ПМИ\n";
	D.group_to_group("3","ПМИ");
	cout<<"Выбраем старост в группах\n";
	D.Selection_Heads();
	for(int i = 0; i<3; i++)
	{
		D.groups[i]->print_gr();
	    cout<<"\nCтароста:";
	    D.groups[0]->Head->print_st();
		cout<<"\n\n";
	}
	cout<<"Отчисляем  студентов за неуспеваемость\n";
	D.Remove_students();
	for(int i = 0; i<3; i++)
	{
		D.groups[i]->print_gr();
		cout<<"\n\n";
	}
	cout<<endl;
}