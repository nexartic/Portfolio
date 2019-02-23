#include "TListHash.h"

TListHash::TListHash(int Size) : THashTable()
{
    if (Size <= 0 || Size > TabMaxSize)
        throw std::out_of_range("Size is out of range");

    pList = new PTDatList[Size];
    for (int i = 0; i < Size; ++i)
        pList[i] = new TDatList();
    TabSize = Size;
    CurrList = 0;
}

TListHash::~TListHash()
{
    if (pList != nullptr)
    {
        for (int i = 0; i < TabSize; ++i)
            delete pList[i];
        delete[] pList;
    }
    // WARNING: TabRecord->pValue should be deleted manually!
}

int TListHash::IsFull() const
{
    try { auto tmp = new TDatLink(); delete tmp; }
    catch (...) { return true; }

    return false;
}

TKey TListHash::GetKey(void) const
{
    if (CurrList < 0 || IsTabEnded()) return TKey("");
    auto tmp = static_cast<PTTabRecord>(pList[CurrList]->GetDatValue());
    return (tmp == nullptr) ? TKey("") : tmp->key;
}

PTDatValue TListHash::GetValuePTR(void) const
{
    if (CurrList < 0 || IsTabEnded()) return nullptr;
    auto tmp = static_cast<PTTabRecord>(pList[CurrList]->GetDatValue());
    return (tmp == nullptr) ? nullptr : tmp->pValue;
}

PTDatValue TListHash::FindRecord(TKey k)
{
    if (IsEmpty())
        throw std::runtime_error("Table is empty");

    Efficiency = 0;
    CurrList = HashFunc(k) % TabSize;
    auto cl = pList[CurrList];  // Current list
    for (cl->Reset(); !cl->IsListEnded(); cl->GoNext())
    {
        Efficiency++;
        if (static_cast<PTTabRecord>(cl->GetDatValue())->key == k)
            return static_cast<PTTabRecord>(cl->GetDatValue())->pValue;
    }

    throw std::runtime_error("There is no record with specified key");
}

void TListHash::InsRecord(TKey k, PTDatValue pVal)
{
    if (IsFull())
        throw std::runtime_error("Table is full");

    try { FindRecord(k); }
    catch (...)
    {
        CurrList = HashFunc(k) % TabSize;
        pList[CurrList]->InsFirst(new TTabRecord(k, pVal));
        DataCount++;
        return;
    }

    throw std::runtime_error("Record with specified key already exists");
}

void TListHash::DelRecord(TKey k)
{
    try { FindRecord(k); }
    catch (...) { throw; }

    pList[CurrList]->DelCurrent();
    DataCount--;
}

int TListHash::Reset(void)
{
    CurrList = 0;
    while (!IsTabEnded() && pList[CurrList]->IsEmpty())
        CurrList++;
    if (IsTabEnded()) return -1;
    else
    {
        pList[CurrList]->Reset();
        return CurrList;
    }
}

int TListHash::IsTabEnded(void) const
{
    return CurrList == TabSize;
}

int TListHash::GoNext(void)
{
    pList[CurrList]->GoNext();
    if (!(pList[CurrList]->IsListEnded()))
        return CurrList;
    while (++CurrList && !IsTabEnded())
    {
        if (!(pList[CurrList]->IsEmpty()))
            return pList[CurrList]->Reset();
    }
    return 1;
}