#include"matrix.h" 
using namespace Matrix;
ostream& operator<<(ostream& stream, const matrix& mat)
{
	for(int i = 0; i<mat.hig(); i++)
	{
		stream<<endl;
		stream<<"|";
		for(int j = 0; j<mat.wid(); j++)
		{
			stream.width(2);
			stream<<mat.Mat()[i][j]<<"|";
		}
		stream<<endl;
	}
	return stream;
}
int main()
{
	matrix m;
	matrix *s  = new matrix(2,3);
	matrix *d = new matrix(m);
	matrix *s1 = new matrix(3,2);
	random_device rand;
	for(int i = 0; i<3; i++)
		for(int j = 0; j<2; j++)
		{
			s->Mat()[j][i] = rand()%10;
			s1->Mat()[i][j] = rand()%10;
		}
     for(int i = 0; i<3; i++)
		for(int j = 0; j<3; j++)
		{
			d->Mat()[i][j] = rand()%10;
			m.Mat()[i][j] = rand()%10;
		}
	cout<<m+(*d)<<"\n"<<m-(*d)<<endl;
    cout<<(*s)*(*s1)<<endl;
	if(m != (*d))
		cout<<"False";
	else
		cout<<"True";
	system("pause");
}