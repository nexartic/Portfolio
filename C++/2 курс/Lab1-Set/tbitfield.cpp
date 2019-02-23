#include "tbitfield.h"

TBitField::TBitField(int len)
{
	if (len < 0)
		throw NegativeIndex();
	sizeOfTelemInBit = sizeof(TELEM) * 8;
	if (len % sizeOfTelemInBit == 0)
	{
		MemLen = len / sizeOfTelemInBit;
	}
	else
	{
		MemLen = len / sizeOfTelemInBit + 1;
		
	}
	BitLen = len;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++)
	{
		pMem[i] = 0;
	}
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	MemLen = bf.MemLen;
	BitLen = bf.BitLen;
	sizeOfTelemInBit = bf.sizeOfTelemInBit;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++)
	{
		pMem[i] = bf.pMem[i];
	}
}

TBitField::~TBitField()
{
	delete[] pMem;
	pMem = nullptr;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
		if (n%sizeOfTelemInBit == 0)// начиная с нулевого битаы
		{
			return (n / sizeOfTelemInBit);
		}
		else
		{
			return (n / sizeOfTelemInBit);
		}
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	if (n < 0)
		throw NegativeIndex();
	if (n > BitLen)
	{
		throw BigIndex();
	}
		return 1 << (((GetMemIndex(n) + 1)*sizeOfTelemInBit) - (n+1));//n+1 !!!!
	
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if (n < 0)
		throw NegativeIndex();
	if (n > BitLen)
	{
		throw BigIndex();
	}
	pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if (n < 0)
		throw NegativeIndex();
	if (n > BitLen)
	{
		throw BigIndex();
	}
	pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if (n < 0)
		throw NegativeIndex();
	if (n > BitLen)
	{
		throw BigIndex();
	}
	return (pMem[GetMemIndex(n)] & GetMemMask(n)) >> ((GetMemIndex(n)+1) *sizeOfTelemInBit - (n+1));//n+1 !!!!
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	if (&bf == this)
		throw NegativeIndex();
	MemLen = bf.MemLen;
	sizeOfTelemInBit = bf.sizeOfTelemInBit;
	if (bf.BitLen != BitLen)
	{
		delete[] pMem;
		pMem = nullptr;
		pMem = new TELEM[bf.MemLen];		
	}
	for (int i = 0; i < bf.MemLen; i++)
	{
		pMem[i] = bf.pMem[i];
	}
	BitLen = bf.BitLen;
	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
	if (BitLen != bf.BitLen)// сначала по длине не зависимо от значений, даже если в большем все 0
		return 0;
	for (int i = 1; i <= BitLen; i++)// Если длина равна
	{
		if (GetBit(i) != bf.GetBit(i))
			return 0;
	}
	return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
	if (*this == bf)
		return 0;
	return 1;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	TBitField *buf;
	int size = 0;
	if (BitLen > bf.BitLen)
	{
		buf = new TBitField(*this);
		size = bf.MemLen;
	}
	else
	{
		buf = new TBitField(bf);
		size = MemLen;
	}
	for (int i = 0; i < size; i++)
		buf->pMem[i] = bf.pMem[i] | pMem[i];
	return *buf;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	TBitField *buf;
	int min, max;
	if (BitLen > bf.BitLen)
	{
		buf = new TBitField(*this);
		min = bf.MemLen;
		max = MemLen;
	}
	else
	{
		buf = new TBitField(bf);
		min = MemLen;
		max = bf.MemLen;
	}
	for (int i = 0; i < min; i++)
		buf->pMem[i] = bf.pMem[i] & pMem[i];
	for (int i = min; i < max; i++)
		buf->pMem[i] = 0;
	return *buf;
}

TBitField TBitField::operator~(void) // отрицание
{
	for (int i = 0,j = 0; i < BitLen; i++)
	{
		pMem[j] ^= GetMemMask(i);
		if (i % (sizeOfTelemInBit - 1) == 0)
			j++;
		if (i == 0)
			j--;
	}
	return *this;
}

// ввод/вывод

istream &operator>>(istream &input, TBitField &bf) // ввод
{
	string buf,buf2;
	int countDigits = 0;
	input >> buf;
	if (buf.size() != bf.MemLen)
	{
		for (unsigned i = 0,  j = 0; i < buf.size(); i++)
		{
			if (buf[i] >= '0' && buf[i] <= '9')
			{
				countDigits++;
				buf2[j] = buf[i];
			}
		}
		delete[] bf.pMem;
		bf.pMem = nullptr;
		bf.pMem = new TELEM[countDigits];
		bf.sizeOfTelemInBit = sizeof(TELEM) * 8;
		bf.BitLen = countDigits*bf.sizeOfTelemInBit;
		bf.MemLen = countDigits;
	}
	for (unsigned i = 0; i < buf2.size(); i++)
	{
		bf.pMem[i] = buf2[i] - '0';
	}
	return input;
}

ostream &operator<<(ostream &output, const TBitField &bf) // вывод
{
	output << "Count of bits = " << bf.BitLen << endl;
	output << "Size of Mass = " << bf.MemLen << endl;
	output << "Size of Telem in bit = " << bf.sizeOfTelemInBit << endl;
	for (int i = 1; i <= bf.BitLen; i++)
	{
		output << bf.GetBit(i);
		if (i%bf.sizeOfTelemInBit == 0)
			output << "  ";
	}
	return output;
}
