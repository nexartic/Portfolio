// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// Copyright (c) Гергель В.П. 28.07.2000
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Динамические структуры данных - тестирование стека
#pragma once
#include <iostream>
#include "tstack.h"

using namespace std;

int main()
{
	TStack st(2);
	int temp;
	setlocale(LC_ALL, "Russian");
	cout << "Тестирование программ поддержки структуры типа стека" << endl;
	for (int i = 0; i < 35; i++)
	{
	st.Put(i);
	cout << "Положили значение " << i << " Код " << st.GetRetCode() << endl;
	}
	while (!st.IsEmpty())
	{
	temp = st.Get();
	cout << "Взяли значение " << temp << " Код " << st.GetRetCode() << endl;
	}
	system("pause");
	return 1;
}
