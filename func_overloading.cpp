/** ��ü�������α׷��� HW#5
 *  ���ϸ�: func_overloading.cpp (�Լ� �����ε� �����ϱ�)
 *  �а�: ����Ʈ�����а�
 *  �й�: 2021041018
 *  �̸�: �忹��
 *  ������: 2022-04-20
 */

#include<iostream>
#include<cstring>
using namespace std;

int GetMin(int, int);               // ���� �� �ּҰ��� ���ϴ� �Լ�
double GetMin(double, double);      // �Ǽ� �� �ּҰ��� ���ϴ� �Լ�
char* GetMin(char*, char*);         // ���ڿ� �� ���� ���ڿ��� ���ϴ� �Լ�
int GetMin(int*);                   // ������ �迭 �� �ּҰ��� ���ϴ� �Լ�

int main() {
    /* �� ���� �� */
    cout << "�ΰ��� ������ �Է��ϼ���: ";
    int A, B;
    cin >> A >> B;
    cout << "�ּҰ��� " << GetMin(A, B) << "�Դϴ�.\n";

    /* �� �Ǽ� �� */
    cout << "�ΰ��� �Ǽ��� �Է��ϼ���: ";
    double C, D;
    cin >> C >> D;
    cout << "�ּҰ��� ";
    cout << fixed;
    cout.precision(2);
    cout << GetMin(C, D) << "�Դϴ�.\n";

    /* �� ���ڿ� �� */
    cout << "�ΰ��� ���ڿ��� �Է��ϼ���: ";
    char str1[20];
    char str2[20];
    cin >> str1 >> str2;
    char* temp = GetMin(str1, str2);
    if (temp == NULL)
        cout << "���̰� �����ϴ�.\n";
    //�ٸ� �� ������� strlen()�� ����� �� ����
    //if (strlen(str1) == strlen(str2))
    //    cout << "���̰� �����ϴ�.\n";
    else cout << "�ּҰ��� " << temp << "�Դϴ�.\n";

    /* �迭�� ���� �� */
    cout << "�迭�� ����: ";
    int num[10];
    for (int i = 0; i < 10; i++) {
        cin >> num[i];
    }
    cout << "�ּҰ��� " << GetMin(num) << "�Դϴ�.\n";

    return 0;
}

/**
 * ���� ������ �̿��Ͽ� �� ���� �� return
 */
int GetMin(int x, int y) {
    return (x < y ? x : y);
}

/**
 * ���� ������ �̿��Ͽ� �� ���� �� return
 */
double GetMin(double x, double y) {
    return (x < y ? x : y);
}

/**
 * strcmp �̿��Ͽ� ���ϰ� �� ���ڿ��� ��ȯ(���� ��� NULL)
 * ���� ���� �� ���ڿ��� ���̰� ���� ���� ����� �ǵ� �ȵ�
 */
char* GetMin(char* x, char* y) {
    switch (strcmp(x, y)) {
    case -1: return x;
    case 1: return y;
    default: return NULL;
    }
}

/**
 * for�� �̿��Ͽ� �迭 �������� �ּҰ� ���ϰ� return
 */
int GetMin(int* num) {
    int min = num[0];
    for (int i = 1; i < 10; i++) {
        if (num[i] < min) min = num[i];
    }
    return min;
}