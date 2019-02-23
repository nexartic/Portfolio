#include "DatList.h"
#include <stdexcept>

TDatList::TDatList()
{
	pFirst = pLast = pCurrLink = pPrevLink = pStop = nullptr;
	ListLen = 0;
}

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
	return new TDatLink(pVal, pLink);
}

void TDatList::DelLink(PTDatLink pLink)
{
	if (pLink != nullptr)
	{
		if (pLink->pValue != nullptr) delete pLink->pValue;
		delete pLink;
	}
}

PTDatValue TDatList::GetDatValue(TLinkPos mode) const
{
	PTDatLink res = nullptr;
	switch (mode)
	{
		case FIRST:
			res = pFirst;
			break;
		case CURRENT:
			res = pCurrLink;
			break;
		case LAST:
			res = pLast;
			break;
		default:
			throw std::invalid_argument("Incorrect position");
	}
	return (res == nullptr)? nullptr: res->pValue;
}

int TDatList::SetCurrentPos(int pos)
{
	if (pos < 0 || pos >= ListLen) 
		throw std::out_of_range("Position is out of range");
	else
	{
		Reset();
		for (int i = 0; i < pos; ++i)
			GoNext();
		CurrPos = pos;
		return 1;
	}
}

int TDatList::Reset()
{
	if (!IsEmpty())
	{
		pPrevLink = pStop;
		pCurrLink = pFirst;
		CurrPos = 0;
		return 1;
	}
	else return -1;
}

int TDatList::GoNext()
{
	if (!IsEmpty())
	{
		pPrevLink = pCurrLink;
		pCurrLink = pCurrLink->GetNextDatLink();
		CurrPos++;
		return 1;
	}
	else return -1;
}

void TDatList::InsFirst(PTDatValue pVal)
{
	PTDatLink n_node = GetLink(pVal, pFirst);
	pFirst = n_node; ListLen++;
	if (pLast == pStop)		// List was empty
	{
		pLast = pCurrLink = n_node;
		CurrPos = 0;
	}
	else if (CurrPos == 0)	// Current node was the first
	{
		pPrevLink = pFirst;
		CurrPos = 1;
	}
	else CurrPos++;
}

void TDatList::InsLast(PTDatValue pVal)
{
	PTDatLink n_node = GetLink(pVal, pStop);
	auto old_last = pLast;
	pLast = n_node; ListLen++;
	if (pFirst == pStop)		// List was empty
	{
		pFirst = pCurrLink = n_node;
		CurrPos = 0;
	}
	else old_last->SetNextLink(pLast);
	if (IsListEnded()) pCurrLink = pLast;
}

void TDatList::InsCurrent(PTDatValue pVal)
{
	if (IsEmpty() || CurrPos == 0) InsFirst(pVal);
	else if (IsListEnded()) InsLast(pVal);
	else
	{
		PTDatLink n_node = GetLink(pVal, pCurrLink);
		pPrevLink->SetNextLink(n_node);
		pPrevLink = n_node;
		CurrPos++;
		ListLen++;
	}
}

void TDatList::DelFirst()
{
	// Do nothing if list is empty
	if (!IsEmpty())
	{
		auto old_first = pFirst;
		pFirst = pFirst->GetNextDatLink();
		ListLen--; DelLink(old_first);
		if (IsEmpty())
			pPrevLink = pCurrLink = pFirst = pLast = pStop;
		else if (CurrPos == 0) pCurrLink = pFirst;	// Current node was the first
		else if (CurrPos == 1) pPrevLink = pStop;	// Current node was the second
		else CurrPos--;
	}
}

void TDatList::DelCurrent()
{
	// Do nothing if list is empty
	if (!IsEmpty())
	{
		if (pCurrLink == pFirst) DelFirst();	// Current node was the first
		else
		{
			auto old_cur = pCurrLink;
			pCurrLink = pCurrLink->GetNextDatLink();
			pPrevLink->SetNextLink(pCurrLink);
			if (old_cur == pLast)
				pLast = pPrevLink;
			DelLink(old_cur); ListLen--;
		}
	}
}

void TDatList::DelList()
{
	while (!IsEmpty()) DelFirst();
	pPrevLink = pCurrLink = pFirst = pLast = pStop;
}