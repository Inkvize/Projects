#include <iostream>
#include <Windows.h>

struct element {
	char slov[32];
	element *next;
};

void prinst(struct element *p) {//������ ������
	element *y = p;
	if (y != NULL) {
		while (y != NULL) {
			printf("%s\n", y->slov);
			y = y->next;
		}
	}
}

bool CharCheck(char *s, char &c) {//�������� �������
	for (int i = 0; i < strlen(s); i++) {
		if (c == *(s + i)) {
			return true;
		}
	}
	return false;
}

void form(char *strok, element **first1, element **first2)//������������ �������
{
	*(strok + strlen(strok) + 1) = '\0';
	element *p1, *q1, *p2, *q2;
	char *firstslov, *endslov;
	char s[] = "�Ũ����������������AEYUIOaeyuio";
	int k1 = 0, k2 = 0;
	firstslov = strok;
	while (*firstslov != '\0') {
		endslov = firstslov;
		while (*endslov != ' '&&*endslov != '\0') {
			*endslov++;
		}
		*endslov--;
		if (CharCheck(s, *firstslov)) {
			p1 = new element;
			p1->next = NULL;
			if (k1 == 0) {
				*first1 = p1;
				p1->next = NULL;
				q1 = p1;
				strncpy(p1->slov, firstslov, strlen(firstslov) - strlen(endslov) + 1);
				p1->slov[strlen(firstslov) - strlen(endslov) + 1] = '\0';
			}
			else {
				q1->next = p1;
				strncpy(p1->slov, firstslov, strlen(firstslov) - strlen(endslov) + 1);
				p1->slov[strlen(firstslov) - strlen(endslov) + 1] = '\0';
				q1 = q1->next;
			}
			k1++;
		}
		else {
			p2 = new element;
			p2->next = NULL;
			if (k2 == 0) {
				*first2 = p2;
				q2 = p2;
				strncpy(p2->slov, firstslov, strlen(firstslov) - strlen(endslov) + 1);
				p2->slov[strlen(firstslov) - strlen(endslov) + 1] = '\0';
			}
			else {
				q2->next = p2;
				strncpy(p2->slov, firstslov, strlen(firstslov) - strlen(endslov) + 1);
				p2->slov[strlen(firstslov) - strlen(endslov) + 1] = '\0';
				q2 = q2->next;
			}
			k2++;
		}
		endslov = endslov + 2;
		firstslov = endslov;
	}
}

int CountWord(element *first) {//������� ���� � ������
	element *q = first;
	int count = 0;
	while (q != NULL) {
		count++;
		q = q->next;
	}
	return count;
}

void schet(element *first1, element *first2) {//���� ���� � ����������� � ����� ������ �� ������
	int k1, k2;
	k1 = CountWord(first1);
	k2 = CountWord(first2);
	if (k1 > k2)
	{
		printf("������� �� ���������� ���� ������ �� ���� �� ������� ����� c k1=%d �������, �� 2 ������ k2=%d\n", k1, k2);
	}
	if (k2 > k1)
	{
		printf("������� �� ���������� ���� ������ �� ���� �� ��������� ����� c k2=%d �������, � 1 ������ k1=%d\n", k2, k1);
	}
	if (k1 == k2)
	{
		printf("���������� ���� � ������� ���������(k1=k2=%d)\n", k1);
	}
}

void delstr(element **q) {//�������� ������
	if (*q != NULL) {
		element *a = *q, *next;
		while (a)
		{
			next = a->next;
			delete a;
			a = next;
		}
		*q = NULL;
	}
}

int main() {
	system("chcp 1251");
	system("color f0");
	system("cls");
	element *first1 = NULL, *first2 = NULL;
	char strok[100];
	puts("������� ������");
	gets_s(strok);
	printf("\n");
	form(strok, &first1, &first2);
	printf("������ �� ���� �� ������� �����\n");
	prinst(first1);
	printf("������ �� ���� �� ��������� �����\n");
	prinst(first2);
	schet(first1, first2);
	delstr(&first1);
	delstr(&first2);
	system("pause");
	return 0;
}
