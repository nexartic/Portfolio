#include "matrix.h"
using namespace Matrix;
void matrix::constructor(int hight,int width)
{
	Matrix = new int*[hight];
	for(int i = 0; i<hight; i++)
		Matrix[i] = new int[width];
	this->hight = hight;
	this->width = width;
}
void matrix::destructor()
{
	for(int i = 0; i<hight; i++)
		delete[] Matrix[i];
}
matrix::matrix(int hight,int width)
{
	constructor(hight,width);
}
matrix::matrix()
{
	constructor(3,3);
}
matrix::matrix(const matrix& mat)
{
	constructor(mat.hight,mat.width);
	for(int i = 0; i<mat.hight; i++)
		for(int j = 0; j<mat.width; j++)
			Matrix[i][j] = mat.Matrix[i][j];
}
matrix::~matrix()
{
	destructor();
}
matrix matrix::operator+(const matrix& mat)
{
	if(width != mat.width || hight != mat.hight)
	{
		cout<<"Матрицы не равны. Сложение невозможно";
		return *this;
	}
	matrix _matrix(*this);
	for(int i = 0; i<hight; i++)
		for(int j = 0; j<width; j++)
			_matrix.Matrix[i][j] += mat.Matrix[i][j];

	return _matrix;
}
matrix matrix::operator-(const matrix& mat)
{
	if(width != mat.width || hight != mat.hight)
	{
		cout<<"Матрицы не равны. Вычитание невозможно";
		return *this;
	}
	matrix _matrix(*this);
	for(int i = 0; i<hight; i++)
		for(int j = 0; j<width; j++)
			_matrix.Matrix[i][j] -= mat.Matrix[i][j];

	return _matrix;
}
matrix matrix::operator*(const matrix& mat) 
{
	if(width != mat.hight)
	{
		cout<<" Умножение невозможно";
		return *this;
	}
	matrix * _matrix = new matrix(hight,mat.width);
	int place;
	for(int i = 0; i<hight; i++)
	{
		for(int j = 0; j<mat.width; j++)
		{
			place = 0;
			for(int k = 0; k<width; k++)
			{
				place += (Matrix[i][k]*mat.Matrix[k][j]);
			}
			_matrix->Matrix[i][j] = place;
		}
	}
	return *_matrix;			
}
bool matrix::operator==(const matrix& mat)const
{
	if(hight != mat.hight || width != mat.width)
		return false;
	for(int i = 0; i<hight; i++)
	{
		for(int j = 0; j<width; j++)
		{
			if(Matrix[i][j] != mat.Matrix[i][j])
				return false;
		}
	}
	return true;
}
bool matrix::operator!=(const matrix& mat)const
{
	if(*this == mat)
		return false;
	return true;
}