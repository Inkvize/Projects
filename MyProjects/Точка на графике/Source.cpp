#include <math.h> 
#include <stdio.h> 
#include <locale.h> 
#include <iostream> 

using namespace std;

	void main() {
		setlocale(0, "russian");
		puts("������� ���������� x,y");
		double x, y, z;
		cin >> x >> y;
		cout <<"x= "<< x <<" "<<"y= "<< y<< endl;
		z = x*x + y*y;
		if (1<=z)
		{
			if (4 >= z) 
			{
				puts("����� �����������");
		}
			else puts("����� ��� ���������� � �������� 2");
		}
		else puts("����� ������ ���������� � �������� 1");
		system("pause");
		

}