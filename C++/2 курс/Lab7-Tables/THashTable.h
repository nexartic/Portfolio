#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include "TTable.h"

class THashTable : public TTable
{
    protected:
        virtual unsigned long HashFunc(const TKey& key); // hash-функция
    public:
        THashTable() : TTable() {}
};

#endif