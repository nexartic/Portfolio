#pragma once
#include "HeadRing.h"
#include "Monom.h"

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = NULL, int km = 0); // конструктор
												  // полинома из массива «коэффициент-индекс»
	TPolinom(const TPolinom &q);      // конструктор копирования
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+(TPolinom &q); // сложение полиномов
	TPolinom & operator=(TPolinom &q); // присваивание
	friend ostream& operator<<(ostream &out, TPolinom& q)
	{
		int lastpos = q.GetCurrentPos();
		q.Reset();
		out << "P(x,y,z) = ";
		if (q.IsEmpty())
		{
			out << '0';
			return out;
		}
		while (!q.IsListEnded())
		{
			PTMonom m = q.GetMonom();
			if (m->GetCoeff() < 0)
				out << '-';
			else
			{
				if (m->GetCoeff() > 0 && q.GetCurrentPos() > 0)
					out << '+';
				else if (m->GetCoeff() == 0)
					continue;
			}
			out << *m;
			q.GoNext();
		}
		q.SetCurrentPos(lastpos);
		out << endl;
		return out;
	}
	friend istream& operator>> (istream &in, TPolinom&q)
	{
		q.DelList();
		int coef, ind;
		int len;
		cin >> len;
		for (int i = 0; i < len; i++)
		{
			cin >> coef >> ind;
			if (coef == 0)
				continue;
			int monoms[1][2];
			monoms[0][0] = coef;
			monoms[0][1] = ind;
			TPolinom p(monoms, 1);
			q = q + p;
		}
			return in;
	}
};
