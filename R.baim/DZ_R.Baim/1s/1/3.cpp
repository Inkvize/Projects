#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(0, "russian");
	double y, eps, n;
	y = 0;
	n = 1;
	puts("������� �������� ���������� eps");
	cin >> eps;
	do
	{
		y = n / (n*n + 2);
		n++;
	} while (eps <= fabs(y));
	cout << "����� ����� ������������������ ��� �������� ����������� �������(���������� ��������)=" << n - 1 << endl;
	printf("%20.15f \n", y);
	cout << y << endl;
	system("pause");
	return 0;
}