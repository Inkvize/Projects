#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
long double y, ap, op;
int main()
{
	setlocale(0, "rus");
	y = 1;
	printf("�� �������������� y=%20.16f\n", y);
	y = y / 3;
	printf("������������� ����� 1/3 � ������    y=%20.16f\n", y);
	printf("������ ������������� ����� 1/3  =%20.16f\n", 1.0 / 3.0);
	ap = fabs((1.0 / 3) - y);    //���������� �����������
	op = ap / fabs(1.0 / 3);  // ������������� �����������
	printf("���������� ����������� ������. 1/3 ap=%20.16f\n", ap);
	printf("������������� ����������� ������. 1/3  op=%20.16f\n", op);
	y = y / 6000;
	y = exp(y);
	y = sqrt(y); //���������� ������
	y = y / 14;
	y = 14 * y;
	y = y*y;
	y = log(y);
	y = 6000 * y;
	y = y * 3;
	printf("����� �������������� y=%20.16f\n", y);
	ap = fabs(1 - y);  //���������� �����������
	op = ap / 1.0; // ������������� �����������
	printf("���������� ����������� ap=%20.16f\n", ap);
	printf("������������� ����������� op=%20.16f\n", op);
	system("pause");
	return 0;
}
