#include "Figures.h"
#include "Menu.h"

Figure *Test = nullptr;

void OutFigurParam() {
    if (Test != nullptr)
        Test->Out();
}

void UpdateFigure() {
    if (Test != nullptr)
        Test->Input();
}

void Clean() {
    if (Test)
        Figure::Destroy(Test);
}

void InitRec() {
    Clean();
    Test = Figure::make(1);
    Test->Input();
}

void InitCir() {
    Clean();
    Test = Figure::make(2);
    Test->Input();
}

void InitTrap() {
    Clean();
    Test = Figure::make(3);
    Test->Input();
}

int main() {
    system("chcp 1251");
    system("color f0");
    system("cls");
    Menu Main(4);
    Menu Figur_Op(4);
    Main.PushLine(0, "1.����������� ������", &Figur_Op, nullptr);
    Main.PushLine(1, "2.�������� ���������� ������", nullptr, OutFigurParam);
    Main.PushLine(2, "3.���������� ������", nullptr, UpdateFigure);
    Main.PushLine(3, "4.�����", nullptr, nullptr);
    Figur_Op.PushLine(0, "1.�������������", nullptr, InitRec);
    Figur_Op.PushLine(1, "2.����", nullptr, InitCir);
    Figur_Op.PushLine(2, "3.��������", nullptr, InitTrap);
    Figur_Op.PushLine(3, "4.�����", &Main, nullptr);
    Main.Run();
    Clean();
    system("pause");
    return 0;
}  
