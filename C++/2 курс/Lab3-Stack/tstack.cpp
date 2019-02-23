#include"tstack.h"
void TStack::SetMem(void *p,int size)
{
	if (size <= 0)
		SetRetCode(DataErr);
	if (size > MaxSizeStack)
		SetRetCode(DataNoMem);
	else
	{
		pMem = (PTElem)p;
		MemSize = size;
		MemType = TMemType::MEM_RENTER;
		DataCount = 0;
	}
}
TStack::~TStack()
{
	delete[] pMem;
}

TStack::TStack(unsigned size)
{
	if (size > MaxSizeStack)
		SetRetCode(DataNoMem);
	else
	{
		MemSize = size;
		DataCount = 0;
		MemType = TMemType::MEM_HOLDER;
		pMem = new TElem[MemSize];
	}
}
bool TStack::IsFull() const
{
	if (DataCount == MemSize)
		return true;
	return false;
}
bool TStack::IsEmpty() const
{
	if (DataCount == 0)
		return true;
	return false;
}
int TStack::IsValid()
{
	if (RetCode == 0)
	{
		cout << "All is OK";
	}
	cout << "Error:" << endl << "Return Code = "<<RetCode;
	return RetCode;
}
void TStack::Put(const TData &Val)
{
	if (IsFull())
		SetRetCode(DataFull);
	else
	{
		pMem[DataCount] = Val;
		DataCount++;
	}
}
TData TStack::Get()
{
	if(!IsEmpty())
	{
		DataCount--;
		return pMem[DataCount];
	}
	else
	{
		SetRetCode(DataEmpty);
	}
	return 0;
}
void TStack::Print()
{
	for (int i = 0; i < DataCount; i++)
	{
		cout << pMem[i] << " ";
	}
	cout << endl;
}