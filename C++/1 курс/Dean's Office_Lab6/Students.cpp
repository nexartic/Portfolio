#include "Student.h"
void Student :: create_ST(STR id,STR fio)
{
	this->id = id;
	this->fio = fio;
}
void Student::add_mark()
{
	random_device rnd;
	int *buf;
	if(amount_marks == 0)
	{
		marks = new int [amount_marks+1];
	}
	else
	{
 	   buf = new int[amount_marks];
	   for(int i = 0; i<amount_marks; i++)
	   {
		   buf[i] = marks[i];
	   }
	   delete[] marks;
	   marks = new int[amount_marks+1];
	   for(int i = 0; i<amount_marks; i++)
	   {
		  marks[i] = buf[i];
	   }
	   delete[] buf;
	}
	marks[amount_marks] = rnd()%4+2;
	amount_marks++;
}
float Student::medium_mark()
{
	float sum = 0;
	for(int i = 0; i<amount_marks; i++)
	{
		sum+=marks[i];
	}
	return sum/amount_marks;
}
void Student::print_st()
{
	cout<<endl<<id<<"|"<<fio<<"|"<<amount_marks<<"|";
	for(int i = 0; i<amount_marks; i++)
	{
		cout<<marks[i];
	}
	cout<<"|"<<this->medium_mark()<<endl;
}
void Student::add_to_group(Group *group)
{
	this->gr = group;
}
