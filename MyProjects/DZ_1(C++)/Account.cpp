#include "Account.h"

int Account::CountObj = 0;

int Account::Count() {
    return CountObj;
}

Account::Account() {
    �urrency = 0;
    Num = 0;
    Proc = 0;
    CountObj++;
}

Account::Account(const Account &acc) {
    �urrency = acc.�urrency;
    Num = acc.Num;
    Proc = acc.Proc;
    Sum = acc.Sum;
    strcpy_s(Name, sizeof(Name), acc.Name);
    CountObj++;
}

void Account::Rub() {
    switch (�urrency) {
    case'U':Sum *= 58.011; break;
    case'E':Sum *= 61.36;
    }
    �urrency = 'R';
}

Account::Account(char *name, int num, double proc, Money &sum, char currency) {
    �urrency = currency;
    Num = num;
    Proc = proc / 100;
    Sum = sum;
    strcpy_s(Name, sizeof(Name), name);
    CountObj++;
}

Account::~Account() {
    �urrency = 0;
    Num = 0;
    Proc = 0;
}

void Account::NewName(char *newname) {
    strcpy_s(Name, sizeof(Name), newname);
}

void Account::RemoveSum(const Money &rem) {
    Sum -= rem;
}

void Account::PutSum(const Money &put) {
    Sum += put;
}

void Account::Percentages() {
    if (Proc > 0) {
        Sum *= (1 + Proc);
    }
}

void Account::Dollars() {
    switch (�urrency) {
    case'R':Sum /= 58.011; break;
    case'E':Sum *= 1.06;
    }
    �urrency = 'U';
}

void Account::Euro() {
    switch (�urrency) {
    case'R':Sum /= 61.36; break;
    case'U':Sum *= 0.96;
    }
    �urrency = 'E';
}

std::ostream& operator<<(std::ostream &stream, const Account &obj) {
    stream << "���: " << obj.Name << " ����� �����: ";
    stream << obj.Num << " �������: " << obj.Proc * 100;
    stream << " �����: " << obj.Sum << " ������: " << obj.�urrency;
    return stream;
}

std::istream& operator >> (std::istream &stream, Account &obj) {
    stream >> obj.Name >> obj.Num >> obj.Proc >> obj.Sum >> obj.�urrency;
    return stream;
}

std::string Account::towords() {
    switch (�urrency) {
    case'R':return _towords(Sum.GetZ()) + " ���. " + _towords(Sum.GetQ()) + " ���.";
    case'E':return _towords(Sum.GetZ()) + " ���� " + _towords(Sum.GetQ()) + " ��������";
    case'U':return _towords(Sum.GetZ()) + " ���. " + _towords(Sum.GetQ()) + " ����";
    }
}

std::string Account::_towords(int numb) {
    int osn[11] = { 0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
    std::string basis[11][10] = {
        { "","","","","","","","","","" },
        { "","����","���","���","������","����","�����","����","������","������" },
        { "","������","��������","��������","�����","���������","����������","���������","�����������","���������" },
        { "","���","������","������","���������","�������","��������","�������","���������","���������" },
        { "","����","���","���","������","����","�����","����","������","������" },
        { "","������","��������","��������","�����","���������","����������","���������","�����������","���������" },
        { "","���","������","������","���������","�������","��������","�������","���������","���������" },
        { "","����","���","���","������","����","�����","����","������","������" },
        { "","������","��������","��������","�����","���������","����������","���������","�����������","���������" },
        { "","���","������","������","���������","�������","��������","�������","���������","���������" },
        { "","����","���","��� ","������","����","�����","����","������","������" } };
    std::string termination[10][10] = {
        { "","","","�����","","","���������","","","����������" },
        { "","","","������","","","�������","","","��������" },
        { "","","","������","","","��������","","","���������" },
        { "","","","������","","","��������","","","���������" },
        { "","","","������","","","��������","","","���������" },
        { "","","","�����","","","���������","","","����������" },
        { "","","","�����","","","���������","","","����������" },
        { "","","","�����","","","���������","","","����������" },
        { "","","","�����","","","���������","","","����������" },
        { "","","","�����","","","���������","","","����������" } };
    std::string dec[10] = { "������","�����������","����������","����������","������������","����������","�����������","����������","������������","������������" };
    std::string result;
    if (!numb) {
        result = "����";
        return result;
    }
    int n1 = numb;
    int cnt = 0;
    while (numb) {
        numb /= 10;
        ++cnt;
    }
    int celoe = 0;
    while (n1) {
        if (!((cnt + 1) % 3)) {
            if ((n1 / osn[cnt]) == 1) {
                n1 %= osn[cnt];
                --cnt;
                celoe = n1 / osn[cnt];
                n1 %= osn[cnt];
                result += dec[celoe];
                --cnt;
                if (!(cnt % 3))
                    result += " " + termination[0][cnt] + " ";
            }
            if (!cnt) break;
        }
        celoe = n1 / osn[cnt];
        n1 %= osn[cnt];
        result += basis[cnt][celoe] + " ";
        --cnt;
        if (!(cnt % 3))
            result += termination[celoe][cnt] + " ";
    }
    for (int i = 0; i < result.length(); i++) {
        if (result[i] == ' ' && result[i + 1] == ' ') {
            result.erase(i, 1);
            i--;
        }
    }
    while (result[result.length() - 1] == ' ') {
        result.erase(result.length() - 1);
    }
    return result;
}
