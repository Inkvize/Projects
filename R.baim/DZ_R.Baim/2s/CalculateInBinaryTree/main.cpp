#include <iostream>
#include <ctime>
#include <string.h>
#include <cmath>

#include "Menu.h"

struct Node {
    char info[32];
    Node *l, *r;
};

char term[][32] = {"(", "(", "1", "+", "0", ")", "*", "(", "2", "-", "3", "*", "(", "7", "-", "0", ")", ")", ")"};
Node *tree = NULL;
double a = 0, b = 0;
bool key_r = false;

int Prioritet(char *arr) {
    if (strlen(arr) > 1) return 100;
    switch (*arr) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 100;
}

bool CheckNumber(Node *tree) {
    if (!tree) return 0;
    int i = 0;
    while (tree->info[i]) {
        if (strchr("0123456789-.", tree->info[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}


Node *MakeTree(char term[][32], int first, int last) {
    int minop = 100, ptr, k;
    int nest = 0;
    bool error = true;
    char c;
    Node *res = new Node;
    res->r = res->l = NULL;
    if (first == last) {
        strcpy(res->info, term[first]);
        return res;
    }
    for (int i = first; i <= last; i++) {
        c = term[i][0];
        if (c == '(') {
            nest++;
            continue;
        }
        if (c == ')') {
            nest--;
            continue;
        }
        if (nest > 0) continue;
        ptr = Prioritet(term[i]);
        if (ptr <= minop) {
            minop = ptr;
            error = false;
            k = i;
        }
    }
    if (error && !(minop == 100 && term[first][0] == '(' && term[last][0] == ')')) {
        delete res;
        throw "������ ���������� ������";
    }
    if (minop == 100 && term[first][0] == '(' && term[last][0] == ')')
        return MakeTree(term, first + 1, last - 1);
    strcpy(res->info, term[k]);
    res->l = MakeTree(term, first, k - 1);
    res->r = MakeTree(term, k + 1, last);
    return res;
}

void DelNode(Node *&tree) {//�������� ������ �� ������
    if (tree != NULL) {
        DelNode(tree->l);
        DelNode(tree->r);
        delete tree;
        tree = NULL;
    }
}

void Calculate(Node **tree) {//������ ������ ����� � �������� ��������, ���� ������� �����
    if (!(*tree) || !CheckNumber((*tree)->r) || !CheckNumber((*tree)->l)) return;
    double a, b, c;
    a = atof((*tree)->l->info);
    b = atof((*tree)->r->info);
    if (b == 0. && strchr((*tree)->info, '/')) throw "������� �� 0!";
    switch ((*tree)->info[0]) {
        case '+':
            c = a + b;
            break;
        case '-':
            c = a - b;
            break;
        case '*':
            c = a * b;
            break;
        case '/':
            c = a / b;
            break;
        case '^':
            c = pow(a, b);
    }
    delete (*tree)->l;
    delete (*tree)->r;
    sprintf((*tree)->info, "%lf", c);
    (*tree)->l = (*tree)->r = NULL;
}

void Calculated(Node **tree) {//����� ������ ��� ������� ���� ��������
    if (*tree) {
        Calculated(&((*tree)->l));
        Calculated(&((*tree)->r));
        Calculate(tree);
    }
}

void Inputa_() {
    std::cout << "������� a" << std::endl;
    std::cin >> a;
    if (a < -1000 || a > 1000) throw "����� ������ �������, ����������� �������� �� ���������(0)\n";
}

void Inputb_() {
    std::cout << "������� b" << std::endl;
    std::cin >> b;
    if (b < -1000 || b > 1000) throw "����� ������ �������, ����������� �������� �� ���������(0)\n";//����� ����������
}

void Inputa() {//��������� ����������
    try {
        Inputa_();
    }
    catch (const char *ex) {
        std::cout << ex;
        a = 0;
    }
}

void Inputb() {
    try {
        Inputb_();
    }
    catch (const char *ex) {
        std::cout << ex;
        b = 0;
    }
}

void OutInputCalc() {
    sprintf(term[4], "%lf", a);//������ ��������� a � b
    sprintf(term[15], "%lf", b);//
    tree = MakeTree(term, 0, 18);
    Calculated(&tree);
    std::cout << "a = " << a << " " << "b = " << b << std::endl;
    std::cout << "(1 + a)*(2 - 3 * (7 - b)) = " << tree->info << std::endl;
    DelNode(tree);
}

void Random() {
    a = (rand() % 20000) / 10.0 - 1000;
    b = (rand() % 20000) / 10.0 - 1000;
    std::cout << "a = " << a << " " << "b = " << b << std::endl;
}

void OutParams() {
    std::cout << "a = " << a << " " << "b = " << b << std::endl;
}

void ShowNode(Node *&Tree) {//����� ������ �������������� � ������� �� ��������(��������� ����� ����� ����� � �������)
    if (Tree != NULL) {
        std::cout << '(';
        ShowNode(Tree->l);
        std::cout << Tree->info;
        ShowNode(Tree->r);
        std::cout << ')';
    }
}

void PrintTree(Node *&pNode, int n) {
    if (pNode->l) PrintTree(pNode->l, n + 3);
    for (int i = 0; i < n; i++) printf(" ");
    printf("%s\n", pNode->info);
    if (pNode->r) PrintTree(pNode->r, n + 3);
}

void Out() {
    sprintf(term[4], "%lf", a);//������ ��������� a � b
    sprintf(term[15], "%lf", b);//
    tree = MakeTree(term, 0, 18);
    ShowNode(tree);
    std::cout << std::endl << std::endl;
    PrintTree(tree, 10);
    std::cout << std::endl;
    DelNode(tree);
}

int CharCheck(char s) {
    switch (s) {
        case '(':
            return 1;
        case ')':
            return -1;
    }
    return 0;
}

bool StringCheck(char *str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        count += CharCheck(*(str + i));
        if (count < 0) return false;
        if (str[i] == '(' && str[i + 1] == ')') return false;
    }
    if (count == 0) {
        return true;
    } else {
        return false;
    }
}

void DelProbels(char *str) {
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ' ')
            for (int j = i; j <= strlen(str) - 1; j++)
                str[j] = str[j + 1];
}

void InputCalculate() {
    std::cout << "������� ��������� ��� �������" << std::endl;
    char str[100];
    int count = 0;
    double tmp;
    std::cin >> str;
    DelProbels(str);
    if (str[0] == '-') {
        for (int i = strlen(str); i >= 0; i--) {
            str[i + 1] = str[i];
        }
        str[0] = '0';
    }
    if (StringCheck(str) && strlen(str)) {
        char calc[100][32];
        for (int i = 0; i < strlen(str); i++) {
            if (strchr("()*+/-^", str[i])) {
                calc[count][0] = str[i];
                calc[count][1] = '\0';
                count++;
            } else {
                if (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_", str[i])) {
                    char *out = str + i;
                    while (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_", *(out + 1)) &&
                           *(out + 1) != '\0')
                        out++;
                    switch (key_r) {
                        case 0:
                            std::cout << "������� ��������: " << std::endl;
                            break;
                        case 1:
                            break;
                    }
                    while ((str + i) != (out + 1)) std::cout << *(str + (i++));
                    i--;
                    std::cout << " = ";
                    switch (key_r) {
                        case 0:
                            std::cin >> tmp;
                            break;
                        case 1:
                            tmp = (rand() % 20000) / 10.0 - 1000;
                            std::cout << tmp << std::endl;
                    }
                } else {
                    tmp = atof(str + i);
                    while (strchr("0123456789.", str[i + 1]))
                        i++;
                }
                sprintf(calc[count], "%lf", tmp);
                count++;
            }
        }
        try {
            tree = MakeTree(calc, 0, count - 1);
            std::cout << "������:";
            std::cout << std::endl << std::endl;
            PrintTree(tree, 10);
            std::cout << std::endl;
            Calculated(&tree);
            std::cout << "�����: " << tree->info << std::endl;
            std::cout << std::endl;
        }
        catch (const char *ex) {
            std::cout << ex << std::endl;
        }
        DelNode(tree);
    } else {
        std::cout << "������ � ���������" << std::endl;
    }
}

void Help() {
    std::cout << "��������� ������� ��������� (1+a)*(2-3*(7-b)), ��� a, b - double(-1000, 1000)" << std::endl;
    std::cout << "�������� ����� ������(�� ������� � ������ � ����������), ������������ ��������� �����" << std::endl;
    std::cout << "���������� ����� � ������� � ���������(A-Z, a-z, \"-\")" << std::endl;
    std::cout << "��� ��������� ����� ���������� ������������ ����(+)" << std::endl;
    std::cout << "������������� ��������� ������ ���� ������� �� ����, ������������ ����������� ������" << std::endl;
    std::cout << "��� �������� ����� ������������ ���� ���������� �������� ��� ���� enter" << std::endl;
}

void KeyRand() {
    std::cout << "���������� �����: ";
    if (key_r) {
        std::cout << '+';
    } else {
        std::cout << '-';
    }
    std::cout << std::endl;
    bool key_key;
    std::cout << "������� ���������?(1-��, 0-���)" << std::endl;
    std::cin >> key_key;
    if (key_key) {
        key_r = !key_r;
        std::cout << "OK!" << std::endl;
    }
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    Menu Main(
            10);//������ ���� ������� ������ ���� ����������, ����� ������� �������� ����, ������ ��������� ����� ��������(3 ��������)
    Main.PushLine(0, "1.������ a", nullptr, &Inputa);//������������� ����� ����
    Main.PushLine(1, "2.������ b", nullptr, &Inputb);
    Main.PushLine(2, "3.�������. a � b", nullptr, &Random);
    Main.PushLine(3, "4.����������� a � b", nullptr, &OutParams);
    Main.PushLine(4, "5.���������", nullptr, &OutInputCalc);
    Main.PushLine(5, "6.����� ������", nullptr, &Out);
    Main.PushLine(6, "7.�����������", nullptr, &InputCalculate);
    Main.PushLine(7, "8.���� ������� ��� ������������", nullptr, &KeyRand);
    Main.PushLine(8, "9.������", nullptr, &Help);
    Main.PushLine(9, "10.�����", nullptr, nullptr);
    Main.Run();//������ ����
    return 0;
}