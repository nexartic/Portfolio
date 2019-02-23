#include<iostream>
#include<string>
#include<random>
namespace Matrix
{
using namespace std;
class matrix
{
public:
	matrix(int,int);
	~matrix();
	matrix();
	matrix(const matrix&);
	matrix operator+(const matrix&);
	matrix operator-(const matrix&);
	matrix operator*(const matrix&);
	bool operator ==(const matrix&)const;
	bool operator !=(const matrix&)const;
	int wid()const{return width;}
    int hig()const{return hight;}
	int **Mat()const{return Matrix;}
private:
	int width;// ширина
	int hight;// высота
	int **Matrix;
	void constructor(int,int);
	void destructor();
};
}
