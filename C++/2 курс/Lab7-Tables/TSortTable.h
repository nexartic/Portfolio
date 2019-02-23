#ifndef _SORT_TABLE_H_
#define _SORT_TABLE_H_

#include "TScanTable.h"

enum TSortMethod { INSERTION_SORT, MERGE_SORT, QUICK_SORT };

class TSortTable : public TScanTable
{
  protected: 
    TSortMethod SortMethod;
    void SortData(void);    // сортировка данных
    void InsertSort(PTTabRecord *pMem, int DataCount);
    void MergeSort(PTTabRecord *pMem, int DataCount);
    void MergeSorter(PTTabRecord * &pData, int left, int right);
    void MergeData(PTTabRecord * &pData, int left, int mid, int right);
    void QuickSort(PTTabRecord *pMem, int left, int right);
    int QuickSplit(PTTabRecord *pData, int left, int right);
  public:
    TSortTable(int Size = TabMaxSize) : TScanTable(Size) 
    { 
        SortMethod = INSERTION_SORT; 
    }
    TSortTable(const TScanTable &tab);
    TSortTable& operator=(const TScanTable &tab);
    TSortMethod GetSortMethod(void);
    void SetSortMethod(TSortMethod sm);

    // основные методы
    virtual PTDatValue FindRecord(TKey k);           // найти запись
    virtual void InsRecord(TKey k, PTDatValue pVal); // вставить
    virtual void DelRecord(TKey k);                  // удалить запись
};

#endif