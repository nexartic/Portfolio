#include"tdataroot.h"
const int MaxSizeStack = 10000; 
class TStack : public TDataRoot
{
public:
	void SetMem(void *p, int size);
	TStack(unsigned size);
	~TStack();
	bool IsEmpty() const ;
	bool IsFull() const ;
	void  Put(const TData &Val);
	TData Get(void);
	int IsValid();
	void Print();
	int GetDataCount() const
	{
		return DataCount;
	}
};