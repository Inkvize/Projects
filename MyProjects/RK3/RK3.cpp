#include <iostream>
#include <Windows.h>

struct element //������� ������������ ���������
{
	char a;
	element *prev;
	element *next;
};

void prinst1(struct element *y) //������ � ������ ����������� ������
{
	if (y != NULL)//�������� �� ������ ������
	{
		if (y->next != NULL)
		{
			while (y != NULL)
			{
				std::cout << y->a<<std::endl;
				y = y->next;
			}
			printf("\n");
		}
		else printf("%s\n", y->a);
	}
}

void prinst2(struct element *y) //������ � �������� ����������� ������
{
	while (y->next != NULL)
	{
		y = y->next;
	}
	if (y != NULL)
	{
		if (y->prev != NULL)
		{
			while (y != NULL)
			{
				std::cout << y->a<<std::endl;
				y = y->prev;
			}
			printf("\n");
		}
		else printf("%s\n", y->a);
	}
}

void form(char *strok, element **first) //��������� �� ������������ ������
{
	element *p, *q, *tmp;
	char *buk=strok;
	while (*buk == '#')
	{
		buk++;
	}
	if(*buk!='\n')
	{
			p = new element;
			*first = p;
			p->a = *buk;
			p->next = p->prev = NULL;
			buk++;
			while (*buk != '\0')
			{
				if (*buk != '#')
				{
					q = new element;
					q->next = q->prev = NULL;
					q->a = *buk;
					q->prev = p;
					p->next = q;
					p = q;
				}
				else//���� ���������� �� # ������� ���������� ������� ��������� �����
				{
					tmp = p;
					p = p->prev;
					p->next = NULL;
					delete[] tmp;
				}
				buk++;
			}
	}
}

void delstr(struct element **q)//�������� �� ������ ������
{
	element *a = *q, *b = *q;
	q = NULL;
	while (a->next != NULL)
	{
		b = a;
		a = a->next;
		delete b;
	}
	delete a;
}

int main()//�������� ������
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char strok[100];
	element *first;
	puts("������� ������");
	gets_s(strok);
	form(strok, &first);
	puts("�������������� ������������ ������(��� # � ���������� ��������)");
	puts("������ � ������ �����������");
	prinst1(first);
	puts("������ � �������� �����������");
	prinst2(first);
	delstr(&first);
	system("pause");
    return 0;
}