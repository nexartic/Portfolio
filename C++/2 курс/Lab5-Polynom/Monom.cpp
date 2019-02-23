#include "Monom.h"

TDatValue* TMonom::GetCopy()
{
	TDatValue* monom = new TMonom(this->Coeff, this->Index);
	return monom;
}