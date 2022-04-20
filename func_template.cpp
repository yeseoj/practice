/** 객체지향프로그래밍 HW#5
 *  파일명: func_template.cpp (함수 템플릿 이해하기)
 *  학과: 소프트웨어학과
 *  학번: 2021041018
 *  이름: 장예서
 *  수정일: 2022-04-20
 */

#include<iostream>
using namespace std;

void PrintMenu();                           /* 메뉴 출력 */
template <class T>
void sort(T* array, int size) {             /* 입력한 배열 정렬 */
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
template <class T>                          /* 정렬 결과 출력 */
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
        case 1: /* 정수 정렬 */
            cout << "5개의 정수를 입력하세요: ";
            int integer[5];
            for (int i = 0; i < 5; i++)
                cin >> integer[i];
            sort(integer, 5);
            PrintSort(integer, 5);
            break;
        case 2: /* 실수 정렬 */
            cout << "5개의 실수를 입력하세요: ";
            double realnum[5];
            for (int i = 0; i < 5; i++)
                cin >> realnum[i];
            sort(realnum, 5);
            cout << fixed;
            cout.precision(2);
            PrintSort(realnum, 5);
            break;
        case 3: /* 프로그램 종료 */
            break;
        default: /* 잘못된 숫자 입력 시 */
            cout << "\n잘못된 입력입니다. 다시 입력해 주세요.\n\n";
        }
    } while (menunum != 3);

    return 0;
}

void PrintMenu() {
    cout << "1. 정수 정렬\n"
         << "2. 실수 정렬\n"
         << "3. 프로그램 종료\n"
         << "메뉴 선택 : ";
}