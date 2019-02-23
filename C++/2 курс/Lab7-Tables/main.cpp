#include "Interaction.h"
#include "TScanTable.h"
#include "TSortTable.h"
#include "TTreeTable.h"
#include "TBalanceTree.h"
#include "TListHash.h"
#include "TArrayHash.h"

int main()
{
    TScanTable stud;
    read(stud, "input1.txt");
    print(stud);
    std::cout << "\nAmount execellent students = " << get_excellent_students_num(stud);
    std::cout << "\nGroup medium mark = " << GetMediumGroupMark(stud) << std::endl;
    std::cout << std::endl;

    TListHash hash;
	std::cout << "\n-------------------------------------------------------------\n";
    read(hash, "input2.txt");
    print(hash);
    std::cout << "\nNumber of excellent students = " << get_excellent_students_num(hash);
    std::cout << "\nGroup average mark = " << GetMediumGroupMark(hash) << std::endl;

    std::cout << "\n-------------------------------------------------------------" << std::endl;
    std::cout << "\nCount of excellent students at all groups = " << get_excellent_num_among_all_groups(stud, hash) << std::endl;
    std::cout << "Medium mark at all groups = " << get_avg_mark_among_all_groups(stud, hash) << std::endl;

    std::cout << std::endl;
	system("pause");
    return 0;
}