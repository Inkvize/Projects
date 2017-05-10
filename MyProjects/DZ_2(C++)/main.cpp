#include <iostream>

#include "Menu.h"
#include "Array.h"
#include "bitstring.h"
#include "fraction.h"
#include "Exc.h"

Array *arr_a, *arr_b;

int Arr_Info() {
    std::cout << "1.a" << std::endl << "2.b" << std::endl;
    int val;
    std::cin >> val;
    return val;
}

void SizeArr() {
    switch (Arr_Info()) {
    case 1:std::cout << "������ ������� " << arr_a->getlen() << std::endl; break;
    case 2:std::cout << "������ ������� " << arr_b->getlen() << std::endl; break;
    }
}

void NewSizeArr() {
    int n_size;
    switch (Arr_Info()) {
    case 1:std::cout << "������� ����� ������" << std::endl;
    x: std::cin >> n_size;
        try {
            arr_a->NewSize(n_size);
        }
        catch (ErrorSizeArray ex) {
            ex.ErrorInfo();
            std::cout << "���������� ��� ���" << std::endl;
            goto x;
        }
        catch (ErrorSizeLimit er) {
            er.Info();
            std::cout << "����������� � ���������" << std::endl;
        }
        break;
    case 2:std::cout << "������� ����� ������" << std::endl;
    x1: std::cin >> n_size;
        try {
            arr_b->NewSize(n_size);
        }
        catch (ErrorSizeArray ex) {
            ex.ErrorInfo();
            std::cout << "���������� ��� ���" << std::endl;
            goto x1;
        }
        catch (ErrorSizeLimit er) {
            er.Info();
            std::cout << "����������� � ���������" << std::endl;
        }
    }
}

void InArr() {
    int num;
    switch (Arr_Info()) {
    case 1:std::cout << "������� �����" << std::endl;
    x: std::cin >> num;
        try {
            arr_a->InputVal(num);
        }
        catch (ErrorNumWrite ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "���������� ��� ���" << std::endl;
            goto x;
        }
        catch (ErrorSizeLimit ex) {
            ex.Info();
            std::cout << "���������� � ��������� ���������" << std::endl;
        }
        break;
    case 2:std::cout << "������� �����" << std::endl;
    x1: std::cin >> num;
        try {
            arr_b->InputVal(num);
        }
        catch (ErrorNumWrite ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "���������� ��� ���" << std::endl;
            goto x1;
        }
        catch (Exc ex) {
            ex.Info();
            std::cout << "���������� � ��������� ���������" << std::endl;
        }
    }
}

void InArrSumb() {
    switch (Arr_Info()) {
    case 1:x:std::cout << "������� ��������(" << arr_a->getlen() << ')' << std::endl;
        try {
            std::cin >> *arr_a;
        }
        catch (Exc er) {
            er.Info();
            std::cout << "���������� ��� ���" << std::endl;
            goto x;
        }
        break;
    case 2:x1:std::cout << "������� ��������(" << arr_b->getlen() << ')' << std::endl;
        try {
            std::cin >> *arr_b; break;
        }
        catch (Exc er) {
            er.Info();
            std::cout << "���������� ��� ���" << std::endl;
            goto x1;
        }
    }
}

void SumArray() {
    std::cout << "a+b" << std::endl << *arr_a << std::endl << '+' << std::endl << *arr_b << std::endl << '=' << std::endl;
    try {
        std::cout << (*arr_a) + (*arr_b) << std::endl;
    }
    catch (ErrorSizeLimit er) {
        er.Info();
        std::cout << "�������� ��������� � ���������� �����" << std::endl;
    }
}

void OutArray() {
    std::cout << "a" << std::endl << *arr_a << std::endl << "b" << std::endl << *arr_b << std::endl;
}

void MakeArr() {
    if (arr_a) delete arr_a;
    arr_a = new Array(0);
    if (arr_b) delete arr_b;
    arr_b = new Array(0);
}

void MakeBit() {
    if (arr_a) delete arr_a;
    arr_a = new BitString(0);
    if (arr_b) delete arr_b;
    arr_b = new BitString(0);
}

void MakeFrac() {
    if (arr_a) delete arr_a;
    arr_a = new Fraction(0);
    if (arr_b) delete arr_b;
    arr_b = new Fraction(0);
}

void OperBit() {
    std::cout << "������� ��������(+, |, *, ^, ~, >, <)((a operation b),(operation a))" << std::endl;
    char op;
    std::cin >> op;
    std::cout << (*arr_a) << std::endl << op << std::endl << (*arr_b) << std::endl << '=' << std::endl;;
    try {
        switch (op) {
        case '|':std::cout << (*(reinterpret_cast<BitString*>(arr_a)) | *(reinterpret_cast<BitString*>(arr_b))) << std::endl; break;
        case '+':std::cout << (*arr_a) + (*arr_b) << std::endl; break;
        case '*':std::cout << (*(reinterpret_cast<BitString*>(arr_a)) & *(reinterpret_cast<BitString*>(arr_b))) << std::endl; break;
        case '^':std::cout << (*(reinterpret_cast<BitString*>(arr_a)) ^ *(reinterpret_cast<BitString*>(arr_b))) << std::endl; break;
        case '~':std::cout << ~(*(reinterpret_cast<BitString*>(arr_a))) << std::endl;
        }
    }
    catch (Exc er) {
        er.Info();
        std::cout << "�������� ��������� � ���������� �����" << std::endl;
    }
    if (op == '>' || op == '<') {
        std::cout << "������� ��������" << std::endl;
        int sh = 0;
        std::cin >> sh;
        BitString out = *(reinterpret_cast<BitString*>(arr_a));
        switch (op) {
        case '>':out >> sh; break;
        case '<':out << sh;
        }
        std::cout << out << std::endl;
    }
}

void OperFrac() {
    std::cout << "������� ��������(+, -, *, >, <, =)(a operation b)" << std::endl;
    char op;
    std::cin >> op;
    std::cout << *(reinterpret_cast<Fraction*>(arr_a)) << std::endl << op << std::endl << *(reinterpret_cast<Fraction*>(arr_b)) << std::endl << '=' << std::endl;;
    try {
        switch (op) {
        case '+':std::cout << (*(dynamic_cast<Fraction*>(arr_a)) + *(reinterpret_cast<Fraction*>(arr_b))) << std::endl; break;
        case '-':std::cout << (*(reinterpret_cast<Fraction*>(arr_a)) - *(reinterpret_cast<Fraction*>(arr_b))) << std::endl; break;
        case '*':std::cout << (*(reinterpret_cast<Fraction*>(arr_a)) * *(reinterpret_cast<Fraction*>(arr_b))) << std::endl; break;
        case '/':std::cout << (*(reinterpret_cast<Fraction*>(arr_a)) == *(reinterpret_cast<Fraction*>(arr_b))) << std::endl; break;
        case '>':std::cout << (*(reinterpret_cast<Fraction*>(arr_a)) > *(reinterpret_cast<Fraction*>(arr_b))) << std::endl; break;
        case '<':std::cout << (*(reinterpret_cast<Fraction*>(arr_a)) < *(reinterpret_cast<Fraction*>(arr_b))) << std::endl; break;
        case '=':std::cout << (*(reinterpret_cast<Fraction*>(arr_a)) == *(reinterpret_cast<Fraction*>(arr_b))) << std::endl;
        }
    }
    catch (Exc er) {
        er.Info();
        std::cout << "�������� �������� ������ � ��������� ��������" << std::endl;
    }
}

void InFrac() {
    std::cout << "������� ��������� � ����������� ������(2)" << std::endl;
    switch (Arr_Info()) {
    case 1:x:std::cout << "������� ����� " << std::endl;
        try {
            std::cin >> (*(reinterpret_cast<Fraction*>(arr_a)));
        }
        catch (DevNilFraction er) {
            er.Info();
            std::cout << "���������� ��� ���" << std::endl;
            system("pause");
            goto x;
        }
        catch (ErrorSizeLimit er) {
            er.Info();
            std::cout << "���������� � ��������� ���������" << std::endl;
        }
        catch (ErrorNumWrite er) {
            std::cout << er.what() << std::endl;
            std::cout << "���������� ��� ���" << std::endl;
            system("pause");
            goto x;
        }
        break;
    case 2:x1:std::cout << "������� ����� " << std::endl;
        try {
            std::cin >> (*(reinterpret_cast<Fraction*>(arr_b)));
        }
        catch (DevNilFraction er) {
            er.Info();
            std::cout << "���������� ��� ���" << std::endl;
            system("pause");
            goto x1;
        }
        catch (ErrorSizeLimit er) {
            er.Info();
            std::cout << "���������� � ��������� ���������" << std::endl;
        }
        catch (ErrorNumWrite er) {
            std::cout << er.what() << std::endl;
            std::cout << "���������� ��� ���" << std::endl;
            system("pause");
            goto x1;
        }
    }
}

void OutielemArr() {
    int i;
    switch (Arr_Info()) {
    case 1:std::cout << "������� ������" << std::endl;;
        std::cin >> i;
        try {
            std::cout << "arr[" << i << "] = " << int((*arr_a)[i]) << std::endl;
        }
        catch (ErrorIndexArray er) {
            er.Info();
            std::cout << "�������� ��������� � ���������� ��� ���" << std::endl;
            system("pause");
        }
        break;
    case 2:std::cout << "������� ������" << std::endl;;
        std::cin >> i;
        try {
            std::cout << "arr[" << i << "] = " << int((*arr_b)[i]) << std::endl;
        }
        catch (ErrorIndexArray er) {
            er.Info();
            std::cout << "�������� ��������� � ���������� ��� ���" << std::endl;
            system("pause");
        }
    }
}

void OutFrac() {
    std::cout << "a" << std::endl << (*(reinterpret_cast<Fraction*>(arr_a))) << std::endl << "b" << std::endl << (*(reinterpret_cast<Fraction*>(arr_b))) << std::endl;
}

void Clean() {
    if (arr_a) delete arr_a;
    if (arr_b) delete arr_b;
}

int main() {
    system("chcp 1251");
    system("color f0");
    system("cls");
    Menu Main(4), Array(7), BitStr(6), Frac(4);
    Main.PushLine(0, "1.������", &Array, MakeArr);
    Main.PushLine(1, "2.������� ������", &BitStr, MakeBit);
    Main.PushLine(2, "3.������������ �����", &Frac, MakeFrac);
    Main.PushLine(3, "4.�����", nullptr, nullptr);
    Array.PushLine(0, "1.������ ������", nullptr, SizeArr);
    Array.PushLine(1, "2.�������� ������", nullptr, NewSizeArr);
    Array.PushLine(2, "3.����������� �������", nullptr, OutArray);
    Array.PushLine(3, "4.������ ����� � ������", nullptr, InArr);
    Array.PushLine(4, "5.������ ������ �����������", nullptr, InArrSumb);
    Array.PushLine(5, "6.����� ���� ��������", nullptr, SumArray);
    Array.PushLine(6, "7.�����", &Main, nullptr);
    BitStr.PushLine(0, "1.��������", nullptr, OutArray);
    BitStr.PushLine(1, "2.�������� i �������", nullptr, OutielemArr);
    BitStr.PushLine(2, "3.������ �������", nullptr, NewSizeArr);
    BitStr.PushLine(3, "4.��������", nullptr, InArrSumb);
    BitStr.PushLine(4, "5.��������", nullptr, OperBit);
    BitStr.PushLine(5, "6.�����", &Main, nullptr);
    Frac.PushLine(0, "1.�������� �����", nullptr, OutFrac);
    Frac.PushLine(1, "2.������ �����", nullptr, InFrac);
    Frac.PushLine(2, "3.��������", nullptr, OperFrac);
    Frac.PushLine(3, "4.�����", &Main, nullptr);
    Main.Run();
    Clean();
    system("pause");
    return 0;
}
