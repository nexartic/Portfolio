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
		cout << "Error: Negative value." << endl;
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
class NotEqVector
{
public:
	NotEqVector()
	{
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED);
		cout << "Error: Vectors is not equivalent." << endl;
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
};

class TheSameObjects
{
public:
	TheSameObjects()
	{
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED);
		cout << "Error: That objects is same" << endl;
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
};
