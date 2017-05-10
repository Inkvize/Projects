#include "vector.h"
#include "csr.h"
#include "Menu.h"
#include "Exc.h"

void MalMatrixVect() {
    CSR A(0);
    std::cout << "������� �������(�����������, ����� ��������)" << std::endl;
    std::cin >> A;
    std::cout << A;
    int size_m = A.GetSize();
    Vector x(size_m);
    std::cout << "������� ������ ������������ " << size_m << std::endl << std::endl;
    std::cin >> x;
    std::cout << "���������:" << std::endl << (A*x) << std::endl;
}

void MalVec_sh() {
    std::cout << "������� ����������� �������" << std::endl;
    int size;
    std::cin >> size;
    Vector x(size);
    std::cout << "������� ������" << std::endl << std::endl;
    std::cin >> x;
    std::cout << "������� �����" << std::endl;
    double mal;
    std::cin >> mal;
    std::cout << "���������:" << std::endl << (mal*x) << std::endl;
}

void MalVec_vs() {
    std::cout << "������� ����������� ��������" << std::endl;
    int size;
    std::cin >> size;
    Vector x(size), y(size);
    std::cout << "������� ������� x � y" << std::endl << std::endl;
    std::cin >> x >> y;
    std::cout << "���������:" << std::endl << (y&x) << std::endl;
}

void MalVec_vv() {
    std::cout << "������� ����������� ��������" << std::endl;
    int size1, size2;
    std::cin >> size1 >> size2;
    Vector x(size1), y(size2);
    std::cout << "������� ������� x � y" << std::endl << std::endl;
    std::cin >> x >> y;
    try {
        std::cout << "���������(1 �� 2):" << std::endl << (x*y) << std::endl;
    }
    catch (ErrorMalVec er) {
        std::cout << er.what() << '(' << er.errordem1 << ' ' << er.errordem2 << ')' << std::endl;
    }
}

void SumVec() {
    std::cout << "������� ����������� ��������" << std::endl;
    int size;
    std::cin >> size;
    Vector x(size), y(size);
    std::cout << "������� �������" << std::endl << std::endl;
    std::cin >> x >> y;
    std::cout << "���������:" << std::endl << (y + x) << std::endl;
}

void VecLenght() {
    std::cout << "������� ����������� �������" << std::endl;
    int size;
    std::cin >> size;
    Vector x(size);
    std::cout << "������� ������" << std::endl << std::endl;
    std::cin >> x;
    std::cout << "����� �������:" << std::endl << x.lenght_vect_g() << std::endl;
}

void MalMatrix_ch() {
    std::ofstream fout("test.txt");
    CSR A(3, 3);
    std::cout << "������� �������(�����������, ����� ��������)" << std::endl;
    std::cin >> A;
    std::cout << "������� �����" << std::endl;
    double mal;
    std::cin >> mal;
    std::cout << "���������:" << std::endl << A*mal << std::endl;
    fout << A*mal;
    fout.close();
    std::ifstream fcin("test.txt");
    fcin >> A;
    std::cout << "������� �����" << std::endl;
    std::cin >> mal;
    std::cout << "���������:" << std::endl << A*mal << std::endl;
    fcin.close();
}

void UnaryVector() {
    std::cout << "������� ����������� �������" << std::endl;
    int size;
    std::cin >> size;
    Vector x(size);
    std::cout << "������� ������" << std::endl << std::endl;
    std::cin >> x;
    char op;
    std::cout << "������� ������� ��������" << std::endl;
    std::cin >> op;
    switch (op) {
    case '+': +x; break;
    case '-': x = -x;
    }
    std::cout << "���������:" << std::endl << x << std::endl;
}

void ElemOperetor() {
    std::cout << "������� ����������� �������" << std::endl;
    int size;
    std::cin >> size;
    Vector x(size);
    std::cout << "������� ������" << std::endl << std::endl;
    std::cin >> x;
    int in;
    std::cout << "������� ������" << std::endl;
    std::cin >> in;
    try {
        std::cout<< "x[" << in << "] = " << x[in] << std::endl;
    }
    catch (ErrorIndex er) {
        std::cout << er.what() << er.errorind << std::endl;
    }
}

int main() {
    system("chcp 1251");
    system("color f0");
    system("cls");
    Menu Main(4), Vec(8), Matrix(2);
    Main.PushLine(0, "1.��������� ��������", &Vec, nullptr);
    Main.PushLine(1, "2.��������� ��������", &Matrix, nullptr);
    Main.PushLine(2, "3.��������� ���. � ���.(A*x)", nullptr, MalMatrixVect);
    Main.PushLine(3, "4.�����", nullptr, nullptr);
    Vec.PushLine(0, "1.��������� �� �����", nullptr, MalVec_sh);
    Vec.PushLine(1, "2.��������� ���������", nullptr, MalVec_vs);
    Vec.PushLine(2, "3.��������� ���������", nullptr, MalVec_vv);
    Vec.PushLine(3, "4.�������� ��������", nullptr, SumVec);
    Vec.PushLine(4, "5.����� �������", nullptr, VecLenght);
    Vec.PushLine(5, "6.������� ��������", nullptr, UnaryVector);
    Vec.PushLine(6, "7.��������� � ��������", nullptr, ElemOperetor);
    Vec.PushLine(7, "8.�����", &Main, nullptr);
    Matrix.PushLine(0, "1.��������� �� �����", nullptr, MalMatrix_ch);
    Matrix.PushLine(1, "2.�����", &Main, nullptr);
    Main.Run();
    system("pause");
    return 0;
}
