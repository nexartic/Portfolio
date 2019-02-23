###<p align="center">Министерство образования и науки Российской Федерации
####<p align="center">Государственное образовательное учреждение высшего профессионального образования «Нижегородский государственный университет им. Н.И. Лобачевского» </p>

<p align="center">
Институт информационных технологий, математики и механики
Кафедра программной инженерии  Специальность (направление): Программная инженерия  </p>  
<p align="center">
Специальность (направление): Программная инженерия </p>
 
<p align="center">
Отчет по Лабораторной работе № 1  
по дисциплине «Алгоритмы и структуры данных»</p>  

<p align="center">
тема:  
«Битовое поле»</p>  

    -                                                    Выполнил:  
    -                                                    студент группы 381608-2  
    -                                                    Матясов Михаил Андреевич  
    -                                                    Подпись_________________  

              
    -                                                    Научный руководитель:  
    -                                                    Доцент, к.т.н. Штанюк А.А.  
    -                                                    Подпись_________________ 
    
    
    
<p align="center">    
Нижний Новгород  
2017 г. </p>

 .  
 .  
 ###Цели и задачи: 
 <p align = "left">
 1. Pазработка структуры данных для хранения множеств с использованием битовых полей.  
 2. Освоение таких инструментов разработки программного обеспечения, как система контроля версий Git и фрэймворк для разработки автоматических тестов Google Test.</p>  
 
 .  
##Описание работы:
 <p align = "left">
  1. В ходе данной работы я кратко ознакомился с синтаксисом фрэймворка GoogleTest. Научился подключать его к исходному проекту, а также редактировать исходный код тестов, кроме того мною было разработанно 2 класса:  
  a) Первый для работы с "Битовым полем"   
  б) Второй для работы с множествами. Стоит также отметить что,второй класс был разработан на основе "Битового поля"
  </p>
  
  ###Вывод:
  
  Считаю , что справился с поставленной задачей, т.к сконструированные классы прошели все предоставленные тесты.
  Кроме того мои навыки владения фреймворком GoogleTest стали лучше.  
  .  
  <p align= "left">
  ###Код на языке С++:  
  ####TBitField:  
  </p>
  
```
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
	*this = bf;
}
TBitField::~TBitField()
{
	//delete []pMem;
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
		return 1 << (((GetMemIndex(n) + 1)*sizeOfTelemInBit) - n);
	
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
	return (pMem[GetMemIndex(n)] & GetMemMask(n)) >> ((GetMemIndex(n)+1) *sizeOfTelemInBit - n);
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	if (bf == NULL)
	{
		cout << "Error: Empty Referense.";
		return *this;
	}
	MemLen = bf.MemLen;
	sizeOfTelemInBit = bf.sizeOfTelemInBit;
	if (bf.BitLen != BitLen)
	{
		//delete[]pMem;
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
	int size;
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
		max = bf.BitLen;
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

  ```
 #### Tset:
  ```
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
```





