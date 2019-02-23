#include "TTabRecord.h"

TTabRecord::TTabRecord(TKey k, PTDatValue pVal) : 
    key(k), pValue(pVal) {}

void TTabRecord::SetKey(TKey k) { key = k; }

TKey TTabRecord::GetKey() { return key; }

void TTabRecord::SetValuePtr(PTDatValue p) { pValue = p; }

PTDatValue TTabRecord::GetValuePTR() { return pValue; }

TDatValue *TTabRecord::GetCopy()
{
    if (pValue != nullptr)
        return static_cast<PTDatValue>(new TTabRecord(key, pValue->GetCopy()));
    else 
        return static_cast<PTDatValue>(new TTabRecord(key, nullptr));
}

TTabRecord& TTabRecord::operator=(const TTabRecord& rhs)
{
    if (this != &rhs)
    {
        key = rhs.key;
        if (pValue != nullptr)
            delete pValue;
        if (rhs.pValue == nullptr)
            pValue = nullptr;
        else pValue = rhs.pValue->GetCopy();
    }
    return *this;
}

int TTabRecord::operator==(const TTabRecord &rhs)
{
    return key == rhs.key;
}

int TTabRecord::operator<(const TTabRecord &rhs)
{
    return key < rhs.key;
}

int TTabRecord::operator>(const TTabRecord &rhs)
{
    return key > rhs.key;
}