#ifndef DEF
#define DEF
#include<iostream>
#include<string>
#include<random>
#include<fstream>
#include<clocale>
#include<vector>
#endif
namespace general
{
	typedef const char* STR;
	using namespace std;
}
class Group;
class Dekanat;
using namespace general;
    class Student
    {
    private:
		string id;
        string fio;
	    int *marks;
	    int amount_marks;
	    Group *gr;
	public:
		void create_ST(STR,STR);
		void add_mark();
		float medium_mark();
		void add_to_group(Group *);
		void print_st();
		Student()
		{
			amount_mark = 0;
		}
		Student(string id,string fio)
		{
			this->id = id;
			this->fio = fio;
			amount_marks = 0;
		}
		friend Group;
		friend Dekanat;
    };

