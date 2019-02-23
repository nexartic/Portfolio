#include "HeadRing.h"
enum ERRORS2 { EMPTY_LIST, LINK_DOESNT_EXIST };

THeadRing::THeadRing()
{
	pHead = new TDatLink(NULL, pStop);
	ListLen = 0;
	CurrPos = -1;
	pStop = pHead;
	pFirst = pLast = pCurrLink = pPrevLink = pStop;
}

THeadRing::~THeadRing()
{
	DelList();
	pHead = NULL;
}

void THeadRing::InsFirst(PTDatValue pVal)
{
	TDatList::InsFirst(pVal);
	pStop->SetNextLink(pFirst);
}

void THeadRing::DelFirst()
{ 
	TDatList::DelFirst();
	pStop->SetNextLink(pFirst);
}