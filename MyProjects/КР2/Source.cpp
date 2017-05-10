#include <iostream>
#include<stdio.h>
#include<time.h>

void  inrand(int a[][10], int size) //��������� ������� ���������� ������� � ������� ��
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			a[i][j] = rand() % 11;
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

void seah(int a[][10], int n, int &imax, int &jmax) // ������������ ������ ������������� �������� ���� ���������(�� ������ ������������ ��������)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[imax][jmax] < a[i][j])
			{
				imax = i;
				jmax = j;
			}
		}
	}
}

int prover(int a[][10], int n, int imax, int jmax)
{
	int prover = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[imax][jmax] == a[i][j])
			{
				prover++;
			}
		}
	}
	return prover;
}

void outend(int a[][10], int n, int resulprov)// ����� ������� �� �������� ��� ������� � ����������� �� ���������� �������� ������� ����������� ��������
{
	if (resulprov == 0)
	{
		printf("Out strok \n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%5d", a[i][j]);
			}
			printf("\n");
		}
     }
	else
	{
		{
			printf("Out stolb \n");
			for (int j = 0; j < n; j++)
			{
				for (int i = 0; i < n; i++)
				{
					printf("%5d", a[i][j]);
				}
				printf("\n");
			}
		}
	}
	printf("\n");
}

int main()// ������� ���������
{
	srand(time(0));
	int a[10][10], n, imax, jmax, k;
	printf("Imput n(<10) matrix \n");
	std::cin >> n;
	inrand(a, n);
	imax = 0;
	jmax = 1;
	seah(a, n, imax, jmax);
	k = prover(a, n, imax, jmax);
	printf("max el up diagonal=%d in strok=%d stolb=%d \nvstretilos down diagonal=%d \n", a[imax][jmax], imax+1, jmax+1, k);
	outend(a, n, k);
	system("pause");
}