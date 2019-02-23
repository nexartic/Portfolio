#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

#include "TTabRecord.h"

class TTreeNode;
typedef TTreeNode *PTTreeNode;

class TTreeNode : public TTabRecord 
{
  protected: 
    PTTreeNode pLeft, pRight;
  public:
    TTreeNode(TKey k = "", PTDatValue pVal = nullptr, 
              PTTreeNode pL = nullptr, PTTreeNode pR = nullptr) :
              TTabRecord(k, pVal), pLeft(pL), pRight(pR) {}

    PTTreeNode GetLeft(void) const;
    PTTreeNode GetRight(void) const;
    virtual TDatValue* GetCopy() override;

    friend class TTreeTable;
    friend class TBalanceTree;
};

#endif