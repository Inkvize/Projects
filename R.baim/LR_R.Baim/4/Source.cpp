#include <iostream>
#include <locale.h>
#include <time.h>
#include<stdio.h>

using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "russian");
	cout << "������� ����������� ��������� �������"<< endl;
	int N;
	cin >> N;
	cout << "������� �������� �������" << endl;
	double b[50], min, max, c;
	for (int i = 0; i < N; i++)
	{
	cin>>b[i];
	}
	for (int i = 0; i < N; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	min = b[0];
	max = b[0];
	for (int i = 1; i < N; i++)
	{
		if (b[i] > max)
		{
			max = b[i];
		}
		if(b[i]< min)
		{
			min = b[i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << b[i] << " ";
	}
	c = max - min;
	cout <<endl<< "������� ��������=" << c << endl;
	cout <<"����������� �������="<< min << endl;
	cout <<"������������ �������="<< max << endl;
	system("pause");
}