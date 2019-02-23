#include "Polinom.h"

int main()
{
	int monoms[2][2];
	monoms[0][0] = 5;
	monoms[0][1] = 5;
	monoms[1][0] = 25;
	monoms[1][1] = 25;
	TPolinom pol(monoms, 2);
	cin >> pol;
	cout << pol << endl;
	return 0;
}