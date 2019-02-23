#ifndef GEN
#define GEN
#include<iostream>
#include<string>
#include<fstream>
#include<random>
#endif
namespace employee
{
	using namespace std;
	class Employee
	{
	public:
		Employee(){}
		virtual void calc() = 0;
		string position;
		inline virtual void contration( int , int , int ){}
	     void print_employee()
		{
			cout<<"|"<<id<<"|"<<fio<<"|"<<worktime<<" час.|"<<payment<<" руб.|"<<position<<endl;
		}
	protected:
		string fio;
		string id;
		int worktime;
		double payment;
	};
}
