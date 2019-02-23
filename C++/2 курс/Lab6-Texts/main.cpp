#include <iostream>
#include "TText.h"

int main()
{

    TTextLink::InitMemSystem(14);
    TText text;
    text.Read((char*)"input.txt");

    text.GoFirstLink();               
    text.GoDownLink();                 
    text.GoDownLink();                               

	text.DelDownLine();

    text.GoFirstLink();                
    text.GoNextLink();                 
    text.DelDownSection();              
                                        
    TTextLink::MemCleaner(text);


    TTextLink::PrintFreeLink();

    text.GoFirstLink();                  
    text.GoNextLink();                   
    text.GoNextLink();                   
    text.InsDownSection("String");  

    text.Print();
    text.Write((char*)"output.txt");
}