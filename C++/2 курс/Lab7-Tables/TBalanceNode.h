#ifndef _TREE_NODE_H
#define _TREE_NODE_H

#include "TTreeNode.h"

#define BalOk 0
#define BalLeft -1
#define BalRight 1

class TBalanceNode;
typedef TBalanceNode *PTBalanceNode;

class TBalanceNode: public TTreeNode 
{
  protected: 
    int Balance;        // индекс балансировки вершины (-1, 0, 1)
  public:
    TBalanceNode (TKey k = "", PTDatValue pVal = nullptr, 
    PTTreeNode pL = nullptr, PTTreeNode pR = nullptr, int bal = BalOk) : 
    TTreeNode(k, pVal, pL, pR), Balance(bal) {}

    virtual TDatValue *GetCopy();
    int GetBalance(void) const;
    void SetBalance(int bal);
    friend class TBalanceTree;
};

#endif