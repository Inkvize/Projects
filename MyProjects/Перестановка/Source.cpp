#include<cstdio>
#include<cstdlib>

int askNumberOfElements()
{
	int ret;
	do
	{
		printf("Vvedite k-vo elementov v masive: ");
		scanf_s("%d", &ret);
	} while (ret <= 0);
	return ret;
}
int* packArray(int elements)
{
	int* ret = (int*)malloc(elements * sizeof(int));
	for (int i = elements; i; --i)
	{
		printf("Vvedite %d element massiva: ", elements - i + 1);
		scanf_s("%d", ret + elements - i);
	}
	return ret;
}

bool isContain(int* array, int countOfElements, int requiredElement)
//������� ������ �������� � �������
{
	for (int i = 0; i < countOfElements; ++i)
		if (array[i] == requiredElement)
			return true;
	return false;
}
void nextElement(int* usedElements, int countOfUsedElements, int& currentElement)
//������� �������� � ���������� ��������.
{
	while (isContain(usedElements, countOfUsedElements, ++currentElement)) {}
}
int firstElement(int* usedElements, int countOfUsedElements)
//����������, � ������ �������� �������� ������������ �����.
{
	int currentElement = 0;
	while (isContain(usedElements, countOfUsedElements, currentElement))
		++currentElement;

	return currentElement;
}
void recursionPrintAllCombinationOfElemens(int* array, int elements, int countOfUsedElements = 0)
{
	/*
	������ �������� ��� ������� � ������� � ���������: ��������� ������ usedElements ����
	������������ ����� ��������, ������� ��� ��� ������� � ���������� ������� ����������.
	��� �������� ��� static, ��� ������ ��� �������� �� ����� ������ ������ ��� � �� ���
	������ ����������� ������ �������. ����� ���� ����������� ���������� � ������ ��������������
	��������� �� ����� ���������� ��������� ���������� ������ �� ������ � ���� �� ��������
	���� ���������������� ���������, ������ ������������ � ������ �������������� ���������,
	����� ����� ��� ���� ���������� ��������.
	���� ����� ��������� � ������� �������������� ��������� ����� ����� ��������� ����������
	������, �. �. ���������� ��� ��������(��� ���, ��� ���������) �� ���������� ���� ��
	������ ��������� ��������� ������� � ������������ � ��������, ��������� � ������� ��������������
	���������. ���� ��� ������ - ������� �����, �� ����� �������� �������� �� �� ��� �����
	���������� �� �� ����� ������ �� �������� � � ��������� �����. ������� ��� ��� ��� �������
	���������� ����� ���������. � ������ ���� ����� ������ ���������, ������ ��� ������ ����
	��� �� ���� �����, ��� ��� ��� ���������� ������ �� ����� ������ �� �������� ����������,
	��� ��� �����, ������� ��� ��������� �� ������� ������ ��������, � ��� ���� �������
	����� ��������� ����.
	���������� ��������� � ���, ��� ��������� �������������� ������ � �� ���� ��������� ���
	�����. ��� ������� ������ ����� ���������� �� ��� �� � ������ � ����� ����, � ��������
	������� �� ��� ���� � �������������� ������� �� �����. ������ ������ �������� ���������
	������� �� � ������� �������� � ��������� ����������� ������. ���, � �����, �������.

	����������� �� �� ������ ��, ������������ - �� ������ �� ������ static. ���� ��� ���
	������ �� ��������(� �� ��� ������ �������, ������ �� ����� �������� �� ����� ��������������
	����������) �� �������� ���������� usedElements ��� � ���������� ������������ ��� � main
	*/
	static int* usedElements = (int*)malloc(elements * sizeof(int));
	if (countOfUsedElements != elements)
		for (int i = firstElement(usedElements, countOfUsedElements); i < elements; nextElement(usedElements, countOfUsedElements, i))
		{
			usedElements[countOfUsedElements] = i;
			recursionPrintAllCombinationOfElemens(array, elements, countOfUsedElements + 1);
		}
	else
	{
		for (int i = 0; i < elements; ++i)
			printf("%d\t", array[usedElements[i]]);
		printf("\n");
	}
}

void main()
{
	int n = askNumberOfElements(),
		*m = packArray(n);

	printf("Vse vozmojnie kombinacii elementov:\n");
	recursionPrintAllCombinationOfElemens(m, n);

	free(m);
	system("pause");
}