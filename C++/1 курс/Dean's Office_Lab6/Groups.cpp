#include "Group.h"

void Group::add_student(Student *st,Group *group)
{
	if(amount_st == 0)
	{
		mass_st = new Student*[1];
		mass_st[0] = st;
		mass_st[0]->add_to_group(group);
		amount_st++;
	}
	else
	{
		Student **buf = new Student* [amount_st];
	    for(int i = 0; i < amount_st; i++)
	    {
		    buf[i] = mass_st[i];
	    }
	    delete[] mass_st;
	    mass_st = new Student* [++amount_st];
		for(int i = 0; i<amount_st-1; i++)
	    {
		   mass_st[i] = buf[i];
	    }
		delete [] buf;
	    mass_st[amount_st-1] = st;
		mass_st[amount_st-1]->add_to_group(group);
	}
	
}
Student* Group::selection_Head()
{
	random_device rand;
	Head  = mass_st[rand()%amount_st];
	return Head;
}
Student* Group::search_st(STR id)
{
	for(int i = 0; i<amount_st; i++)
	{
		if(mass_st[i]->id == id)
			return mass_st[i];
		if(i == amount_st-1)
		{
			cout<<"Студент не найден";
			return 0;
		}
	}
}
float Group::medium_mark_group()
{
	float sum = 0;
	for(int i = 0; i<amount_st; i++)
	{
		sum+=mass_st[i]->medium_mark();
	}
	if(amount_st == 0)
		return sum;
	else
		return sum/amount_st;
}
void Group::Delete_st(string id)
{
	for(int i = 0; i<amount_st; i++)
	{
		if(mass_st[i]->id == id)
		{
			for(int j = i; j<amount_st-1 ; j++)
			{
				mass_st[j] = mass_st[j+1];
			}
			Student **buf = new Student* [--amount_st];
			for(int i = 0; i<amount_st; i++)
			{
				buf[i] = mass_st[i];
			}
			delete [] mass_st;
			mass_st = new Student* [amount_st];
			for(int i = 0; i<amount_st; i++)
			{
				mass_st[i] = buf[i];
			}
			delete [] buf;
			return;
		}
	}
}
void Group::print_gr()
{
	cout<<Title;
	for(int i = 0; i<amount_st; i++)
	{
		mass_st[i]->print_st();
	}
	cout<<"Средняя оценка группы:"<<this->medium_mark_group();
}