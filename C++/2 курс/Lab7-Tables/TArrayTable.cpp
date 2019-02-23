#include "TArrayTable.h"
#include <stdexcept>

TArrayTable::TArrayTable(int size) : TTable()
{
    if (size <= 0 || size > TabMaxSize)
        throw std::out_of_range("Avaliable diapasone: [1;25]");

    pRecs = new PTTabRecord[size];
    for (int i = 0; i < size; ++i)
        pRecs[i] = nullptr;
    TabSize = size;
    CurrPos = 0;
}

TArrayTable::~TArrayTable()
{
    if (pRecs != nullptr)
    {
        for (int i = 0; i < TabSize; ++i)
            if (pRecs[i] != nullptr)
            {
                if (pRecs[i]->pValue != nullptr)
                    delete pRecs[i]->pValue;
                delete pRecs[i];
            }
        delete[] pRecs;
    }
}

int TArrayTable::IsFull() const
{
    return DataCount == TabSize;
}

int TArrayTable::GetTabSize() const { return TabSize; }

TKey TArrayTable::GetKey(void) const
{
    return GetKey(CURRENT_POS);
}

PTDatValue TArrayTable::GetValuePTR(void) const
{
    return GetValuePTR(CURRENT_POS);
}

TKey TArrayTable::GetKey(TDataPos mode) const
{
    if (IsEmpty())
        throw std::runtime_error("Table is empty");

    int validPos;
    switch (mode)
    {
    case FIRST_POS:
        validPos = 0;
        break;
    case CURRENT_POS:
        validPos = CurrPos;
        break;
    case LAST_POS:
        validPos = DataCount - 1;
        break;
    default:
        throw std::invalid_argument("There is no such position");
    }
    return (pRecs[validPos] == nullptr) ? TKey("") : 
        pRecs[validPos]->key;
}

PTDatValue TArrayTable::GetValuePTR(TDataPos mode) const
{
    if (IsEmpty())
        throw std::runtime_error("Table is empty");

    int validPos;
    switch (mode)
    {
    case FIRST_POS:
        validPos = 0;
        break;
    case CURRENT_POS:
        validPos = CurrPos;
        break;
    case LAST_POS:
        validPos = DataCount - 1;
        break;
    default:
        throw std::invalid_argument("There is no such position");
    }
    return (pRecs[validPos] == nullptr) ? nullptr :
        pRecs[validPos]->pValue;
}

int TArrayTable::Reset(void)
{
    return CurrPos = 0;
}

int TArrayTable::IsTabEnded(void) const
{
    return CurrPos == DataCount;
}

int TArrayTable::GoNext(void)
{
    if (!IsTabEnded()) return ++CurrPos;
    else return 1;
}

int TArrayTable::SetCurrentPos(int pos)
{
    if (pos < 0 || pos >= DataCount)
        throw std::invalid_argument("There is no such position");
    return CurrPos = pos;
}

int TArrayTable::GetCurrentPos(void) const { return CurrPos; }