#include <locale.h>
#include <time.h>
#include <Windows.h>

#include <iostream>

#include "sort.h"

using namespace std;

int main() {
	system("color f0");
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
    int *array;
    int size;
    cout << "������� ���������� ��������� �������\n";
    cin >> size;
    array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = rand() % 10 - rand() % 10;
    cout << "��������� �������� �������\n";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
    SortBubble(array, size);
    cout << "��������������� ������\n";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
    delete[] array;
    system("pause");
    return 0;
}
