#include "TTreeTable.h"

void TTreeTable::DeleteTreeTab(PTTreeNode pNode)
{
    if (pNode == nullptr) return;
    if (pNode->pLeft != nullptr)
        DeleteTreeTab(pNode->pLeft);
    if (pNode->pRight != nullptr)
        DeleteTreeTab(pNode->pRight);
    if (pNode->pValue != nullptr)
        delete pNode->pValue;
    delete pNode;
    pNode = nullptr;
}

int TTreeTable::IsFull() const
{
    try { auto tmp = new TTreeNode(); delete tmp; }
    catch (...) { return true; }
    return false;
}

PTDatValue TTreeTable::FindRecord(TKey k)
{
    PTTreeNode cur = pRoot;
    ppRef = nullptr;
    Efficiency = 0;
    while (cur != nullptr)
    {
        Efficiency++;
        if (cur->key == k)
            return cur->GetValuePTR();
        else
        {
            ppRef = cur;
            if (cur->key > k) cur = cur->pLeft;
            else cur = cur->pRight;
        }
    }
    throw std::runtime_error("There is no record with specified key");
}

void TTreeTable::InsRecord(TKey k, PTDatValue pVal)
{
    if (IsFull())
        throw std::runtime_error("Table is full");

    try { FindRecord(k); }
    catch (...)
    {
        if (ppRef == nullptr)   // Tree table was empty
            pRoot = new TTreeNode(k, pVal);
        else
        {
            if (ppRef->key > k)
                ppRef->pLeft = new TTreeNode(k, pVal);
            else
                ppRef->pRight = new TTreeNode(k, pVal);
        }
        DataCount++;
        return;
    }

    throw std::runtime_error("Record with specified key already exists");
}

void TTreeTable::DelRecord(TKey k)
{
    try { FindRecord(k); }
    catch (...) { throw; }

    PTTreeNode stbd = nullptr;  // Supposed to be deleted

    if (ppRef == nullptr) stbd = pRoot;  // Root is supposed
                                         // to be deleted
    else
    {
        if (ppRef->key > k)
            stbd = ppRef->pLeft;
        else stbd = ppRef->pRight;
    }

    // 1st case: stbd doesn't have a child on the right
    // or stbd node is a leaf
    if (stbd->pRight == nullptr)
    {
        if (ppRef == nullptr)   // Deleting root
        {
            pRoot = stbd->pLeft;
            stbd->pLeft = nullptr;
            if (stbd->pValue != nullptr)
                delete stbd->pValue;
            delete stbd;
        }
        else
        {
            if (stbd == ppRef->pLeft)
                ppRef->pLeft = stbd->pLeft;
            else ppRef->pRight = stbd->pLeft;
            stbd->pLeft = nullptr;
            if (stbd->pValue != nullptr)
                delete stbd->pValue;
            delete stbd;
        }
    }

    // 2nd case: stbd node has a child on the right
    else
    {
        // Leftmost in the right subtree
        PTTreeNode lmrst = stbd->pRight;  

        ppRef = nullptr;
        while (lmrst->pLeft != nullptr)
        {
            ppRef = lmrst;
            lmrst = lmrst->pLeft;
        }
        if (ppRef != nullptr)
            ppRef->pLeft = lmrst->pRight;
        else stbd->pRight = lmrst->pRight;
        
        if (stbd->pValue != nullptr)
            delete stbd->pValue;
        stbd->pValue = lmrst->pValue;
        lmrst->pValue = nullptr;
        stbd->key = lmrst->key;
        delete lmrst;
    }
    DataCount--;
}

TKey TTreeTable::GetKey(void) const
{
    return (pCurrent == nullptr) ? TKey("") : pCurrent->key;
}

PTDatValue TTreeTable::GetValuePTR(void) const
{
    return (pCurrent == nullptr) ? nullptr : pCurrent->pValue;
}


// After applying this method
// pCurrent points to the leftmost tree node
int TTreeTable::Reset(void)
{
    while (!st.empty()) st.pop();
    PTTreeNode cur = pCurrent = pRoot;
    while (cur != nullptr)
    {
        st.push(cur);
        pCurrent = cur;
        cur = cur->pLeft;
    }
    return CurrPos = 0;
}

int TTreeTable::IsTabEnded(void) const
{
    return CurrPos == DataCount;
}

int TTreeTable::GoNext(void)
{
    // pCurrent == nullptr if tree is empty
    if (!IsTabEnded() && (pCurrent != nullptr))
    {
        PTTreeNode cur = pCurrent = pCurrent->pRight;
        st.pop();
        while (cur != nullptr)
        {
            st.push(cur);
            pCurrent = cur;
            cur = cur->pLeft;
        }

        // There is no right subtree or tree has ended
        if (pCurrent == nullptr && !st.empty())
            pCurrent = st.top();
        return ++CurrPos;
    }
    else return 1;
}
