#include "DatList.h"
enum ERRORS1 { EMPTY_LIST, LINK_DOESNT_EXIST, EMPTY_LINK };

TDatList::TDatList()
{
	pStop = NULL;
	ListLen = 0;
	CurrPos = -1;
	pFirst = pLast = pCurrLink = pPrevLink = pStop;
}

void TDatList::InsFirst(PTDatValue pVal)
{
	TDatLink* tmp = GetLink(pVal, pFirst);
	if (IsEmpty())
	{
		pLast = tmp;
		pCurrLink = tmp;
	}
	if (pFirst == pCurrLink)
		pPrevLink = tmp;
	pFirst = tmp;
	CurrPos++;
	ListLen++;
}

void TDatList::InsLast(PTDatValue pVal)
{
	TDatLink* tmp = GetLink(pVal, pStop);
	if (IsEmpty())
	{
		pFirst = tmp;
		pCurrLink = tmp;
		CurrPos++;
	}
	else
		pLast->SetNextLink(tmp);
	if (IsListEnded())
		pCurrLink = tmp;
	pLast = tmp;
	ListLen++;
}

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
	if (!pVal)
		throw EMPTY_LINK;
	PTDatLink tmp = new TDatLink(pVal, pLink);
	return tmp;
}

void TDatList::DelLink(PTDatLink pLink)
{
	if (pLink == pStop)
		throw LINK_DOESNT_EXIST;
	if (pLink->pValue)
		pLink->pValue = NULL;
	delete pLink;
}

void TDatList::DelFirst()
{
	if (IsEmpty())
		throw EMPTY_LIST;
	if (pFirst == pPrevLink)
		pPrevLink = pStop;
	else
	{
		if (pFirst == pLast)
		{
			pCurrLink = pLast = pStop;
		}
		else if (pFirst == pCurrLink)
		{
			pCurrLink = pCurrLink->GetNextDatLink();
			CurrPos++;
		}
	}
	PTDatLink tmp = pFirst;
	pFirst = pFirst->GetNextDatLink();
	DelLink(tmp);
	ListLen--;
	CurrPos--;
}

void TDatList::InsCurrent(PTDatValue pVal)
{
	if (pCurrLink == pFirst)
		InsFirst(pVal);
	else 
		if (CurrPos<=ListLen)
	{
		PTDatLink tmp = GetLink(pVal, pCurrLink);
		pPrevLink->SetNextLink(tmp);
		ListLen++;
		CurrPos++;
	}
		else throw LINK_DOESNT_EXIST;
}

void TDatList::DelCurrent()
{
	if (IsListEnded())
		throw LINK_DOESNT_EXIST;
	if (pCurrLink == pFirst)
		DelFirst();
	else
	{
		PTDatLink tmp = pCurrLink;
		if (pCurrLink == pLast)
		pLast = pPrevLink;
		pPrevLink->SetNextLink(pCurrLink->pNext);
		pCurrLink = pCurrLink->GetNextDatLink();
		ListLen--;
		DelLink(tmp);
	}
}

int TDatList::Reset()
{
	if (!IsEmpty())
	{
		CurrPos = 0;
		pPrevLink = pStop;
		pCurrLink = pFirst;
	}
	return 0;
}

int TDatList::IsListEnded() const
{
	return pCurrLink == pStop;
}

int TDatList::GetCurrentPos() const
{
	return CurrPos;
}

int TDatList::GoNext()
{
	if (!pCurrLink)
		throw LINK_DOESNT_EXIST;
	pPrevLink = pCurrLink;
	pCurrLink = pCurrLink->GetNextDatLink();
	CurrPos++;
	if (CurrPos == ListLen)
		CurrPos = -1;
	return IsListEnded();
}

int TDatList::SetCurrentPos(int pos)
{
	if (pos >= ListLen)
		throw LINK_DOESNT_EXIST;
	if (pos > GetCurrentPos())
	{
		int pos2 = GetCurrentPos();
		for (int i = 0; i < pos - pos2; i++)
			GoNext();
	}
	else
	{
		Reset();
		if (pos == ListLen)
			CurrPos = -1;
		for (int i = 0; i < pos; i++)
			GoNext();
	}
	return 0;
}

void TDatList::DelList()
{
	while (!IsEmpty())
		DelFirst();
	pFirst = pLast = pCurrLink = pPrevLink = pStop;
}

PTDatValue TDatList::GetDatValue(TLinkPos mode) const
{
	if (pCurrLink == pStop)
		throw LINK_DOESNT_EXIST;
	if (mode == CURRENT)
	{
		return pCurrLink->GetDatValue();
	}
	return nullptr;
}