#ifndef _TREE_TABLE_H_
#define _TREE_TABLE_H_

#include "TTable.h"
#include "TTreeNode.h"
#include <stack>

class TTreeTable : public TTable 
{
  protected: 
    PTTreeNode pRoot;     // указатель на корень дерева
    PTTreeNode ppRef;     // указатель на вершину-результата в FindRecord
    PTTreeNode pCurrent;  // указатель на текущую вершину
    int CurrPos;          // номер текущей вершины
    std::stack<PTTreeNode> st;  // стек для итератора

    void DeleteTreeTab(PTTreeNode pNode);

  public:
    TTreeTable() : TTable(), CurrPos(0), pRoot(nullptr), pCurrent(nullptr), ppRef(nullptr) {}   
    ~TTreeTable() { DeleteTreeTab(pRoot); }

    // информационные методы
    virtual int IsFull() const;

    // основные методы
    virtual PTDatValue FindRecord(TKey k);
    virtual void InsRecord(TKey k, PTDatValue pVal);
    virtual void DelRecord(TKey k);

    // навигация
    virtual TKey GetKey(void) const;
    virtual PTDatValue GetValuePTR(void) const;
    virtual int Reset(void);
    virtual int IsTabEnded(void) const;
    virtual int GoNext(void);   //(=1 после применения для последней записи таблицы)
};

#endif