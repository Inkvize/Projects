#include <math.h>
#include <iostream>
#include <locale.h>
#include <stdio.h>

using namespace std;

int main()
{
	setlocale(0, "russian");
	double s,r,eps,c,R,k;
	s = 0;
	r = 0.5;
	c = 1;
	k = 0;
	cout << "������� �������� ���������� E" << endl;
	cin >> eps;
	do
	{
		R = r;
		s += r;
		r = (1 + c) / (pow(2,c+1)*pow((-1),c));
		c++;
		k++;
		cout << s << " ";
	} while (eps <= fabs(r-R));
	cout << endl;
	cout <<"��������� ������ ���� = "<< k << endl;
	system("pause");
}