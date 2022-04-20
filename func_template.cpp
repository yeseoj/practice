/** ��ü�������α׷��� HW#5
 *  ���ϸ�: func_template.cpp (�Լ� ���ø� �����ϱ�)
 *  �а�: ����Ʈ�����а�
 *  �й�: 2021041018
 *  �̸�: �忹��
 *  ������: 2022-04-20
 */

#include<iostream>
using namespace std;

void PrintMenu();                           /* �޴� ��� */
template <class T>
void sort(T* array, int size) {             /* �Է��� �迭 ���� */
    T temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i; j < size; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
template <class T>                          /* ���� ��� ��� */
void PrintSort(T* array, int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << "\n\n";
}

int main() {
    int menunum;

    do {
        PrintMenu();
        cin >> menunum;

        switch (menunum) {
        case 1: /* ���� ���� */
            cout << "5���� ������ �Է��ϼ���: ";
            int integer[5];
            for (int i = 0; i < 5; i++)
                cin >> integer[i];
            sort(integer, 5);
            PrintSort(integer, 5);
            break;
        case 2: /* �Ǽ� ���� */
            cout << "5���� �Ǽ��� �Է��ϼ���: ";
            double realnum[5];
            for (int i = 0; i < 5; i++)
                cin >> realnum[i];
            sort(realnum, 5);
            cout << fixed;
            cout.precision(2);
            PrintSort(realnum, 5);
            break;
        case 3: /* ���α׷� ���� */
            break;
        default: /* �߸��� ���� �Է� �� */
            cout << "\n�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���.\n\n";
        }
    } while (menunum != 3);

    return 0;
}

void PrintMenu() {
    cout << "1. ���� ����\n"
         << "2. �Ǽ� ����\n"
         << "3. ���α׷� ����\n"
         << "�޴� ���� : ";
}