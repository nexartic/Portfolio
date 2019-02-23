#ifndef DAT_LIST_H
#define DAT_LIST_H

#include "DatLink.h"

enum TLinkPos { FIRST, CURRENT, LAST };

typedef TDatList *PTDatList;

class TDatList
{
protected:
	PTDatLink pFirst;    // первое звено
	PTDatLink pLast;     // последнее звено
	PTDatLink pCurrLink; // текущее звено
	PTDatLink pPrevLink; // звено перед текущим
	PTDatLink pStop;     // значение указателя, означающего конец списка 
	int CurrPos;         // номер текущего звена (нумерация от 0)
	int ListLen;         // количество звеньев в списке
protected:
	PTDatLink GetLink(PTDatValue pVal = nullptr, PTDatLink pLink = nullptr);
	void DelLink(PTDatLink pLink);   // удаление звена
public:
	TDatList();
	~TDatList() { DelList(); }

	PTDatValue GetDatValue(TLinkPos mode = CURRENT) const;	   // значение
	virtual bool IsEmpty()  const { return pFirst == pStop; }  // список пуст?
	int GetListLength()    const { return ListLen; }		   // к-во звеньев
														   
	int SetCurrentPos(int pos);								// установить текущее звено
	int GetCurrentPos(void) const { return CurrPos; }       // получить номер тек. звена
	virtual int Reset(void);								// установить на начало списка
	virtual bool IsListEnded(void) const { return pCurrLink == pStop; }; // список завершен?
	int GoNext(void);                    // сдвиг вправо текущего звена
										 // (=1 после применения GoNext для последнего звена списка)
										 
	virtual void InsFirst(PTDatValue pVal = nullptr);	// перед первым
	virtual void InsLast(PTDatValue pVal = nullptr);	// вставить последним 
	virtual void InsCurrent(PTDatValue pVal = nullptr); // перед текущим 
													 
	virtual void DelFirst(void);     // удалить первое звено 
	virtual void DelCurrent(void);	 // удалить текущее звено 
	virtual void DelList(void);      // удалить весь список
};

#endif