#include "TArrayHash.h"

TArrayHash::TArrayHash(int Size, int Step) : THashTable()
{
    if (Size <= 0 || Size > TabMaxSize || Step < 1 || Step >= Size)
        throw std::out_of_range("Parameter is out if range");

    pRecs = new PTTabRecord[Size];
    for (int i = 0; i < Size; ++i)
        pRecs[i] = nullptr;
    TabSize = Size;
    HashStep = Step;
    pMark = new TTabRecord("DELETED");
}

TArrayHash::~TArrayHash()
{
    if (pRecs != nullptr)
    {
        for (int i = 0; i < TabSize; ++i)
            if (pRecs[i] != nullptr && pRecs[i] != pMark)
            {
                if (pRecs[i]->pValue != nullptr)
                    delete pRecs[i]->pValue;
                delete pRecs[i];
            }
        delete[] pRecs;
    }
    delete pMark;
}

int TArrayHash::IsFull() const
{
    return DataCount == TabSize;
}

TKey TArrayHash::GetKey(void) const
{
    return (CurrPos < 0 || IsTabEnded()) ? TKey("") : pRecs[CurrPos]->key;
}

PTDatValue TArrayHash::GetValuePTR(void) const
{
    return (CurrPos < 0 || IsTabEnded()) ? nullptr : pRecs[CurrPos]->pValue;
}

PTDatValue TArrayHash::FindRecord(TKey k)
{
    if (IsEmpty())
        throw std::runtime_error("Table is empty");

    FreePos = -1;   // First free line index
    CurrPos = HashFunc(k) % TabSize;
    Efficiency = 0;
    int originPos = CurrPos;
    while (true)
    {
        Efficiency++;
        if (pRecs[CurrPos] == nullptr)
            throw std::runtime_error("There is no record with specified key");
        else if (pRecs[CurrPos] == pMark)
        {
            if (FreePos < 0) FreePos = CurrPos;
        }
        else if (pRecs[CurrPos]->key == k)
            return pRecs[CurrPos]->pValue;

        CurrPos = GetNextPos(CurrPos);
        if (CurrPos == originPos)
            break;
    }

    throw std::runtime_error("There is no record with specified key");
}

void TArrayHash::InsRecord(TKey k, PTDatValue pVal)
{
    if (IsFull())
        throw std::runtime_error("Table is full");

    FreePos = -1;   // First free line index
    CurrPos = HashFunc(k) % TabSize;
    int originPos = CurrPos;
    while (true)
    {
        if (pRecs[CurrPos] != nullptr && pRecs[CurrPos] != pMark)
        {
            if (pRecs[CurrPos]->key == k)
                throw std::runtime_error
                ("Record with specified key already exists");
        }
        else if (pRecs[CurrPos] == pMark)
        {
            if (FreePos < 0) FreePos = CurrPos;
        }
        else if (pRecs[CurrPos] == nullptr)
        {
            if (FreePos < 0)
                pRecs[CurrPos] = new TTabRecord(k, pVal);
            else pRecs[FreePos] = new TTabRecord(k, pVal);
            DataCount++;
            return;
        }

        CurrPos = GetNextPos(CurrPos);
        if (CurrPos == originPos)
        {
            if (FreePos > -1)
            {
                pRecs[FreePos] = new TTabRecord(k, pVal);
                DataCount++;
                return;
            }
            break;
        }
    }

    throw std::runtime_error("Cannot add a new record");
}

void TArrayHash::DelRecord(TKey k)
{
    try { FindRecord(k); }
    catch (...) { throw; }

    if (pRecs[CurrPos]->pValue != nullptr)
    {
        delete pRecs[CurrPos]->pValue;
        pRecs[CurrPos]->pValue = nullptr;
    }
    delete pRecs[CurrPos];
    pRecs[CurrPos] = pMark;
    DataCount--;
}

int TArrayHash::Reset(void)
{
    CurrPos = 0;
    while (!IsTabEnded() && (pRecs[CurrPos] == nullptr || 
                             pRecs[CurrPos] == pMark))
        CurrPos++;
    if (IsTabEnded()) return -1;
    else return CurrPos;
}

int TArrayHash::IsTabEnded(void) const
{
    return CurrPos == TabSize;
}

int TArrayHash::GoNext(void)
{
    while (++CurrPos && !IsTabEnded())
    {
        if (pRecs[CurrPos] != nullptr && pRecs[CurrPos] != pMark)
            break;
    }
    if (IsTabEnded()) return 1;
    else return CurrPos;
}
