#include "TBalanceNode.h"

TDatValue * TBalanceNode::GetCopy()
{
    if (pValue != nullptr)
        return static_cast<PTDatValue>
        (new TBalanceNode(key, pValue->GetCopy(), nullptr, nullptr, Balance));
    else return static_cast<PTDatValue>
        (new TBalanceNode(key, nullptr, nullptr, nullptr, Balance));
}

int TBalanceNode::GetBalance(void) const { return Balance; }

void TBalanceNode::SetBalance(int bal)
{
    switch (bal)
    {
    case BalOk : case BalLeft: case BalRight:
        Balance = bal;
        break;
    default:
        throw std::invalid_argument("Unsupported balance value");
    }
}
