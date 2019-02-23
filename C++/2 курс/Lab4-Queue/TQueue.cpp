#include"TQueue.h"
TQueue::TQueue(unsigned size) : TStack(size)
{
	Hi = -1;
	Li = -1;
}

void TQueue::Put(const TData& elem)
{
	if (!IsFull())
	{
		pMem[GetNextIndex(Hi)] = elem;
		DataCount++;
	}
}

TData TQueue::Get()
{
	if (!IsEmpty())
	{
		DataCount--;
		return pMem[GetNextIndex(Li)];
	}
	return 404;
}

unsigned TQueue::GetNextIndex(unsigned& elem)
{
	if (++elem = MemSize)
		elem = 0;
	return elem;
}