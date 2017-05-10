#include <iostream>

bool CheckChar(char *a, char &c) {//��������� ����������� ��� �������� ����� ����� "c" �������� ������,
	//��������� ���� � �������� �������, ������� ���� ���������� � ���������� ���������
	if (c == *a) {
		return true;
	}
	if (strlen(a) == 0) {
		return false;
	}
	return CheckChar((a + 1), c);
}

void CountGlas(char *a, char *s, int &count) { //���������� �������� ��� �������
	if (strlen(a) == 0) {
		//����� �� ��������
	} else {
		count += (int)CheckChar(s, *a);//����� ����������� ���������
		CountGlas((a + 1), s, count);
	}
}

int CountClass(char *a, char *s) { //����������� ���������� ��������
	if (strlen(a) == 0) {
		//����� �� ��������
		return 0;
	}
	return (int)CheckChar(s, *a) + CountClass(a+1, s);
}

int main() {
	system("chcp 1251");
	system("color f0");
	system("cls");
	char a[64];
	char s[] = "AEIOUYaeiouy";
	int count = 0;
	std::cout << "������� ������" << std::endl;
	std::cin >> a;
	CountGlas(a, s, count);
	std::cout << "���������� ������� � ������ " << count << std::endl;
	//std::cout << "���������� ������� � ������ " << CountClass(a, s) << std::endl;
	system("pause");
	return 0;
}
