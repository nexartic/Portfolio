#pragma once
#include "DatValue.h"
using namespace std;
class TMonom;
typedef TMonom* PTMonom;
class TMonom : public TDatValue {
protected:
	int Coeff; // коэффициент монома
	int Index; // индекс (свертка степеней)
public:
	TMonom(int cval = 1, int ival = 0) {
		Coeff = cval; Index = ival;
	};
	virtual TDatValue * GetCopy(); // изготовить копию
	void SetCoeff(int cval) { Coeff = cval; }
	int  GetCoeff(void) { return Coeff; }
	void SetIndex(int ival) { Index = ival; }
	int  GetIndex(void) { return Index; }
	TMonom& operator=(const TMonom &tm) {
		Coeff = tm.Coeff; Index = tm.Index;
		return *this;
	}
	int operator==(const TMonom &tm) {
		return (Coeff == tm.Coeff) && (Index == tm.Index);
	}
	int operator<(const TMonom &tm) {
		return Index<tm.Index;
	}

	friend ostream& operator<<(ostream &out, const TMonom& q)
	{
		out << abs(q.Coeff);
		if (q.Index / 100 > 0)
			out << "* x^" << q.Index / 100;
		if ((q.Index / 10)%10 > 0)
			out << " * y^" << (q.Index / 10)%10;
		if (q.Index % 10 > 0)
			out << " * z^" << q.Index % 10<<' ';
		return out;
	}

	friend class TPolinom;
};
