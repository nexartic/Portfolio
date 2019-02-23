#define _CRT_SECURE_NO_WARNINGS

#ifndef _LINK_
#define _LINK_

#include "tdatvalue.h"
#include <cstring>
#include <iostream>

using namespace std;

const int TextLineLength = 40;

class TText;
class TTextLink;

typedef TTextLink* PTTextLink;
typedef char TStr[TextLineLength];

class TTextMem
{
    PTTextLink pFirst;                       // указатель на первое звено
    PTTextLink pLast;                        // указатель на последнее звено
    PTTextLink pFree;                        // указатель на первое свободное звено
    TTextMem() : pFirst(nullptr), pLast(nullptr), pFree(nullptr) {};
    friend class TTextLink;
};
typedef TTextMem *PTTextMem;

class TTextLink : public TDatValue
{
protected:
    TStr Str;                                 // поле для хранения строки текста
    PTTextLink pNext, pDown;                  // указатели по тек. уровень и на подуровень
    static TTextMem MemHeader;                // система управления памятью
public:
    static void InitMemSystem(int size);     // инициализация памяти
    static void PrintFreeLink(void);         // печать свободных звеньев
    void * operator new (size_t size);        // выделение звена
    void operator delete (void *pM);          // освобождение звена
    static void MemCleaner(TText &txt);      // сборка мусора
	TTextLink(TStr s = nullptr, PTTextLink pn = nullptr, PTTextLink pd = nullptr);
	TTextLink(string s);
    ~TTextLink() {}
    int IsAtom() { return pDown == nullptr; }   // проверка атомарности звена
    PTTextLink GetNext() { return pNext; }       // переход к следующему звену
    PTTextLink GetDown() { return pDown; }       // переход на подуровень
    PTDatValue GetCopy() { return new TTextLink(Str, pNext, pDown); }
    friend class TText;
};

#endif 
