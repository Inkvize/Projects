#include <locale.h>
#include <stdio.h>
#include <conio.h>
int nod(int x, int y)
{
	while (x!=y)
		if (x>y) x=x-y;
		else y=y-x;
		return y;
}
void main()
{
	int a,b;
setlocale (0,"russian");// ���������� �������� �����
puts("������� ��� ����������� �����:");
scanf ("%d %d", &a,&b);
printf ("��� %d � %d = %d.\n",a,b,nod(a,b));
puts("������� ����� ������� ��� ����������.....");
getch();
}

