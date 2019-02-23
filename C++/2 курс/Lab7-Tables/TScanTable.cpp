#include "TScanTable.h"

PTDatValue TScanTable::FindRecord(TKey k)
{
    int i = 0;
    for (i; i < DataCount; ++i)
        if (pRecs[i]->GetKey() == k) break;
    Efficiency = i + 1;
    if (i < DataCount)
    {
        CurrPos = i;
        return pRecs[i]->pValue;
    }
    else
        throw std::runtime_error("There is no record with specified key");
}

void TScanTable::InsRecord(TKey k, PTDatValue pVal)
{
    if (IsFull())
        throw std::runtime_error("Table is full");
    
    int i = 0;
    for (i; i < DataCount; ++i)
        if (pRecs[i]->GetKey() == k) break;
    if (i < DataCount)
        throw std::runtime_error("A record with specified key already exists");

    pRecs[DataCount++] = new TTabRecord(k, pVal);
}

void TScanTable::DelRecord(TKey k)
{
    if (IsEmpty())
        throw std::runtime_error("Table is empty");

    for (int i = 0; i < DataCount; ++i)
        if (pRecs[i]->GetKey() == k)
        {
            if (pRecs[i]->pValue != nullptr)
                delete pRecs[i]->pValue;
            delete pRecs[i]; pRecs[i] = nullptr;
            pRecs[i] = pRecs[DataCount - 1];
            pRecs[DataCount - 1] = nullptr;
            DataCount--;
            return;
        }
    throw std::runtime_error("There is no record with specified key");
}
