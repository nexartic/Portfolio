#include"mpi.h"
#include<iostream>
#include<string>
#include<time.h>

using namespace std;

char* SplitString(char* str, int proc_num, int proc_rank, int& lenght) {

	proc_num--;
	proc_rank--;

	if (lenght > proc_num) {

		int remains = lenght % proc_num;
		lenght = lenght / proc_num + (proc_rank < remains);

		int start = proc_rank * (lenght / proc_num) + proc_rank * (proc_rank < remains);
		return &str[start];
	}
	else
	{
		int len = lenght;
		char* null = nullptr;
		lenght = 1;
		return (proc_rank < len) ? &str[proc_rank] : (char*)nullptr;
	}


}



int Check(char* str1, char* str2, int lenght) {
	if (str1 == (char*)nullptr)
		return 1;

	for (int i = 0; i < lenght; i++) {
		if ((int)str1[i] < (int)str2[i])
			return 0;
		if ((int)str1[i] > (int)str2[i])
			return 1;
	}
	return 2;
}

void FillString(char* str1, char* str2, int size) {
	for (int i = 0; i < size; i++) {
		str1[i] = rand() % 25 + 'a';
		str2[i] = rand() % 25 + 'a';
	}
}

void Print(char* str, int size) {
	for (int i = 0; i < size; i++) {
		cout << str[i];
	}
	cout << endl;
}

void PrintResult(bool result) {
	if (result == 0)
		cout << "String_1 < String_2";
	else if (result == 1)
		cout << "String_2 > String_1";
	else
		cout << "String_2 = String_1";

	cout << endl;
}

void SingleCheck(char* str1, char* str2, int size, int ProcSize) {
	cout << "\nSingleProgram: \n\n";

	PrintResult(Check(str1, str2, size));

	cout << "\nMultyProgram:\n\n";
}

int main(int argc, char* argv[]) {


	srand(time(NULL));
	int size = 10000;

	int ProcNum, ProcRank;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
	MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
	MPI_Status st;


	int recv1 = 0, recv2 = 0;
	int code_error1, code_error2;
	int time = 0;
	int natural_lenght = (ProcNum <= size + 1) ? ProcNum : size + 1;
	if (ProcRank == 0) {

		
		char *str1 = new char[size];
		char *str2 = new char[size];
		FillString(str1, str2, size);
		Print(str1, size);
		Print(str2, size);
		time = MPI_Wtime();
		SingleCheck(str1, str2, size, ProcNum);
		cout << "\nSingleTime: " << MPI_Wtime() - time << endl;
		time = MPI_Wtime();
		code_error1 = 0;
		code_error2 = 0;

		
		for (int i = 1; i < natural_lenght; i++) {
			int split_size1 = size;
			int split_size2 = size;

			char* split_str = SplitString(str1, natural_lenght, i, split_size1);
			char* split_str2 = SplitString(str2, natural_lenght, i, split_size2);

			MPI_Send(&split_size1, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			MPI_Send(&split_size2, 1, MPI_INT, i, 0, MPI_COMM_WORLD);

			MPI_Send(split_str, split_size1, MPI_CHAR, i, 0, MPI_COMM_WORLD);
			MPI_Send(split_str2, split_size2, MPI_CHAR, i, 0, MPI_COMM_WORLD);
		}

		int result = 2;
		for (int i = 1; i < natural_lenght; i++) {
			MPI_Recv(&code_error1, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &st);
			
			if (code_error1 != 2)
			{
				result = code_error1;
				break;
			}
		}

		PrintResult(result);
		cout << "\n MultyTime: " << MPI_Wtime() - time;
	}
	else if(ProcRank < natural_lenght){
		MPI_Status st;
		int split_size1 = 0;
		int split_size2 = 0;

		char* split_str, *split_str2;

		MPI_Recv(&split_size1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
		MPI_Recv(&split_size2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);

		split_str = new char[split_size1];
		split_str2 = new char[split_size2];

		MPI_Recv(split_str, split_size1, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &st);
		MPI_Recv(split_str2, split_size2, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &st);

		code_error1 = Check(split_str, split_str2, split_size1);
		
		MPI_Send(&code_error1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);

	}

	MPI_Finalize();

	return 0;

}