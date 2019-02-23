#include<iostream>
template <class T>
class MyStack
{
	T* pMem;      
	int MemSize;
	int DataCount;
public:
	MyStack(int size = 10)
	{
		MemSize = size;
		DataCount = 0;
		pMem = new T[size];
	}
	void  Put(const T &Val);
	T Get(void);
	bool IsEmpty() const;
	bool IsFull() const;
};

template <class T>
void MyStack<T>::Put(const T &Val)
{
	pMem[DataCount++] = Val;
}
template <class T>
T MyStack<T>:: Get()
{
	return pMem[--DataCount];
}

template <class T>
bool MyStack<T>::IsEmpty() const
{
		if (DataCount == 0)
			return true;
		return false;
}
template <class T>
bool MyStack<T>::IsFull() const
{
	if (DataCount == MemSize)
			return true;
		return false;
}