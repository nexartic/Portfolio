#include"Student.h"
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
class Group
{	 
private:
	string Title;
	Student **mass_st;
	int amount_st;
	Student *Head;
public:
	Group( char* title)
	{
		this->Title = title;
		amount_st = 0;
	}
	Group()
	{
		amount_st = 0;
	}
	void create_group( char *title)
	{
		this->Title = title;
	}
	void add_student(Student *,Group *);
	Student* selection_Head();
	Student* search_st(STR);
	float medium_mark_group();
	void Delete_st(string);
	void print_gr();
	friend Dekanat;
};

