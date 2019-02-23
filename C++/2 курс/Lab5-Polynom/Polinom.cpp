#include "Polinom.h"
enum ERRORS {MONOMS_DONT_EXIST};

TPolinom::TPolinom(int monoms[][2], int km)
{
	PTMonom hmonom = new TMonom(0, -1);
	pHead->SetDatValue(hmonom);
	for (int i = 0; i < km; i++)
	{
		if (monoms[i][0] == 0 && monoms[i][1] <=0)
			throw MONOMS_DONT_EXIST;
		if (monoms[i][1]>999)
			throw MONOMS_DONT_EXIST;
		TMonom* tmp = new TMonom(monoms[i][0], monoms[i][1]);
		InsLast(tmp);
	}
}

TPolinom::TPolinom(const TPolinom& q)
{
	PTMonom hmonom = new TMonom(0, -1);
	pHead->SetDatValue(hmonom);
	PTDatLink secCur = q.pFirst;
	while (secCur!=pStop && secCur)
	{
		PTMonom tmp = (PTMonom)secCur->GetDatValue();
		InsLast(tmp->GetCopy());
		secCur = secCur->GetNextDatLink();
	}
}

TPolinom& TPolinom::operator=(TPolinom& q)
{
	if (this == &q)
		return *this;
	DelList();
	int lastpos = q.GetCurrentPos();
	q.Reset();
	while (!q.IsListEnded())
	{
		PTMonom tmp = q.GetMonom();
		InsLast(tmp->GetCopy());
		q.GoNext();
	}
	q.SetCurrentPos(lastpos);
	return *this;
}

TPolinom& TPolinom:: operator+(TPolinom& q)
{
	TPolinom* tmp = new TPolinom();
	if (this->IsEmpty() && q.IsEmpty())
		return *tmp;
	if (this->IsEmpty())
	{
		*tmp = q;
		return *tmp;
	}
	if (q.IsEmpty())
	{
		*tmp = *this;
		return *tmp;
	}
	int lastposleft = this->GetCurrentPos();
	int lastposright = q.GetCurrentPos();
	this->Reset();
	q.Reset();
	PTMonom left = this->GetMonom();
	PTMonom right = q.GetMonom();  
	PTMonom curMonom = new TMonom;
	while (!(this->IsListEnded() && q.IsListEnded()))
	{
		if (!this->IsListEnded() && !q.IsListEnded())
		{
			if (right->GetIndex() == left->GetIndex())
			{
				if (left->GetCoeff() == -(right->GetCoeff()))
				{
					this->GoNext();
					if (!this->IsListEnded())
						left = this->GetMonom();
					q.GoNext();
					if (!q.IsListEnded())
						right = q.GetMonom();
				}
				else
				{
					curMonom->SetCoeff(left->GetCoeff() + right->GetCoeff());
					curMonom->SetIndex(right->GetIndex());
					tmp->InsLast(curMonom->GetCopy());
					this->GoNext();
					if (!this->IsListEnded())
						left = this->GetMonom();
					q.GoNext();
					if (!q.IsListEnded())
						right = q.GetMonom();
				}
			}
			else
			{
				if (right->GetIndex() < left->GetIndex())
				{
					curMonom->SetCoeff(right->GetCoeff());
					curMonom->SetIndex(right->GetIndex());
					tmp->InsLast(curMonom->GetCopy());
					q.GoNext();
					if (!q.IsListEnded())
						right = q.GetMonom();
				}
				else
					if (right->GetIndex() > left->GetIndex())
					{
						curMonom->SetCoeff(left->GetCoeff());
						curMonom->SetIndex(left->GetIndex());
						tmp->InsLast(curMonom->GetCopy());
						this->GoNext();
						if (!this->IsListEnded())
							left = this->GetMonom();
					}
			}
		}
		else
		{
			if (!this->IsListEnded() && q.IsListEnded())
			{
				curMonom->SetCoeff(left->GetCoeff());
				curMonom->SetIndex(left->GetIndex());
				tmp->InsLast(curMonom->GetCopy());
				this->GoNext();
				if (!this->IsListEnded())
					left = this->GetMonom();
			}
			else 
				if (this->IsListEnded() && !q.IsListEnded())
				{
					curMonom->SetCoeff(right->GetCoeff());
					curMonom->SetIndex(right->GetIndex());
					tmp->InsLast(curMonom->GetCopy());
					q.GoNext();
					if (!q.IsListEnded())
						right = q.GetMonom();
				}
		}
	}
	this->SetCurrentPos(lastposleft);
	q.SetCurrentPos(lastposright);
	return *tmp;
}