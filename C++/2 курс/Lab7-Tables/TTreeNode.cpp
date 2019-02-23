#include "TTreeNode.h"

PTTreeNode TTreeNode::GetLeft(void) const
{
    return pLeft;
}

PTTreeNode TTreeNode::GetRight(void) const
{
    return pRight;
}

TDatValue* TTreeNode::GetCopy()
{
    if (pValue != nullptr)
        return static_cast<PTDatValue>
        (new TTreeNode(key, pValue->GetCopy(), nullptr, nullptr));
    else return static_cast<PTDatValue>
        (new TTreeNode(key, nullptr, nullptr, nullptr));
}
