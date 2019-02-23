#ifndef _TEXT_
#define _TEXT_

#include "tdatacom.h"
#include "TTextLink.h"
#include <stack>
#include <string>
#include <fstream>

class TText;
typedef TText *PTText;

class TText : public TDataCom
{
protected:
    PTTextLink pFirst;                                    // указатель корня дерева
    PTTextLink pCurrent;                                  // указатель текущей строки
    stack< PTTextLink > Path;                             // стек траектории движения по тексту
    stack< PTTextLink > St;                               // стек для итератора
    PTTextLink GetFirstAtom(PTTextLink pl);              // поиск первого атома
    void PrintText(PTTextLink ptl);                      // печать текста со звена ptl
    void PrintTextFile(PTTextLink ptl, ofstream& TxtFile);
    PTTextLink ReadText(ifstream& TxtFile);               // чтение текста из файла
    static int TextLevel;
public:
    TText(PTTextLink pl = nullptr);
    ~TText() { pFirst = nullptr; }
    // навигация
    int GoFirstLink(void);            // переход к первой строке
    int GoDownLink(void);             // переход к следующей строке по Down
    int GoNextLink(void);             // переход к следующей строке по Next
    int GoPrevLink(void);             // переход к предыдущей позиции в тексте
                                       // доступ
    string GetLine(void);               // чтение текущей строки
    void SetLine(string str);         // замена текущей строки 
                                      // модификация
    void InsDownLine(string str);      // вставка строки в подуровень
    void InsDownSection(string str);   // вставка раздела в подуровень
    void InsNextLine(string str);      // вставка строки в том же уровне
    void InsNextSection(string str);   // вставка раздела в том же уровне
    void DelDownLine(void);            // удаление строки в подуровне
    void DelDownSection(void);         // удаление раздела в подуровне
    void DelNextLine(void);            // удаление строки в том же уровне
    void DelNextSection(void);         // удаление раздела в том же уровне
                                       // итератор
    int Reset(void);                  // установить на первую запись
    bool IsTextEnded(void) const;      // текст завершен?
    bool GoNext(void);                 // переход к следующей записи
                                       //работа с файлами
    void Read(char* pFileName);        // ввод текста из файла
    void Write(char* pFileName);       // вывод текста в файл
                                       //печать
    void Print(void);                  // печать текста
};

#endif 