#include "THashTable.h"

unsigned long THashTable::HashFunc(const TKey& key)
{
    // Gets numeric value from key
    unsigned long val = 0;
    for (auto i = 0; i < key.size(); ++i)
        val = (val << 3) + key[i];
    return val;
}
