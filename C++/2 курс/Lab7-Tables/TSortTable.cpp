#include "TSortTable.h"

void TSortTable::SortData(void)
{
    switch (SortMethod)
    {
    case INSERTION_SORT:
        InsertSort(pRecs, DataCount);
        break;
    case MERGE_SORT:
        MergeSort(pRecs, DataCount);
        break;
    case QUICK_SORT:
        QuickSort(pRecs, 0, DataCount - 1);
        break;
    default:
        throw std::runtime_error("Sort method is not specified");
    }
}

void TSortTable::InsertSort(PTTabRecord *pRecs, int DataCount)
{
    for (int i = 1; i < DataCount; ++i)
    {
        int j = i;
        auto tmp = pRecs[i];
        while (j > 0 && tmp->GetKey() < pRecs[j - 1]->GetKey())
        {
            pRecs[j] = pRecs[j - 1];
            j--;
        }
        pRecs[j] = tmp;
    }
}

void TSortTable::MergeSort(PTTabRecord *pRecs, int DataCount)
{
    MergeSorter(pRecs, 0, DataCount - 1);
}

void TSortTable::MergeSorter(PTTabRecord *&pData, int left, int right)
{
    if (right == left)
        return;
    int mid = (right + left) / 2;
    MergeSorter(pData, left, mid);
    MergeSorter(pData, mid + 1, right);
    MergeData(pData, left, mid, right);
}

void TSortTable::MergeData(PTTabRecord *&pData, int left, int mid, int right)
{
    PTTabRecord *pBuff = new PTTabRecord[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
        if (pData[i]->GetKey() < pData[j]->GetKey())
            pBuff[k++] = pData[i++];
        else
            pBuff[k++] = pData[j++];
    if (i > mid)
        while (j <= right)
            pBuff[k++] = pData[j++];
    else
        while (i <= mid)
            pBuff[k++] = pData[i++];
    k = 0;
    for (i = left; i <= right; ++i)
        pData[i] = pBuff[k++];
    delete[] pBuff;
}

void TSortTable::QuickSort(PTTabRecord *pRecs, int left, int right)
{
    if (left < right)
    {
        int p = QuickSplit(pRecs, left, right);
        QuickSort(pRecs, left, p - 1);
        QuickSort(pRecs, p, right);
    }
}

int TSortTable::QuickSplit(PTTabRecord *pData, int left, int right)
{
    auto pivot = pRecs[(left + right) / 2]->GetKey();
    int i = left, j = right;
    while (i <= j)
    {
        while (pRecs[i]->GetKey() < pivot)
            i++;
        while (pRecs[j]->GetKey() > pivot)
            j--;
        if (i <= j)
        {
            auto tmp = pRecs[i];
            pRecs[i] = pRecs[j];
            pRecs[j] = tmp;
            i++;
            j--;
        }
    }
    return i;
}

TSortTable::TSortTable(const TScanTable& tab) : TScanTable(tab.TabSize)
{
    DataCount = tab.DataCount;
    for (int i = 0; i < DataCount; ++i)
        pRecs[i] = static_cast<PTTabRecord>(tab.pRecs[i]->GetCopy());
    SortMethod = INSERTION_SORT;
    SortData();
    Reset();
}

TSortTable& TSortTable::operator=(const TScanTable& tab)
{
    if (this != &tab)
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
        TabSize = tab.TabSize;
        DataCount = tab.DataCount;
        pRecs = new PTTabRecord[TabSize];
        for (int i = 0; i < TabSize; ++i)
            if (tab.pRecs[i] != nullptr)
                pRecs[i] = static_cast<PTTabRecord>(tab.pRecs[i]->GetCopy());
            else pRecs[i] = nullptr;
        SortData();
        Reset();
    }
    return *this;
}

TSortMethod TSortTable::GetSortMethod(void)
{
    return SortMethod;
}

void TSortTable::SetSortMethod(TSortMethod sm)
{
    switch (sm)
    {
    case INSERTION_SORT: case MERGE_SORT:
    case QUICK_SORT: SortMethod = sm; break;
    default:
        throw std::invalid_argument("Unsupported sort type");
    }
}

PTDatValue TSortTable::FindRecord(TKey k)
{
    Reset();
    if (IsEmpty())
        throw std::runtime_error("There is no record with specified key");
        
    if (k < pRecs[0]->GetKey() || k > pRecs[DataCount - 1]->GetKey())
    {
        if (k > pRecs[DataCount - 1]->GetKey())
            CurrPos = DataCount;
        throw std::runtime_error("There is no record with specified key");
    }
    
    // Binary search
    Efficiency = 0;
    int left = 0, right = DataCount;
    while ((right - left) > 0)
    {
        Efficiency++;
        int mid = left + (right - left) / 2;
        CurrPos = mid;
        if (pRecs[mid]->GetKey() == k)
        {
            CurrPos = mid;
            return pRecs[mid]->pValue;
        }
        if (pRecs[mid]->GetKey() > k)
            right = mid;
        else left = mid + 1;
    }
    CurrPos = right;    // Equal to CurrPos = left;

    throw std::runtime_error("There is no record with specified key");
}

void TSortTable::InsRecord(TKey k, PTDatValue pVal)
{
    if (IsFull())
        throw std::runtime_error("Table is full");

    try { FindRecord(k); }
    catch (...)
    {
        for (int i = DataCount; i > CurrPos; --i)
            pRecs[i] = pRecs[i - 1];
        pRecs[CurrPos] = new TTabRecord(k, pVal);
        DataCount++;
        return;
    }

    // Record with specified key already exists
    throw std::runtime_error("Record with specified key already exists");
}

void TSortTable::DelRecord(TKey k)
{
    if (IsEmpty())
        throw std::runtime_error("Table is empty");

    // Nonexistent key
    try { FindRecord(k); }
    catch (...) { throw; }

    if (pRecs[CurrPos]->pValue != nullptr)
        delete pRecs[CurrPos]->pValue;
    delete pRecs[CurrPos]; pRecs[CurrPos] = nullptr;
    for (int i = CurrPos; i < DataCount - 1; ++i)
        pRecs[i] = pRecs[i + 1];
    pRecs[DataCount - 1] = nullptr;
    DataCount--;
    Reset();
}
