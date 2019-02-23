###<p align="center">Министерство образования и науки Российской Федерации
####<p align="center">Государственное образовательное учреждение высшего профессионального образования «Нижегородский государственный университет им. Н.И. Лобачевского» </p>

<p align="center">
Институт информационных технологий, математики и механики
Кафедра программной инженерии  Специальность (направление): Программная инженерия  </p>  
<p align="center">
Специальность (направление): Программная инженерия </p>
 
<p align="center">
Отчет по Лабораторной работе № 2  
по дисциплине «Алгоритмы и структуры данных»</p>  

<p align="center">
тема:  
«Верхнетреугольные матрицы на шаблонах»</p>  

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
  +В рамках лабораторной работы ставится задача создания программных средств, поддерживающих эффективное хранение матриц специального вида (верхнетреугольных) и выполнение основных операций над ними:  
 1) сложение/вычитание;   
 2) копирование;  
 3) сравнение.  
Выполнение работы предполагает решение следующих задач:  

  1. Реализация методов шаблонного класса `TVector` согласно заданному интерфейсу.  
  2. Реализация методов шаблонного класса `TMatrix` согласно заданному интерфейсу.  
  3. Обеспечение работоспособности тестов и примера использования.  
  4. Реализация заготовок тестов, покрывающих все методы классов `TVector` и `TMatrix`.  
  5. Модификация примера использования в тестовое приложение, позволяющее задавать матрицы и осуществлять основные операции над ними.  

  </p>
  
  ###Вывод:
  
  Считаю , что справился с поставленной задачей, т.к сконструированные классы прошели все предоставленные тесты.
  Кроме того мои навыки владения фреймворком GoogleTest стали лучше.  
  .  
  <p align= "left">
  ###Код на языке С++:  
  ####TVector:    
  </p>
  
```
  template <class ValType>
class TVector
{
protected:
  ValType *pVector;
  int Size;       // размер вектора
  int StartIndex; // индекс первого элемента вектора
public:
  TVector(int s = 10, int si = 0);
  TVector(const TVector &v);                // конструктор копирования
  ~TVector();
  int GetSize()      { return Size;       } // размер вектора
  int GetStartIndex(){ return StartIndex; } // индекс первого элемента
  ValType& operator[](int pos);             // доступ
  bool operator==(const TVector &v) const;  // сравнение
  bool operator!=(const TVector &v) const;  // сравнение
  TVector& operator=(const TVector &v);     // присваивание

  // скалярные операции
  TVector  operator+(const ValType &val);   // прибавить скаляр
  TVector  operator-(const ValType &val);   // вычесть скаляр
  TVector  operator*(const ValType &val);   // умножить на скаляр

  // векторные операции
  TVector  operator+(const TVector &v);     // сложение
  TVector  operator-(const TVector &v);     // вычитание
  ValType  operator*(const TVector &v);     // скалярное произведение

  // ввод-вывод
  friend istream& operator>>(istream &in, TVector &v)
  {
    for (int i = 0; i < v.Size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend ostream& operator<<(ostream &out, const TVector &v)
  {
    for (int i = 0; i < v.Size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
	if (s <= 0 || si < 0 )
		throw NegativeIndex();
	if (s > MAX_VECTOR_SIZE)
		throw BigIndex();
	StartIndex = si;
	Size = s;
	pVector = new ValType[Size];

} 

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new ValType[Size];
	for (int i = 0; i < Size; i++)
	{
		pVector[i] = v.pVector[i];
	}
}

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[] pVector;
	pVector = nullptr;
} 

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
	pos -= StartIndex;
	if (pos < 0 )
		throw NegativeIndex();
	if (pos >= Size)
		throw BigIndex();
	return pVector[pos];
} 

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	if (this == &v)
		return true;
	if (Size != v.Size)
		return false;
	for (int i = 0; i < Size; i++)
	{
		if (pVector[i] != v.pVector[i])
			return false;
	}
	return true;
} 

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	if (*this == v)
		return false;
	return true;
} 

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if (this == &v )
		return *this;
	Size = v.Size;
	StartIndex = v.StartIndex;
	delete[] pVector;
	pVector = new ValType[Size];
	for (int i = 0; i < Size; i++)
	{
		pVector[i] = v.pVector[i];
	}
	return *this;
} 

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	TVector<ValType> buf(*this);
	for (int i = 0; i < Size; i++)
	{
		buf.pVector[i] += val;
	}
	return buf;
} 

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	TVector<ValType> buf(*this);
	for (int i = 0; i < Size; i++)
	{
		buf.pVector[i] -= val;
	}
	return buf;
} 

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	TVector<ValType> buf(*this);
	for (int i = 0; i < Size; i++)
	{
		buf.pVector[i] *= val;
	}
	return buf;
} 

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if (Size != v.Size)
		throw NotEqVector();
	TVector<ValType> buf(*this);
	for (int i = 0; i < Size; i++)
	{
		buf.pVector[i] = buf.pVector[i] + v.pVector[i];
	}
	return buf;
} 

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if (Size != v.Size)
		throw NotEqVector();
	TVector<ValType> buf(*this);
	for (int i = 0; i < Size; i++)
	{
		buf.pVector[i] = buf.pVector[i] - v.pVector[i];
	}
	return buf;
} 

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	if (Size != v.Size)
		throw NotEqVector();
	ValType answer = 0;
	for (int i = 0; i < Size; i++)
	{
		answer += (pVector[i] * v.pVector[i]);
	}
	return answer;
} 
``` 
####TMatrix : 
```
// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
  TMatrix(int s = 10);                           
  TMatrix(const TMatrix &mt);                    // копирование
  TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа
  bool operator==(const TMatrix &mt) const;      // сравнение
  bool operator!=(const TMatrix &mt) const;      // сравнение
  TMatrix& operator= (const TMatrix &mt);        // присваивание
  TMatrix  operator+ (const TMatrix &mt);        // сложение
  TMatrix  operator- (const TMatrix &mt);        // вычитание

  // ввод / вывод
  friend istream& operator>>(istream &in, TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      in >> mt.pVector[i];
    return in;
  }
  friend ostream & operator<<( ostream &out, const TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }
};




template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
	if (s > MAX_MATRIX_SIZE)
		throw BigIndex();
	for (int i = 0; i < s; i++)
	{
		this->pVector[i] = *(new TVector<ValType>(s - i,i));
	}
}
template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):TVector<TVector<ValType> >(mt)
{
	for (int i = 0; i < mt.Size; i++)
	{
		this->pVector[i] = *(new TVector<ValType>(mt.pVector[i]));
	}

}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):TVector<TVector<ValType> >(mt){}// все готово

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{	
	if (this->Size != mt.Size)
		return false;
	for (int i = 0; i < this->Size; i++)
	{
		if (this->pVector[i] != mt.pVector[i])
			return false;
	}
	return true;

} 

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	if (*this == mt)
		return false;
	return true;
} 

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	if (&mt == this)
		return *this;
	TVector<TVector<ValType>>::operator=(mt);
	return *this;
} 

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	if (this->Size != mt.Size)
		throw NotEqVector();
	TMatrix <ValType> matrix(*this);
	for (int i = 0; i < Size; i++)
	{
		matrix.pVector[i] = matrix.pVector[i] + mt.pVector[i];
	}
	return matrix;
}

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	if (this->Size != mt.Size)
		throw NotEqVector();
	TMatrix <ValType> matrix(*this);
	for (int i = 0; i < mt.Size; i++)
	{
		matrix.pVector[i] = matrix.pVector[i] - mt.pVector[i];
	}
	return matrix;

}
```





