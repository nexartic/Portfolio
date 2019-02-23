

#include <stdlib.h>
#include<iostream>
#include"mpi.h"
#include<time.h>

using namespace std;
typedef unsigned int uint;

int clamp(int val) {
	if (val < 0)
		return 0;
	if (val > 255)
		return 255;

	return val;
}

int GetIndexRow(int i, int img_size) {
	return i / img_size;
}

uint CalcPixel(int start, int* img, int img_size) {

	uint result_pixel = 0;
	int matrix_size = img_size * img_size;
	int counter = 0;

	for (int i = start - img_size; i <= start + img_size; i += img_size) {
		for (int j = i - 1; j <= i + 1; j++) {
			
			if (j >= 0 && j < matrix_size && GetIndexRow(i, img_size) == GetIndexRow(j, img_size)) {// Проверка на X < 0 и X > width(по j)

				result_pixel += img[j];
				counter++;
			}
		}
	}
	return clamp(result_pixel / counter);
}

int* CreateIntMatrix(int size) {
	int* result = new int[size * size];

	for (int i = 0; i < size * size; i += size) {
		for (int j = i,k = 0; j < i + size; j++, k++) {
			result[i + k] = rand() % 256;
		}
	}

	return result;
}

void SingleProces(int* image, int img_size) {
	int* result = new int[img_size * img_size];
	for (int i = 0; i < img_size * img_size; i++) {
		result[i] = CalcPixel(i, image, img_size);
	}

	cout << "SingleProcess:\n\n";

	//for (int i = 0; i < img_size * img_size; i++) {
	//	cout << "|" << result[i];
	//}

	delete[] result;
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	int ProcSize, ProcRank;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &ProcSize);
	MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
	MPI_Status st;


	int size_img = 1000;
	int matrix_size = size_img * size_img;
	int size_recv = (matrix_size / ProcSize) * (ProcSize - 1);
	int *image = new int[matrix_size];

	double start_t = 0;

	if (ProcRank == 0) {
		start_t = MPI_Wtime();
		image = CreateIntMatrix(size_img);

		SingleProces(image, size_img);
		start_t = MPI_Wtime() - start_t;
		cout << "SingleTime :" << start_t << endl;
		cout << "\n\nMultyProcess\n\n";
		start_t = MPI_Wtime();
	}

	int* sendCounts = new int();
	int* displs = new int();
	if (ProcSize - 1 <= matrix_size) {
		if (ProcRank == 0) {
			
			delete sendCounts;
			delete displs;
			int* resultImage = new int[matrix_size];
			int* sendCounts = new int[ProcSize];
			int* displs = new int[ProcSize];

			sendCounts[0] = 0;
			displs[0] = 0;
			ProcSize--;
			int remainder = matrix_size % ProcSize;
			int offset = size_img;
			int* recv = new int();
			int* startAndEnd = new int[(ProcSize) * 2];
			int* offsetFromStartStr = new int[ProcSize];
			
			displs[1] = 0;
			startAndEnd[0] = 0;
			offsetFromStartStr[0] = 0;
			
			sendCounts[1] = matrix_size / ProcSize + (remainder > 0) + size_img;
			offset = size_img;
			if (GetIndexRow(sendCounts[1] - 1, size_img) == GetIndexRow(sendCounts[1], size_img)) {
				offset++;
				sendCounts[1]++;
			}

			startAndEnd[1] = offset;
			
			int sum = sendCounts[1];// сумма учтенных элементов
			for (int i = 2, j = 2, l = 1; i < ProcSize + 1; i++, l++) {
				int start = sum - offset;
				int a = 0;
				if (start - size_img >= 0) {
					start -= size_img;
					a += size_img;
				}
				if (GetIndexRow(start, size_img) == GetIndexRow(start - 1, size_img)) {
					start--;
					a++;
				}
				startAndEnd[j] = a;
				displs[i] = start;
				offsetFromStartStr[l] = start % size_img;
				
				int end = sum - offset + matrix_size / ProcSize + (i < remainder) - 1;
				
				offset = 0;

				if (end + size_img <= matrix_size) {
					offset += size_img;
				}
				if (GetIndexRow(end, size_img) == GetIndexRow(end + 1, size_img)) {
					offset++;
				}
			    
				startAndEnd[j + 1] = offset;
				end += offset + 1;
				sendCounts[i] = end - start;
				sum = end;
				j += 2;
			}
			
			for (int i = 1,j = 0, k = 0; i < ProcSize + 1; i++, j += 2, k++) {
				MPI_Send(&sendCounts[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
				MPI_Send(&startAndEnd[j], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
				MPI_Send(&startAndEnd[j + 1], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
				MPI_Send(&offsetFromStartStr[k], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			}

			MPI_Scatterv(image, sendCounts, displs, MPI_INT, recv, 0, MPI_INT, 0, MPI_COMM_WORLD);

			int* recvCounts = new int[ProcSize + 1];
			displs[0] = 0;
			recvCounts[0] = 0;
			displs[1] = 0;
			recvCounts[1] = sendCounts[1] - startAndEnd[0] - startAndEnd[1];

			for (int i = 2, j = 2, k = 2; i < ProcSize + 1; i++, j++, k += 2) {
				recvCounts[i] = sendCounts[j] - startAndEnd[k] - startAndEnd[k + 1];
				displs[j] = displs[j - 1] + recvCounts[i - 1];
			}

			MPI_Gatherv(nullptr, 0, MPI_INT, resultImage, recvCounts, displs, MPI_INT, 0, MPI_COMM_WORLD);

			//for (int i = 0; i < matrix_size; i++)
			//	cout << "|" << resultImage[i];

		}
		else {
			MPI_Status st;
			int recv_lenght = 0;
			int start = 0, end = 0, offset = 0;

			MPI_Recv(&recv_lenght, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
			MPI_Recv(&start, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
			MPI_Recv(&end, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
			MPI_Recv(&offset, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
		
			int* recv = new int[recv_lenght];
			MPI_Scatterv(image, sendCounts, displs, MPI_INT, recv, recv_lenght, MPI_INT, 0, MPI_COMM_WORLD);
			
			
			int* result = new int[recv_lenght - start - end];
			int sum = 0;
			int counter = 0;
			for (int i = start, m = 0; i < recv_lenght - end; i++, m++) {
				for (int j = i - size_img; j <= i + size_img; j += size_img) {
					for (int k = j - 1; k <= j + 1; k++) {
						if (k >= 0 && k < recv_lenght && GetIndexRow(j + offset, size_img) == GetIndexRow(k + offset, size_img)) {// Проверка на X < 0 и X > width(по j)
							sum += recv[k];
							counter++;
						}
					}
				}
				
				result[m] = sum / counter;
				counter = 0;
				sum = 0;
			}

			MPI_Gatherv(result, recv_lenght - start - end, MPI_INT, nullptr, nullptr, nullptr, MPI_INT, 0, MPI_COMM_WORLD);
			delete[] recv;
			delete[] result;
		}
	}
	else
	{
	    
		if (ProcRank == 0) {
			delete sendCounts;
			delete displs;
			sendCounts = new int[ProcSize];
			displs = new int[ProcSize];
			int* start = new int[matrix_size];
			int* end = new int[matrix_size];
			int* offset = new int[ProcSize];

			sendCounts[0] = 0;
			displs[0] = 0;
			sendCounts[1] = size_img + 2;
			displs[1] = 0;
			start[0] = 0;
			end[0] = size_img + 1;
			offset[0] = 0;
			offset[1] = 0;

			int currentOffset = 0;
			for (int i = 2, j = 1; i < ProcSize; i++, j++) {

				if (i <= matrix_size) {
					sendCounts[i] = 1;

					currentOffset = 0;
					int val = j - 1;
					if (val >= 0 && GetIndexRow(val, size_img) == GetIndexRow(val + 1, size_img)) {
						currentOffset++;
					}
					val = j - size_img;
					if (val >= 0) {
						currentOffset += size_img;
					}
						
					offset[i] = j - currentOffset;
					start[j] = currentOffset;
					displs[i] = j - currentOffset;

					val = j + 1;
					if (val < matrix_size && GetIndexRow(val, size_img) == GetIndexRow(val - 1, size_img)) {
						currentOffset++;
					}
					val = j + size_img;
					if (val < matrix_size) {
						currentOffset += size_img;
					}

					end[j] = currentOffset - start[j];
					sendCounts[i] += currentOffset;
					
				}
				else {
					sendCounts[i] = 0;
					displs[i] = displs[i - 1];
				}
				
			}
			
			for (int i = 1; i < ProcSize; i++) {
				MPI_Send(&sendCounts[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
				MPI_Send(&offset[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
				if (i <= matrix_size)
					MPI_Send(&start[i - 1], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			}

			MPI_Scatterv(image, sendCounts, displs, MPI_INT, nullptr, 0, MPI_INT, 0, MPI_COMM_WORLD);

			displs[0] = 0;
			sendCounts[0] = 0;
			for (int i = 1; i < ProcSize; i++) {
				displs[i] = displs[i - 1] + (i <= matrix_size);
				sendCounts[i] = (i <= matrix_size);
			}
			int* recv = new int[matrix_size];

			int b = -1;
			
			for (int i = 1; i <= matrix_size; i++) {
				MPI_Recv(&recv[i - 1], 1, MPI_INT, i, 0, MPI_COMM_WORLD, &st);
			}

			//for (int i = 0; i < matrix_size; i++) {
			//	cout << "|" << recv[i];
			//}
		}
		else {
			
			int size = 0;
			int start = 0;
			int resultPixel = 0;
			int offset = 0;

			MPI_Recv(&size, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
			MPI_Recv(&offset, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
			int* pixels = new int[size];

			MPI_Scatterv(nullptr, nullptr, nullptr, MPI_INT, pixels, size, MPI_INT, 0, MPI_COMM_WORLD);

			if (ProcRank <= matrix_size) {
				MPI_Recv(&start, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
				int counter = 0;
				for (int i = start - size_img; i <= start + size_img; i += size_img) {
					for (int j = i - 1; j <= i + 1; j++) {
						if (j >= 0 && j < size && GetIndexRow(j + offset, size_img) == GetIndexRow(i + offset, size_img)) {
							resultPixel += pixels[j];
							counter++;
						}
					}
				}
				
				resultPixel /= counter;


				MPI_Send(&resultPixel, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
			}
			delete[] pixels;
		}
	}


	if (ProcRank == 0) {
		start_t = MPI_Wtime() - start_t;
		cout << "MultyTime :" << start_t;
	}
	MPI_Finalize();
	return 0;
}