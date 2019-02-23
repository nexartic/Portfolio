// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
	if (mp < 0)
		throw NegativeIndex();
	MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
	MaxPower = s.MaxPower;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf)
{
	MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
	return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
	return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
	if (MaxPower != s.MaxPower)
		return 0;
	int thisCount = 0, otherCount = 0;
	for (int i = 0; i < MaxPower; i++)
	{
		if (BitField.GetBit(i) != s.BitField.GetBit(i))
			return 0;
	}
	return 1;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
	if (*this == s)
		return 0;
	return 1;
}

TSet TSet::operator+(const TSet &s) // объединение
{
	int size;
	if (MaxPower > s.MaxPower)
		size = MaxPower;
	else
		size = s.MaxPower;
	TSet *set = new TSet(size);
	set->BitField = BitField | s.BitField;
	return *set;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	if (Elem > MaxPower)
		throw BigIndex();
	TSet *set = new TSet(*this);
	if (set->IsMember(Elem) == 0)
		set->InsElem(Elem);
	return *set;
}
TSet TSet::operator-(const int Elem) // разность с элементом
{
	TSet *set = new TSet(*this);
	if (set->IsMember(Elem))
		set->DelElem(Elem);
	return *set;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
	int size;
	if (MaxPower > s.MaxPower)
		size = MaxPower;
	else
		size = s.MaxPower;
	TSet *set = new TSet(size);
	set->BitField = BitField & s.BitField;
	return *set;
}

TSet TSet::operator~(void) // дополнение
{
	TSet *set = new TSet(MaxPower);
	set->BitField = ~BitField;
	return *set;
}

// перегрузка ввода/вывода

istream &operator>>(istream &input, TSet &s) // ввод
{
	string buf;
	input >> buf;
	TBitField *field;
	int count = 0;
	for (unsigned i = 0; i < buf.size(); i++)
	{
		if (buf[i] >= '0' || buf[i] <= '9')
		{
			count++;
		}
	}
	field = new TBitField(count);
	s.MaxPower = count;
	count = 0;
	for (unsigned i = 0; i < buf.size(); i++)
	{
		if (buf[i] == '0' || buf[i] == '1')
		{
			if (buf[i] == '0')
			{
				field->ClrBit(count);
			}
			else if (buf[i] == '1')
			{
				field->SetBit(count);
			}
			count++;
		}
	}
	s.BitField = *field;
	return input;
}

ostream& operator<<(ostream &output, const TSet &s) // вывод
{
	output << "Max Power :" << s.MaxPower << endl;
	for (int i = 0; i < s.BitField.GetLength(); i++)
	{
		output << s.BitField.GetBit(i);
	}
	output << endl;
	return output;
}
