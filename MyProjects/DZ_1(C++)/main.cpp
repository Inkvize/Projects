#include <string>

#include "Money.h"
#include "Menu.h"
#include "Account.h"

Money One, Two, Res;
Money Coin(25000.76);
Account Bank_K("Default", 1234567890, 10, Coin, 'R');

void OutSumBank_K() {
    std::cout << Bank_K.towords() << std::endl;
}

void MoneyOperationOdTipe() {
    std::cout << "������� ��������" << std::endl;
    char op;
    std::cin >> op;
    switch (op) {
    case '+':Res = One + Two; break;
    case '-':Res = One - Two; break;
    case '/':Res = One / Two;
    }
    std::cout << One << op << Two << "=" << Res << std::endl;
}

void GetMoney() {
    std::cout << "���� 1 ��������" << std::endl;
    std::cin >> One;
    std::cout << "���� 2 ��������" << std::endl;
    std::cin >> Two;
}

void MoneySrOper() {
    std::cout << "������� ��������" << std::endl;
    char op;
    std::cin >> op;
    bool res = false;
    switch (op) {
    case '>':res = One > Two; break;
    case '<':res = One < Two; break;
    case '=':res = One == Two;
    }
    std::cout << One << op << Two << "=" << res << std::endl;
}

void PrintMoney() {
    std::cout << "One: " << One << std::endl;
    std::cout << "Two: " << Two << std::endl;
}

void PrintBank_K() {
    std::cout << Bank_K << std::endl;
}

void MoneyOperationRzTipe() {
    std::cout << "������� ������� ���� double(�������� ����� � 1 ��������� Money)" << std::endl;
    double a;
    std::cin >> a;
    std::cout << "������� ��������" << std::endl;
    char op;
    std::cin >> op;
    switch (op) {
    case '*':Res = One * a; break;
    case '/':Res = One / a;
    }
    std::cout << "���������" << std::endl;
    std::cout << One << op << a << "=" << Res << std::endl;
}

void MinusAccount() {
    std::cout << "������� ��������� �����" << std::endl;
    std::cin >> Coin;
    Bank_K.RemoveSum(Coin);
    std::cout << Bank_K;
}

void PlusAccount() {
    std::cout << "������� ����������� �����" << std::endl;
    std::cin >> Coin;
    Bank_K.PutSum(Coin);
    std::cout << Bank_K;
}

void NewNameKlient() {
    char a[100];
    std::cout << "������� ����� ���" << std::endl;
    std::cin >> a;
    Bank_K.NewName(a);
}

void ConvertBank() {
    std::cout << "������� ������ ������(R, U, E)" << std::endl;
    char v;
    std::cin >> v;
    switch (v) {
    case 'E':Bank_K.Euro(); break;
    case 'U':Bank_K.Dollars(); break;
    case 'R':Bank_K.Rub();
    }
}

void ProcBank_K() {
    Bank_K.Percentages();
    std::cout << Bank_K;
}

void CountObjClass() {
    std::cout << "���������� ��������� �������� Money - " << Money::Count() << std::endl;
    std::cout << "���������� ��������� �������� Menu - " << Menu::Count() << std::endl;
    std::cout << "���������� ��������� �������� Account - " << Account::Count() << std::endl;
}

int main() {
    system("chcp 1251");
    system("color f0");
    system("cls");
    Menu Main(4); Menu Moneys(4); Menu MoneyOper(4); Menu Bank(8);
    Main.PushLine(0, "1.������", &Moneys, nullptr);
    Main.PushLine(1, "2.����", &Bank, nullptr);
    Main.PushLine(2, "3.���������� ��������", nullptr, CountObjClass);
    Main.PushLine(3, "4.�����", nullptr, nullptr);
    Moneys.PushLine(0, "1.���� �����", nullptr, GetMoney);
    Moneys.PushLine(1, "2.��������", &MoneyOper, nullptr);
    Moneys.PushLine(2, "3.�������� �����", nullptr, PrintMoney);
    Moneys.PushLine(3, "4.�����", &Main, nullptr);
    MoneyOper.PushLine(0, "1.���������", nullptr, MoneySrOper);
    MoneyOper.PushLine(1, "2.�������� � ���������� �����", nullptr, MoneyOperationOdTipe);
    MoneyOper.PushLine(2, "3.������� � ������ �����", nullptr, MoneyOperationRzTipe);
    MoneyOper.PushLine(3, "4.�����", &Moneys, nullptr);
    Bank.PushLine(0, "1.�������� �����", nullptr, PrintBank_K);
    Bank.PushLine(1, "2.����� �����", nullptr, MinusAccount);
    Bank.PushLine(2, "3.�������� �����", nullptr, PlusAccount);
    Bank.PushLine(3, "4.������� ������������", nullptr, NewNameKlient);
    Bank.PushLine(4, "5.������� ������", nullptr, ConvertBank);
    Bank.PushLine(5, "6.��������� ��������", nullptr, ProcBank_K);
    Bank.PushLine(6, "7.������� ����� ��������", nullptr, OutSumBank_K);
    Bank.PushLine(7, "8.�����", &Main, nullptr);
    Main.Run();
    return 0;
}
