#ifndef DAT_LINK_H
#define DAT_LINK_H

#include "RootLink.h"

class TDatLink;
typedef TDatLink *PTDatLink;

class TDatLink : public TRootLink
{
protected:
	PTDatValue pValue;  // указатель на объект значения
public:
	TDatLink(PTDatValue pVal = nullptr, PTRootLink pN = nullptr) : TRootLink(pN) { pValue = pVal; }
	void SetDatValue(PTDatValue pVal) override { pValue = pVal; }
	PTDatValue GetDatValue() override { return  pValue; }
	PTDatLink  GetNextDatLink() { return  (PTDatLink)pNext; }
	friend class TDatList;
};

#endif