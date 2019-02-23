#pragma once
#include"tstack.h"
class TQueue : public TStack
{
	unsigned Hi;
	unsigned Li;
	unsigned GetNextIndex(unsigned&);
public:
	TQueue(unsigned size = 10);
	void  Put(const TData &Val);
	TData Get(void);
};