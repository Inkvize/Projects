#include <string.h>
#include <clocale>
#include <ctime>

#include <iostream>
#include <fstream>

struct Node {//��������� ������(l-����� �����, r-������)
    char info;//������(���� �������� ������)
    Node *l, *r;
};

Node *tr = NULL;//������������� �����

int CountTree(Node *&tree) {//������� ��������� � ������
    if (tree != NULL) {
        if (tree->l == NULL && tree->r == NULL) {
            return 1;
        } else {
            return CountTree(tree->l) + CountTree(tree->r) + 1;//+1, �.�. ���� ��������� ��� ��� �������
        }
    }
    return 0;
}

void Add_Node(Node **q, char a) {//���������� ������
    if (*q == NULL) {
        *q = new Node;
        (*q)->r = (*q)->l = NULL;
        (*q)->info = a;
    } else {
        if (a > (*q)->info) {//������� ���������� ��� ���������� �������������� ������
            Add_Node(&((*q)->r), a);
        } else {
            Add_Node(&((*q)->l), a);
        }
    }
}

void ShowNode(Node *&tree) {//����� ������ �������������� � �������
    if (tree != NULL) {
        ShowNode(tree->l);
        std::cout << tree->info;
        ShowNode(tree->r);
    }
}

void DelNode(Node *&tree) {//�������� ������ �� ������
    if (tree != NULL) {
        DelNode(tree->l);
        DelNode(tree->r);
        delete tree;
        tree = NULL;
    }
}

Node *DelElem(Node **root) {//�������� �������� ������
    if ((*root)->l == NULL && (*root)->r == NULL) {//���� ��� ������ �� ������, �� �����
        delete *root;
        *root = NULL;
        return *root;
    } else {
        if ((*root)->l == NULL) {//���� ���� ���-�� ������
            Node *res = (*root)->r;
            (*root)->l = NULL;
            (*root)->r = NULL;
            delete *root;
            return res;
        }
        if ((*root)->r == NULL) {//���� ���� ���-�� �����
            Node *res = (*root)->l;
            (*root)->l = NULL;
            (*root)->r = NULL;
            delete *root;
            return res;
        } else {//���� � ������ � ����� ���-�� ����, ���� ��� ����� �������� ������...
            Node *c = (*root)->l;
            Node *p = (*root);
            while ((c->r) != NULL) {
                p = c;
                c = c->r;
            }
            if (p != *root) {
                p->r = c->l;
                c->l = NULL;
            } else {
                p->l = c->l;
                c->l = NULL;
            }
            (*root)->info = c->info;
            delete c;
            return *root;
        }
    }
}

/*void DelNodeCheck(Node **Tree, char &c, bool &key) {//�������� �������� � ������, key ����� ��� �������� �����������
    if (*Tree != NULL) {
        if (c > (*Tree)->info) {
            DelNodeCheck(&((*Tree)->r), c, key);
        }
        if (c < (*Tree)->info) {
            DelNodeCheck(&((*Tree)->l), c, key);
        }
        if ((*Tree)->info == c) {
            key = true;
            *Tree = (DelElem(*Tree));
        }
    }
}

void DelRepiats(Node **Tree, bool &key) {//������� �������� �������� ��������
    if (*Tree != NULL) {
        key = false;
        DelNodeCheck(&((*Tree)->l), (*Tree)->info, key);
        if (key) {
            DelRepiats(&(*Tree), key);
        }
        DelRepiats(&((*Tree)->l), key);
        DelRepiats(&((*Tree)->r), key);
    }
}*/

void DelAllElem(Node **tree, char e) {//�������� ���� ��������� ������ e
    if (*tree != NULL) {
        while (*tree && e == (*tree)->info) {
            *tree = DelElem(tree);
        }
        if (*tree != NULL) {
            if (e > (*tree)->info) {
                DelAllElem(&((*tree)->r), e);
            } else {
                DelAllElem(&((*tree)->l), e);
            }
        }
    }
}

void DelRepiatsTree(Node **tree) {
    if (*tree != NULL) {
        DelAllElem(&((*tree)->l), (*tree)->info);//�������� ������ ������� ����� ���� ������ �����
        if (*tree) {
            DelRepiatsTree(&((*tree)->l));
        }
        if (*tree) {
            DelRepiatsTree(&((*tree)->r));
        }
    }
}

void BoredTreatment(
        char *a) {//�������� �������� �������� �� ������ ��������(���������� ��� ��������� �������� ��������� ��� ������ � ������
    int size = int(strlen(a));
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(a + i) == *(a + j)) {
                for (int p = j; p < size; p++) {
                    *(a + p) = *(a + p + 1);
                }
                size--;
                j--;
            }
        }
    }
    *(a + size) = '\0';
}

void SortStrok(char *a) {//���������� ������(���������� ��� ����������� ������ ������)
    char tmp;
    for (int i = 1, z; i < strlen(a); i++) {
        tmp = *(a + i);
        z = i - 1;
        while (z >= 0 && *(a + z) > tmp) {
            *(a + z + 1) = *(a + z);
            z--;
        }
        *(a + z + 1) = tmp;
    }
}

int main() {
    char strok[150001];
    FILE *f = fopen("open.txt", "r+");
    int i = 0;
    while ((strok[i] = getc(f)) != EOF && i < 150001) {
        i++;
    }
    strok[i - 1] = '\0';
    long t, t1, t2;
    std::cout << "Inputed strok out file\n";
    std::cout << strok << std::endl;
    t1 = clock();
    for (int item = 0; item < strlen(strok); item++) {
        Add_Node(&tr, *(strok + item));
    }
    t2 = clock();
    std::cout << "Build tree " << std::endl;
    ShowNode(tr);
    std::cout << std::endl;
    std::cout << "Count elem in tree " << CountTree(tr) << std::endl;
    t = clock();
    DelRepiatsTree(&tr);
    std::cout << "Runtime(Binary Tree): " << (clock() - t) / 1000.0 << " s"
              << std::endl;//����� ������� ��������� ������
    std::cout << "For build tree: " << (t2 - t1) / 1000.0 << " s" << std::endl;
    std::cout << "Tree not repiats(" << CountTree(tr) << ")" << std::endl;
    ShowNode(tr);
    std::cout << std::endl;
    t = clock();
    BoredTreatment(strok);
    SortStrok(strok);
    std::cout << "Runtime(straight): " << (clock() - t) / 1000.0 << " s" << std::endl;//����� ������� ��� ������
    printf("%s\n", strok);
    DelNode(tr);
    return 0;
}

