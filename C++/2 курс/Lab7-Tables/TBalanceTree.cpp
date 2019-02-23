#include "TBalanceTree.h"

int TBalanceTree::InsBalanceTree(PTBalanceNode& pNode, TKey k, PTDatValue pVal)
{
    bool hhi = false;   // Height has increased

    if (pNode == nullptr)
    {
        pNode = new TBalanceNode(k, pVal);
        hhi = true;
        DataCount++;
    }

    else if (pNode->key > k)
    {
        if (InsBalanceTree((PTBalanceNode&)(pNode->pLeft), k, pVal))
            hhi = LTInsBalancing(pNode);
    }


    else if (pNode->key < k)
    {
        if (InsBalanceTree((PTBalanceNode&)(pNode->pRight), k, pVal))
            hhi = RTInsBalancing(pNode);
    }

    else
        throw std::runtime_error("Record with specified key already exists");

    return hhi;
}

int TBalanceTree::LTInsBalancing(PTBalanceNode& pNode)
{
    bool hhi = false;
    switch (pNode->Balance)
    {
    case BalRight:
        pNode->SetBalance(BalOk);
        hhi = false;
        break;
    case BalOk:
        pNode->SetBalance(BalLeft);
        hhi = true;
        break;
    case BalLeft:
        auto lc = static_cast<PTBalanceNode>(pNode->pLeft);  // Left subtree
        if (lc->Balance == BalLeft)
        {
            RightRotation(pNode, lc);
            pNode->SetBalance(BalOk);
            pNode = lc;
        }
        else
        {
            auto rc = static_cast<PTBalanceNode>(lc->pRight);  // lc's right subtree
            LeftRightRotation(pNode, lc, rc);

            if (rc->Balance == BalLeft)
                lc->SetBalance(BalRight);
            else lc->SetBalance(BalOk);

            if (rc->Balance == BalRight)
                pNode->SetBalance(BalLeft);
            else pNode->SetBalance(BalOk);

            pNode = rc;
        }
        pNode->SetBalance(BalOk);
        hhi = false;
        break;
    }
    return hhi;
}

int TBalanceTree::RTInsBalancing(PTBalanceNode& pNode)
{
    bool hhi = false;
    switch (pNode->Balance)
    {
    case BalLeft:
        pNode->SetBalance(BalOk);
        hhi = false;
        break;
    case BalOk:
        pNode->SetBalance(BalRight);
        hhi = true;
        break;
    case BalRight:
        auto rc = static_cast<PTBalanceNode>(pNode->pRight);  // Right subtree
        if (rc->Balance == BalRight)
        {
            LeftRotation(pNode, rc);
            pNode->SetBalance(BalOk);
            pNode = rc;
        }
        else
        {
            auto lc = static_cast<PTBalanceNode>(rc->pLeft); // rc's left subtree
            RightLeftRotation(pNode, lc, rc);

            if (lc->Balance == BalRight)
                rc->SetBalance(BalLeft);
            else rc->SetBalance(BalOk);

            if (lc->Balance == BalLeft)
                pNode->SetBalance(BalRight);
            else pNode->SetBalance(BalOk);

            pNode = lc;
        }
        pNode->SetBalance(BalOk);
        hhi = false;
        break;
    }
    return hhi;
}

bool TBalanceTree::DelBalanceTree(PTBalanceNode& pNode, TKey k)
{
    bool hhd = false;  // Height has decreased

    if (pNode == nullptr)
        throw std::runtime_error("There is no record with specified key");

    else if (k < pNode->key)
    {
        if (DelBalanceTree((PTBalanceNode&)pNode->pLeft, k))
            hhd = RTDelBalancing(pNode);
    }

    else if (k > pNode->key)
    {
        if (DelBalanceTree((PTBalanceNode&)pNode->pRight, k))
            hhd = LTDelBalancing(pNode);
    }

    else  // pNode->key == k
    {
        auto tmp = pNode;
        if (tmp->pRight == nullptr)
        {
            pNode = static_cast<PTBalanceNode>(tmp->pLeft);
            hhd = true;
        }
        else if (tmp->pLeft == nullptr)
        {
            pNode = static_cast<PTBalanceNode>(tmp->pRight);
            hhd = true;
        }
        else
        {
           if (DelNode((PTBalanceNode&)tmp->pLeft, tmp))
               hhd = RTDelBalancing(pNode);
        }
        DataCount--;
    }
}

bool TBalanceTree::RTDelBalancing(PTBalanceNode& pNode)
{
    bool hhd = true;

    switch (pNode->Balance)
    {
    case BalLeft:
        pNode->SetBalance(BalOk);
        break;
    case BalOk:
        pNode->SetBalance(BalRight);
        hhd = false;
        break;
    case BalRight:
        auto rc = static_cast<PTBalanceNode>(pNode->pRight);  // Right subtree
        if (rc->Balance >= 0)
        {
            LeftRotation(pNode, rc);
            if (rc->Balance == BalOk)
            {
                pNode->SetBalance(BalRight);
                rc->Balance = BalLeft;
                hhd = false;
            }
            else
            {
                pNode->Balance = BalOk;
                rc->Balance = BalOk;
            }
            pNode = rc;
        }
        else
        {
            auto lc = static_cast<PTBalanceNode>(rc->pLeft);  // rc's left subtree
            RightLeftRotation(pNode, lc, rc);

            if (lc->Balance == BalRight) pNode->SetBalance(BalLeft);
            else pNode->SetBalance(BalOk);
            if (lc->Balance == BalLeft) rc->SetBalance(BalRight);
            else rc->SetBalance(BalOk);

            pNode = lc;
            lc->SetBalance(BalOk);
        }
    }
    return hhd;
}

bool TBalanceTree::LTDelBalancing(PTBalanceNode& pNode)
{
    bool hhd = true;

    switch (pNode->Balance)
    {
    case BalRight:
        pNode->SetBalance(BalOk);
        break;
    case BalOk:
        pNode->SetBalance(BalLeft);
        hhd = false;
        break;
    case BalLeft:
        auto lc = static_cast<PTBalanceNode>(pNode->pLeft);  // Left subtree
        if (lc->Balance <= 0)
        {
            RightRotation(pNode, lc);
            if (lc->Balance == BalOk)
            {
                pNode->SetBalance(BalLeft);
                lc->SetBalance(BalRight);
                hhd = false;
            }
            else
            {
                pNode->SetBalance(BalOk);
                lc->SetBalance(BalOk);
            }
            pNode = lc;
        }
        else
        {
            auto rc = static_cast<PTBalanceNode>(lc->pRight);  // lc's right subtree
            LeftRightRotation(pNode, lc, rc);

            if (rc->Balance == BalLeft) pNode->SetBalance(BalRight);
            else pNode->SetBalance(BalOk);
            if (rc->Balance == BalRight) lc->SetBalance(BalLeft);
            else lc->SetBalance(BalOk);

            pNode = rc;
            rc->SetBalance(BalOk);
        }
    }
    return hhd;
}

bool TBalanceTree::DelNode(PTBalanceNode& pNode, PTBalanceNode& pParent)
{
    bool hhd = false;

    if (pNode->pRight != nullptr)
    {
        if (DelNode((PTBalanceNode&)pNode->pRight, pParent))
            hhd = LTDelBalancing(pNode);
    }
    else
    {
        delete pParent->pValue;
        pParent->key = pNode->key;
        pParent->pValue = pNode->pValue;
        pNode->pValue = nullptr;
        pNode = static_cast<PTBalanceNode>(pNode->pLeft);
        hhd = true;
    }
    return hhd;
}

void TBalanceTree::InsRecord(TKey k, PTDatValue pVal)
{
    if (IsFull())
        throw std::runtime_error("Table is full");

    InsBalanceTree((PTBalanceNode&)pRoot, k, pVal);
}

void TBalanceTree::DelRecord(TKey k)
{
    if (IsEmpty())
        throw std::runtime_error("Table is empty");

    DelBalanceTree((PTBalanceNode&)pRoot, k);
}

void TBalanceTree::RightRotation(PTBalanceNode& pNode, PTBalanceNode& lc)
{
    pNode->pLeft = lc->pRight;
    lc->pRight = pNode;
}

void TBalanceTree::LeftRightRotation(PTBalanceNode& pNode, PTBalanceNode& lc, PTBalanceNode& rc)
{
    lc->pRight = rc->pLeft;
    rc->pLeft = lc;
    pNode->pLeft = rc->pRight;
    rc->pRight = pNode;
}

void TBalanceTree::LeftRotation(PTBalanceNode& pNode, PTBalanceNode& rc)
{
    pNode->pRight = rc->pLeft;
    rc->pLeft = pNode;
}

void TBalanceTree::RightLeftRotation(PTBalanceNode& pNode, PTBalanceNode& lc, PTBalanceNode& rc)
{
    rc->pLeft = lc->pRight;
    lc->pRight = rc;
    pNode->pRight = lc->pLeft;
    lc->pLeft = pNode;
}

