#include <stdio.h>
#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int main()
{
	double x, y, z, k, n, m;
	setlocale(0, "russian");
	puts("������� x, y");
	cin >> x >> y;
	cout << "x=" << x << " " << "y=" << y << endl;
	z = (x + 1)*(x + 1) + y*y;
	k = x + 1;
	n = -x - 1;
	if (z <= 1)
	{
		if (n <= y)
		{
			if (y <= k) { puts("����� ����������� �������� �������"); }
			else puts("����� ��������� � ����������, �� �� � �������� �������");
		}
		else puts("����� ��������� � ����������, �� �� � �������� �������");
	}
	else 
	{
		if (x > 0 && y > 0) { puts("����� � ������ ��������, �� �� � �������� �������"); }
		if (x < 0 && y > 0) { puts("����� �� ������ ��������, �� �� � �������� �������"); }
		if (x < 0 && y < 0) { puts("����� � ������� ��������, �� �� � �������� �������"); }
		if (x > 0 && y < 0) { puts("����� � ��������� ��������, �� �� � �������� �������"); }
	};
	system("pause");
}
