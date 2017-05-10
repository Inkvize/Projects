#include <iostream>

struct Trades{//��������������� �������� ��� ������ � ���������� � ��������� �����
    char ProductName[25];
    char Country[25];
    int Direction;
    int Year, DealV;
}trade;

void PrintFile(FILE *f) {//������� ������ �����
    if (f != NULL) {
        int i = 1;
        rewind(f);
        printf("(�)������������ ������ | ������ ������������� | ��� ������ | ");
        printf("����� | �����������\n");
        while (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {//������ ���������� �� ������ �������, ��� ��� ���� ������� ������ ������� �������� ��������. ���� ������ �������� �� � ����� ���������
            printf("%3d.%-25s %-20s %-4d %10d     ", i, trade.ProductName, trade.Country, trade.Year, trade.DealV);
            if (trade.Direction == 1) {
                printf(" %-7s\n", "������");
            } else {
                printf(" %-7s\n", "�������");
            }
            i++;
        }
        rewind(f);
        std::cin.ignore(); std::cin.get();
        system("cls");
    }
}


void NewFile(FILE *f, char *name) {//������� �������� ������ �����
    printf("������� �������� �����\n");
    std::cin >> name;
    fcloseall();
    f = fopen(name, "w+");
    system("cls");
}

int strlen(FILE *f) {//��������� ����������� ����������� ���������(����������) � �����
    if (f != NULL) {
        int i = 1;
        rewind(f);
        while (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {
            i++;
        }
        rewind(f);
        return i;
    }
    return 0;
}

void OpenFile(FILE *f, char *name) {//������� �������� ����� ������
    printf("������� �������� �����\n");
    std::cin >> name;
    f = fopen(name, "r");
    PrintFile(f);
}

void RedactNewInfoFile(FILE *f) {//���������� ����� ���������� � ����
    if (f != NULL) {
        int count;
        printf("������� ���������� �������� ���������\n");
        std::cin >> count;
        printf("������ ����� ����������: ");
        printf("������������ ������, ������ �������������,��� ������, ");
        printf("�����, �����������(������-1, �������-0)\n");
        fseek(f, -2, SEEK_END);
        for (int i = 0; i < count; i++) {
            scanf("%s %s %d %d %d", &trade.ProductName, &trade.Country, &trade.Year, &trade.DealV, &trade.Direction);
            fprintf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, trade.Year, trade.DealV, trade.Direction);
        }
        system("cls");
    }
}

void DelFileInfo(FILE *f, char *NameFile) {//�������� ���������� �� ������� ��������� ��������� ��� ������
    if (f != NULL) {
        FILE *out = fopen("tmp.txt", "w+");
        PrintFile(f);
        int num;
        bool res = false;
        printf("������� ����� ���������� ������\n");
        std::cin >> num;
        if (num > 0 && num <=strlen(f)) {
            for (int i = 1; i < num && fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF; i++) {
                fprintf(out, "%s %s %d %d %d\n", trade.ProductName, trade.Country, trade.Year, trade.DealV, trade.Direction);
                res = true;
            }
            if (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {
                res = true;
                while (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {
                    fprintf(out, "%s %s %d %d %d\n", trade.ProductName, trade.Country, trade.Year, trade.DealV, trade.Direction);
                }
            }
            else {
                res = false;
            }
            fclose(f); fclose(out);
            remove(NameFile);
            rename("tmp.txt", NameFile);
            f = fopen(NameFile, "r");
        } else {
            res = false;
        }
        if (res) {
            printf("�������� ������ �������!\n");
        } else {
            printf("������� �� ������!\n");
        }
        std::cin.ignore(); std::cin.get(); system("cls");
    }
}

void SearchCountry(FILE *f) {//����� ������ � ������������� �� �������
    if (f != NULL) {
        char nameC[25];
        int sumV = 0;
        rewind(f);
        printf("������� �������� ������\n");
        std::cin >> nameC;
        printf("��������� ������:\n");
        while (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {
            if (strcmp(nameC, trade.Country) == 0 && trade.Direction == 1) {
                printf("%s\n", trade.ProductName);
                sumV += trade.DealV;
            }
        }
        printf("��������� ����� ������ �������:%d\n", sumV);
        rewind(f);
    }
}

void MaxExport(FILE *f) {//����� ������ � ������������ ���������
    char TmpC[25], CountryMax[25];
    int sum = 0, sumk = 0;
    for (int i = 1; i <= strlen(f); i++) {
        sum = 0;
        rewind(f);
        for (int j = 0; j <= i; j++) {
            fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction);
        }
        strcpy(TmpC, trade.Country);
        rewind(f);
        while (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {
            if (strcmp(trade.Country, TmpC) == 0 && trade.Direction == 0) {
                sum += trade.DealV;
            }
        }
        if (sum > sumk) {
            sumk = sum;
            strcpy(CountryMax, TmpC);
        }
    }
    printf("������ � ������������ ��������� - %s \n��������� ����� - %d", CountryMax, sumk);
}

void SearchProduct(FILE *f) {//����� ����� � ������������� ������ ���������
    if (f != NULL) {
        char Product[25];
        printf("������� ��� ������\n");
        std::cin >> Product;
        printf("��������� ������ � ������������� ������ ������� � �������:\n");
        rewind(f);
        while (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {
            if (strcmp(trade.ProductName, Product) == 0 && trade.Direction == 1) {
                printf("%-25s %5d\n", trade.Country, trade.DealV);
            }
        }
        rewind(f);
    }
}

void sms1() {//���� �������
    printf("1.������� ����\n");
    printf("2.������ ����\n");
    printf("3.����������� ����\n");
    printf("4.������������� ����\n");
    printf("5.�������\n");
    printf("6.�����\n");
}

void sms2() {//���� ��������������
    printf("1.�������� �������(�)\n");
    printf("2.������� �������\n");
}

void sms3() {//���� ��������
    printf("1.���������� ��� ������, ������������� �� ������ ������ � ��������� ����� ������\n");
    printf("2.���������� ������, ������� � ������� ����� ���������� �����\n");
    printf("3.���������� ��� ������, �� ������� ������������� ������ �����, � ����� ������ � ������ ������\n");
}

int main() {
    system("chcp 1251");
    system("color f0");
    system("cls");
    char name[25];
    strcpy(name, "base.txt");
    int n;
    printf("����������� ��� ���� ������ base.txt\n");
    FILE *f = fopen("base.txt", "a+");//���� �� ��������� � ����� ������
    do {//���������� ����
        sms1();
        std::cin >> n; system("cls");
        switch (n) {
        case 1:NewFile(f, name); break;
        case 2:OpenFile(f, name); break;
        case 3:PrintFile(f); break;
        case 4:sms2(); std::cin >> n; system("cls");
            switch (n) {
            case 1:RedactNewInfoFile(f); break;
            case 2:DelFileInfo(f, name);
            }
            break;
        case 5:sms3(); std::cin >> n; system("cls");
            switch (n) {
            case 1:SearchCountry(f); break;
            case 2:MaxExport(f); break;
            case 3:SearchProduct(f);
            }
            std::cin.ignore(); std::cin.get(); system("cls");
        }
    } while (n != 6);
    fcloseall();
    return 0;
}
