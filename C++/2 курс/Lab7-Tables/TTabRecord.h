#ifndef _TAB_RECORD_H_
#define _TAB_RECORD_H_

#include <string>
#include "DatValue.h"

typedef std::string TKey;   // тип ключа записи

class TTabRecord;
typedef TTabRecord *PTTabRecord;

class TTabRecord : public TDatValue 
{  
  protected:
    TKey key;
    PTDatValue pValue;   // указатель на значение
  public:
    TTabRecord(TKey k = "", PTDatValue pVal = nullptr);
    void SetKey(TKey k);
    TKey GetKey();
    void SetValuePtr(PTDatValue p);        // установить указатель на данные
    PTDatValue GetValuePTR();              // получить указатель на данные
    virtual TDatValue* GetCopy() override; // изготовить копию

    TTabRecord& operator=(const TTabRecord &tr);
    virtual int operator==(const TTabRecord &tr); // сравнение ==
    virtual int operator<(const TTabRecord &tr);  // сравнение <
    virtual int operator>(const TTabRecord &tr);  // сравнение >

    friend class TArrayTable;
    friend class TScanTable;
    friend class TSortTable;
    friend class TTreeNode;
    friend class TTreeTable;
    friend class TArrayHash;
    friend class TListHash;
};

#endif