#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(0, "russian");
	long double y, eps, n, z;
	y = 0;
	n = 1;
	puts("������� �������� ���������� eps");
	cin >> eps;
	do
	{
		z = y;
		y = pow((1 + 1 / n), n);
		n++;
	} while (eps <= fabs(y-z));
	cout << "����� ����� ������������������ ��� �������� ����������� �������=" << n - 1 << endl;
	printf("%1.20lf",y);
	system("pause");
	return 0;
}