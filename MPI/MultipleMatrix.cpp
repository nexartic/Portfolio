#include<iostream>
#include<time.h>
#include"mpi.h"
#include<vector>

using namespace std;

// Столбцовый формат хранения - 3 одномерных массива.
// 1 массив хранит элементы по столбцам сверху внизу, слева на право.
// 2 массив содержит номера строк, для каждого элемента из массива 1.
// 3 массив - содержит индексы начала каждого столбца, в 1 массиве.


void PrintMatrix(int** matrix, int size1, int size2) {
	cout << "\n";

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			cout << "|";
			if (matrix[i][j] == 0)
				cout << "0";
			cout << matrix[i][j];
		}
		cout << "\n";
	}

	cout << "\n";
}

void PrintCSS(int** css) {
	int valSize = css[3][0];
	cout << "\nValues: ";
	for (int i = 0; i < valSize; i++) {
		cout << "|" << css[0][i];
	}
	cout << "\nRows: ";
	for (int i = 0; i < valSize; i++) {
		cout << "|" << css[1][i];
	}

	cout << "\nIndexCols: ";
	for (int i = 0; i < css[3][2]; i++) {
		cout << "|" << css[2][i];
	}
	cout << "\n";
}

void FillMatrix(int**& matrix1, int**& matrix2, int size) {
	matrix1 = new int*[size];
	matrix2 = new int*[size + 1];
	for (int i = 0; i < size + 1; i++) {
		if(i < size)
		    matrix1[i] = new int[size + 1];
		matrix2[i] = new int[size];
	}

	for (int i = 0; i < size + 1; i++) {
		for (int j = 0; j < size + 1; j++) {
			if (i < size) {
				matrix1[i][j] = (rand() % 100) > 70 ? (rand() % 50 + 10) : 0;
				matrix2[j][i] = (rand() % 100) > 70 ? (rand() % 50 + 10) : 0;
			}
		}
	}

	PrintMatrix(matrix1, size, size + 1);
	PrintMatrix(matrix2, size + 1, size);
}

int** ToCSS(int** matrix, int size1, int size2) {
	
	int counter = 0;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (matrix[i][j] != 0)
				counter++;
		}
	}

	int** result = new int*[4];
	result[0] = new int[counter];
	result[1] = new int[counter];
	result[2] = new int[size2 + 1];
	result[3] = new int[3];// Размерность предыдущих массивов
	result[3][0] = counter;
	result[3][1] = size1;
	result[3][2] = size2 + 1;

	for (int i = 0, k = 0; i < size2; i++) {
		result[2][i] = k;
		for (int j = 0; j < size1; j++) {
			if (matrix[j][i] != 0) {
				result[0][k] = matrix[j][i];
				result[1][k] = j;
				k++;
			}
				
		}
	}
	result[2][size2] = counter;

	return result;
}



void Transp(int** css) {

	vector<int>* vec = new vector<int>[css[3][1]];
	
	for (int i = 0; i < css[3][2] - 1; i++) {
		for (int j = css[2][i]; j < css[2][i + 1]; j++) {
			
			vec[css[1][j]].push_back(css[0][j]);
			vec[css[1][j]].push_back(i);
		}
	}

	int* indexCols = new int[css[3][1] + 1];
	indexCols[0] = 0;
	

	for (int i = 0, k = 0; i < css[3][1]; i++) {
		for (int j = 0; j < vec[i].size(); j += 2) {
			css[0][k] = vec[i][j];
			css[1][k] = vec[i][j + 1];
			k++;
		}
		indexCols[i + 1] = indexCols[i] + (vec[i].size() / 2);
	}

	css[2] = indexCols;

	int tmp = css[3][1];
	css[3][1] = css[3][2] - 1;
	css[3][2] = tmp + 1;
}

int** MultipleMatrix(int** css1, int** css2) {
	vector<int> val;
	vector<int> row;
	vector<int> indexCols;
	int** result = new int*[4];
	int number_full_row = 0;

	

	for (int i = 0; i < css1[3][2] - 1; i++) {
		int j1 = css1[2][i];
		int j2 = css1[2][i + 1];
		int number_row = 0;

		indexCols.push_back(number_full_row);
		for (int l = 0; l < css2[3][2] - 1; l++) {
			int k1 = css2[2][l];
			int k2 = css2[2][l + 1];
			int sum = 0;

			
			if (j1 < j2 && k1 < k2) {// если оба столбца полные

				for (int j = j1; j < j2; j++) {
					for (int k = k1; k < k2; k++) {
						if (css1[1][j] == css2[1][k])
						{
							sum += css1[0][j] * css2[0][k];
						}
					}
				}

				if (sum != 0) {
					val.push_back(sum);
					row.push_back(number_row);
					number_full_row++;
				}
				number_row++;
			}
		}
	}
	indexCols.push_back(number_full_row);
		
	result[0] = new int[val.size()];
	result[1] = new int[row.size()];
	result[2] = new int[indexCols.size()];
	result[3] = new int[3];

	for (int i = 0; i < val.size(); i++) {
		result[0][i] = val[i];
		result[1][i] = row[i];
	}

	for (int i = 0; i < indexCols.size(); i++) {
		result[2][i] = indexCols[i];
	}
	result[3][0] = val.size();
	result[3][1] = css2[3][1];
	result[3][2] = indexCols.size();
	
	return result;
}

void ConcatCSS(int** css, int* val, int* row, int* indexCols, int* count) {
	css[0] = val;
	css[1] = row;
	css[2] = indexCols;
	css[3] = count;
}

int main(int argc, char** argv) {

	srand(time(NULL));
	int ProcSize, ProcRank;
	MPI_Status st;
	time_t time;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &ProcSize);
	MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
	int size_matrix = 5;

	if (ProcRank == 0) {
		
		int** matrix = 0, // size_matrix * (size_matrix+1)
	    **matrix2 = 0; // (size_matrix+1) * size_matrix

		FillMatrix(matrix, matrix2, size_matrix);

		int** css1 = ToCSS(matrix, size_matrix, size_matrix + 1);
		int** css2 = ToCSS(matrix2, size_matrix + 1, size_matrix);

		
		time = MPI_Wtime();
		
		Transp(css1);
		
		PrintCSS(css1);
		PrintCSS(css2);
		
		int** result = MultipleMatrix(css1, css2);
		Transp(result);
		time = MPI_Wtime() - time;
		cout << "\nSingle{\n";
		result[3][2]--;
		PrintCSS(result);
		result[3][2]++;
		cout << "\n}Single";
		cout << "\nSingleTime :" << time;
		cout << "\nMulty{\n";
		time = MPI_Wtime();

		MPI_Bcast(css2[3], 3, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Bcast(css2[0], css2[3][0], MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Bcast(css2[1], css2[3][0], MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Bcast(css2[2], css2[3][2], MPI_INT, 0, MPI_COMM_WORLD);

		int number_cols = size_matrix * size_matrix;
		int number_cols_to_work = number_cols / (ProcSize - 1);
		int reminder = number_cols % (ProcSize - 1);

		int* sendCounts1 = new int[ProcSize], *sendCounts2 = new int[ProcSize];
		int* displs1 = new int[ProcSize], *displs2 = new int[ProcSize];
		sendCounts1[0] = 0;
		sendCounts2[0] = 0;
		displs1[0] = 0;
		displs2[0] = 0;

		
		if (size_matrix >= ProcSize - 1) {
			for(int i = 1; i < ProcSize; i++){
				sendCounts1[i] = size_matrix / (ProcSize - 1) + (size_matrix % (ProcSize - 1) >= i) + 1;
				displs1[i] = displs1[i - 1] + sendCounts1[i - 1];
				MPI_Send(&sendCounts1[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
				if (i > 1)
					displs1[i]--;
				//-------------------
				sendCounts2[i] = css1[2][displs1[i] + sendCounts1[i] - 1] - css1[2][displs1[i]];
				displs2[i] = displs2[i - 1] + sendCounts2[i - 1];
				MPI_Send(&sendCounts2[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			}
		}
		else
		{
			int i;
			for (i = 1; i <= size_matrix; i++) {
				sendCounts1[i] = 2;
				displs1[i] = displs1[i - 1] + sendCounts1[i - 1];
				MPI_Send(&sendCounts1[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
				if (i > 1)
					displs1[i]--;

				sendCounts2[i] = css1[2][i] - css1[2][i - 1];
				displs2[i] = displs2[i - 1] + sendCounts2[i - 1];
				MPI_Send(&sendCounts2[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			}

			for (; i < ProcSize; i++) {
				sendCounts1[i] = 0;
				displs1[i] = displs1[i - 1];

				sendCounts2[i] = 0;
				displs2[i] = displs2[i - 1];
			}
		}
		
		
		int recv = 0;
		MPI_Scatterv(css1[2], sendCounts1, displs1, MPI_INT, &recv, 0, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Scatterv(css1[0], sendCounts2, displs2, MPI_INT, &recv, 0, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Scatterv(css1[1], sendCounts2, displs2, MPI_INT, &recv, 0, MPI_INT, 0, MPI_COMM_WORLD);
		
		int numberVals = 0, numberCols = 0, sumVals = 0, sumCols = 0;
		int right = ProcSize;
		if (size_matrix < ProcSize - 1)
			right = size_matrix + 1;

		int i;
		for (i = 1; i < right; i++) {
			MPI_Recv(&numberVals, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &st);
			MPI_Recv(&numberCols, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &st);
			sumVals += numberVals;
			sumCols += numberCols;

			sendCounts2[i] = numberVals;
			displs2[i] = displs2[i - 1] + sendCounts2[i - 1];

			sendCounts1[i] = numberCols;
			displs1[i] = displs1[i - 1] + sendCounts1[i - 1];
		}
		numberCols = sumCols;
		numberVals = sumVals;
		
		if (size_matrix < ProcSize - 1) {
			for (; i < ProcSize; i++) {
				sendCounts2[i] = 0;
				displs2[i] = displs2[i - 1];
				sendCounts1[i] = 0;
				displs1[i] = displs1[i - 1];
			}
		}

		delete result[0]; delete result[1]; delete result[2];
		result[0] = new int[numberVals]; result[1] = new int[numberVals]; result[2] = new int[numberCols];
		result[3][0] = numberVals, result[3][1] = css2[3][2] - 1, result[3][2] = numberCols;
		

		MPI_Gatherv(nullptr, 0, MPI_INT, result[0], sendCounts2, displs2, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Gatherv(nullptr, 0, MPI_INT, result[1], sendCounts2, displs2, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Gatherv(nullptr, 0, MPI_INT, result[2], sendCounts1, displs1, MPI_INT, 0, MPI_COMM_WORLD);

		int* indexCols = new int[size_matrix + 1];
		for (int i = 0; i < sendCounts1[1]; i++) {
			indexCols[i] = result[2][i];
		}
		
		int j = sendCounts1[1];
		for (int i = sendCounts1[1]; i < numberCols - 1; i++) {
			int dif = result[2][i + 1] - result[2][i];
			if (dif >= 0) {
				indexCols[j] = indexCols[j - 1] + dif;
				j++;
				if (dif == 0)
					i++;
			}
		}

		delete[] result[2];
		result[2] = indexCols;

		result[3][2] = size_matrix + 1;
		result[3][1] = size_matrix;

		Transp(result);
		PrintCSS(result);
		
	}
	else
	{
		int* indexCols2 = 0, *rows2 = 0, *values2 = 0, *count = new int[2];
		int indexNumber = 0, valNumber = 0;
		int numberCols = 0, number_vals = 0;

		MPI_Bcast(count, 3, MPI_INT, 0, MPI_COMM_WORLD);

		valNumber = count[0];
		indexNumber = count[2];
		indexCols2 = new int[indexNumber];
		rows2 = new int[valNumber];
		values2 = new int[valNumber];

		MPI_Bcast(values2, valNumber, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Bcast(rows2, valNumber, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Bcast(indexCols2, indexNumber, MPI_INT, 0, MPI_COMM_WORLD);

		if (size_matrix > ProcRank - 1) {
			MPI_Recv(&numberCols, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
			MPI_Recv(&number_vals, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
		}

		int* indexCols = new int[numberCols];
        int* rows = new int[number_vals];
		int* values = new int[number_vals];

		MPI_Scatterv(nullptr, nullptr, nullptr, MPI_INT, indexCols, numberCols, MPI_INT, 0, MPI_COMM_WORLD);//столбцы
		MPI_Scatterv(nullptr, nullptr, nullptr, MPI_INT, values, number_vals, MPI_INT, 0, MPI_COMM_WORLD);//значения
		MPI_Scatterv(nullptr, nullptr, nullptr, MPI_INT, rows, number_vals, MPI_INT, 0, MPI_COMM_WORLD);//строки

		if (size_matrix > ProcRank - 1) {
			int **css1 = new int*[4], **css2 = new int*[4], *count1 = new int[3];
			count1[0] = number_vals;
			count1[1] = count[1];
			count1[2] = numberCols;

			ConcatCSS(css1, values, rows, indexCols, count1);
			ConcatCSS(css2, values2, rows2, indexCols2, count);

			int tmp = css1[2][0];
			css1[2][0] = 0;
			for (int i = 1; i < css1[3][2]; i++) {
				css1[2][i] -= tmp;

			}

			int** result = MultipleMatrix(css1, css2);
			int recv = 0;

			MPI_Send(&result[3][0], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);

			numberCols = result[3][2];
			MPI_Send(&numberCols, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);

			MPI_Gatherv(result[0], result[3][0], MPI_INT, nullptr, nullptr, nullptr, MPI_INT, 0, MPI_COMM_WORLD);
			MPI_Gatherv(result[1], result[3][0], MPI_INT, nullptr, nullptr, nullptr, MPI_INT, 0, MPI_COMM_WORLD);
			MPI_Gatherv(result[2], numberCols, MPI_INT, nullptr, nullptr, nullptr, MPI_INT, 0, MPI_COMM_WORLD);
		}
		else
		{
			int result = 0;
			MPI_Gatherv(&result, 0, MPI_INT, nullptr, nullptr, nullptr, MPI_INT, 0, MPI_COMM_WORLD);
			MPI_Gatherv(&result, 0, MPI_INT, nullptr, nullptr, nullptr, MPI_INT, 0, MPI_COMM_WORLD);
			MPI_Gatherv(&result, 0, MPI_INT, nullptr, nullptr, nullptr, MPI_INT, 0, MPI_COMM_WORLD);
		}
		
	}
	if (ProcRank == 0) {
		time = MPI_Wtime() - time;
		cout << "\n}Multy";
		cout << "\n MultyTime :" << time;
	}
	
	MPI_Finalize();
}