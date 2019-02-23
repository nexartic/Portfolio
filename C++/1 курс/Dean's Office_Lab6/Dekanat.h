#include"Group.h"
#ifndef DEF
#define DEF
#include<iostream>
#include<string>
#include<random>
#include<fstream>
#include<clocale>
#include<vector>
#endif
using namespace general;
class Dekanat
{
private:
	Student** mass_ST;
	Group** groups;
	int amount_Stud;
	int amount_groups;
public:
	void create_ST_of_file();
	void create_GR_of_file();
	void statistic(STR);// введите имя группы или id студента что бы узнать их статистику 
	void group_to_group(STR,STR);
	void Remove_students();
	void save_date();
	void Selection_Heads();
	void PRINT();
	Dekanat()
	{
		amount_Stud = 0;
		amount_group = 0;
	}
	
};

