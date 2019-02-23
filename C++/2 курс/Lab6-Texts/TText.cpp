#include "TText.h"
#include <fstream>

int TText::TextLevel;

PTTextLink TText::GetFirstAtom(PTTextLink pl)
{
    while (!pl->IsAtom())
    {
        St.push(pl);
        pl = pl->GetDown();
    }
    return PTTextLink();
}

void TText::PrintText(PTTextLink ptl)
{
    if (ptl != nullptr)
    {
        for (int i = 0; i < TextLevel; i++)
            cout << "  ";
        cout << "    " << ptl->Str << endl;
        TextLevel++;
        PrintText(ptl->GetDown());
        TextLevel--;
        PrintText(ptl->GetNext());
    }
}

void TText::PrintTextFile(PTTextLink ptl, ofstream & TxtFile)
{
    if (ptl != nullptr)
    {
        for (int i = 0; i < TextLevel; i++)
            TxtFile << " ";
        TxtFile << " " << ptl->Str << endl;
        TextLevel++;
        PrintTextFile(ptl->GetDown(), TxtFile);
        TextLevel--;
        PrintTextFile(ptl->GetNext(), TxtFile);
    }
}

PTTextLink TText::ReadText(ifstream& input)
{
    PTTextLink ptl = new TTextLink();
    PTTextLink tmp = ptl;
	string buf;
    while (!input.eof())
    {
        std::getline(input,buf);
        if (buf.front() == '}')
            break;
        else if (buf.front() == '{')
            ptl->pDown = ReadText(input);
        else
        {
            ptl->pNext = new TTextLink(buf.c_str());
            ptl = ptl->pNext;
        }
    }
    ptl = tmp;
    if (tmp->pDown == nullptr)
    {
        tmp = tmp->pNext;
        delete ptl;
    }
    return tmp;
}

TText::TText(PTTextLink pl)
{
	if (pl == nullptr)
		pFirst = new TTextLink();
	else
		pFirst = pl;
}


int TText::GoFirstLink(void)
{
    while (!Path.empty())
        Path.pop();
    pCurrent = pFirst;
    if (pCurrent == nullptr)
        SetRetCode(TextErr);
    return RetCode;
}

int TText::GoDownLink(void)
{
    if (pCurrent->GetDown() == nullptr)
        SetRetCode(TextNoDown);
    else
    {
        Path.push(pCurrent);
        pCurrent = pCurrent->GetDown();

    }
    return RetCode;
}

int TText::GoNextLink(void)
{
    if (pCurrent->GetNext() == nullptr)
        SetRetCode(TextNoNext);
    else
    {
        Path.push(pCurrent);
        pCurrent = pCurrent->GetNext();
    }
    return RetCode;
}

int TText::GoPrevLink(void)
{
    if (pCurrent == pFirst)
        SetRetCode(TextNoPrev);
    else
    {
        pCurrent = Path.top();
        Path.pop();
    }
    return RetCode;
}


string TText::GetLine(void)
{
	string result = pCurrent->Str;
	return result;
}

void TText::SetLine(string str)
{
    strcpy(pCurrent->Str, str.c_str());
}


void TText::InsDownLine(string str)
{
    if (pCurrent == nullptr)
        SetRetCode(TextErr);
    else
    {
        TStr buf;
        strcpy(buf, str.c_str());
        pCurrent->pDown = new TTextLink(buf, pCurrent->pDown, nullptr);
    }
}

void TText::InsDownSection(string str)
{
    if (pCurrent == nullptr)
        SetRetCode(TextErr);
    else
    {
        TStr buf;
        strcpy(buf, str.c_str());
        pCurrent->pDown = new TTextLink(buf, nullptr, pCurrent->pDown);
    }
}

void TText::InsNextLine(string str)
{
    if (pCurrent == nullptr)
        SetRetCode(TextErr);
    else
    {
        TStr buf;
        strcpy(buf, str.c_str());
        pCurrent->pNext = new TTextLink(buf, pCurrent->pNext, nullptr);
    }
}

void TText::InsNextSection(string str)
{
    if (pCurrent == nullptr)
        SetRetCode(TextErr);
    else
    {
        TStr buf;
        strcpy(buf, str.c_str());
        pCurrent->pNext = new TTextLink(buf, nullptr, pCurrent->pNext);
    }
}

void TText::DelDownLine(void)
{
    if (pCurrent == nullptr)
        SetRetCode(TextErr);
    else if (pCurrent->pDown == nullptr)
        SetRetCode(TextNoDown);
    else if (pCurrent->pDown->IsAtom())
        pCurrent->pDown = pCurrent->pDown->pNext;
}

void TText::DelDownSection(void)
{
    if (pCurrent == nullptr)
        SetRetCode(TextErr);
    else if (pCurrent->pDown == nullptr)
        SetRetCode(TextNoDown);
    else
        pCurrent->pDown = nullptr;
}

void TText::DelNextLine(void)
{
    if (pCurrent == nullptr)
        SetRetCode(TextErr);
    else if (pCurrent->pNext == nullptr)
        SetRetCode(TextNoNext);
    else if (pCurrent->pNext->IsAtom())
        pCurrent->pNext = pCurrent->pNext->pNext;

}

void TText::DelNextSection(void)
{
    if (pCurrent == nullptr)
        SetRetCode(TextErr);
    else if (pCurrent->pNext == nullptr)
        SetRetCode(TextNoNext);
    else
        pCurrent->pNext = pCurrent->pNext->pNext;
}

int TText::Reset(void)
{
    GoFirstLink();
    if (pCurrent != nullptr)
    {
        St.push(pCurrent);
        if (pCurrent->pNext != nullptr)
            St.push(pCurrent->pNext);
        if (pCurrent->pDown != nullptr)
            St.push(pCurrent->pDown);
    }
    return RetCode;
}

bool TText::IsTextEnded(void) const
{
    return St.empty();
}

bool TText::GoNext(void)
{
    if (!IsTextEnded())
    {
        pCurrent = St.top();
        St.pop();
        if (pCurrent != pFirst)
        {
            if (pCurrent->pNext != nullptr)
                St.push(pCurrent->pNext);
            if (pCurrent->pDown != nullptr)
                St.push(pCurrent->pDown);
        }

    }
    return IsTextEnded();
}

void TText::Read(char * pFileName)
{
    ifstream TextFile(pFileName);
    TextLevel = 0;
    if (TextFile)
        pFirst = ReadText(TextFile);
}

void TText::Write(char * pFileName)
{
    TextLevel = 0;
    ofstream output(pFileName);
    PrintTextFile(pFirst, output);
}

void TText::Print(void)
{
    TextLevel = 0;
    PrintText(pFirst);
}