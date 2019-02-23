#ifndef _SCAN_TABLE_H_
#define _SCAN_TABLE_H_

#include "TArrayTable.h"

class TScanTable : public TArrayTable 
{
  public:
    TScanTable(int Size = TabMaxSize) : TArrayTable(Size) {}
    
    // основные методы
    virtual PTDatValue FindRecord(TKey k);             // найти запись
    virtual void InsRecord(TKey k, PTDatValue pVal);   // вставить
    virtual void DelRecord(TKey k);                    // удалить запись
};

#endif