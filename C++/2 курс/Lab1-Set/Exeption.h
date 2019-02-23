#pragma once
#include<windows.h>
#include<string>
#include<iostream>
using namespace std;
class NegativeIndex
{
public:
	NegativeIndex()
	{
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED);
		cout << "Error: Negative valuÅ." << endl;
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
};
class BigIndex
{
public:
	BigIndex()
	{
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED);
		cout << "Error: Too big value." << endl;
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
};
