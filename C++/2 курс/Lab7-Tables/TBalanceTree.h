#ifndef _BALANCE_TREE_H_
#define _BALANCE_TREE_H_

#include "TTreeTable.h"
#include "TBalanceNode.h"


class TBalanceTree : public TTreeTable
{
protected:
    int InsBalanceTree(PTBalanceNode& pNode, TKey k, PTDatValue pVal);
    bool DelBalanceTree(PTBalanceNode& pNode, TKey k);

    int LTInsBalancing(PTBalanceNode& pNode);  // Баланс. левого поддерева при вставке
    int RTInsBalancing(PTBalanceNode& pNode);  // Баланс. правого поддерева при вставке

    bool RTDelBalancing(PTBalanceNode& pNode);  // Баланс. правого поддерева при удалении
    bool LTDelBalancing(PTBalanceNode& pNode);  // Баланс. левого поддерева при удалении
    bool DelNode(PTBalanceNode& pNode, PTBalanceNode& pParent);

public:
    TBalanceTree() : TTreeTable() {}

    // Основные методы
    virtual void InsRecord(TKey k, PTDatValue pVal);   // Вставка
    virtual void DelRecord(TKey k);                    // Удаление

private:
    void RightRotation(PTBalanceNode& pNode, PTBalanceNode& lc);
    void LeftRightRotation(PTBalanceNode& pNode, PTBalanceNode& lc, PTBalanceNode& rc);
    void LeftRotation(PTBalanceNode& pNode, PTBalanceNode& rc);
    void RightLeftRotation(PTBalanceNode& pNode, PTBalanceNode& lc, PTBalanceNode& rc);
};

#endif
