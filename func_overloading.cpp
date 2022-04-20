/** 객체지향프로그래밍 HW#5
 *  파일명: func_overloading.cpp (함수 오버로딩 이해하기)
 *  학과: 소프트웨어학과
 *  학번: 2021041018
 *  이름: 장예서
 *  수정일: 2022-04-20
 */

#include<iostream>
#include<cstring>
using namespace std;

int GetMin(int, int);               // 정수 중 최소값을 구하는 함수
double GetMin(double, double);      // 실수 중 최소값을 구하는 함수
char* GetMin(char*, char*);         // 문자열 중 작은 문자열을 구하는 함수
int GetMin(int*);                   // 정수형 배열 중 최소값을 구하는 함수

int main() {
    /* 두 정수 비교 */
    cout << "두개의 정수를 입력하세요: ";
    int A, B;
    cin >> A >> B;
    cout << "최소값은 " << GetMin(A, B) << "입니다.\n";

    /* 두 실수 비교 */
    cout << "두개의 실수를 입력하세요: ";
    double C, D;
    cin >> C >> D;
    cout << "최소값은 ";
    cout << fixed;
    cout.precision(2);
    cout << GetMin(C, D) << "입니다.\n";

    /* 두 문자열 비교 */
    cout << "두개의 문자열을 입력하세요: ";
    char str1[20];
    char str2[20];
    cin >> str1 >> str2;
    char* temp = GetMin(str1, str2);
    if (temp == NULL)
        cout << "길이가 같습니다.\n";
    //다른 비교 방법으로 strlen()을 사용할 수 있음
    //if (strlen(str1) == strlen(str2))
    //    cout << "길이가 같습니다.\n";
    else cout << "최소값은 " << temp << "입니다.\n";

    /* 배열의 원소 비교 */
    cout << "배열의 원소: ";
    int num[10];
    for (int i = 0; i < 10; i++) {
        cin >> num[i];
    }
    cout << "최소값은 " << GetMin(num) << "입니다.\n";

    return 0;
}

/**
 * 삼항 연산자 이용하여 더 작은 값 return
 */
int GetMin(int x, int y) {
    return (x < y ? x : y);
}

/**
 * 삼항 연산자 이용하여 더 작은 값 return
 */
double GetMin(double x, double y) {
    return (x < y ? x : y);
}

/**
 * strcmp 이용하여 비교하고 각 문자열을 반환(같은 경우 NULL)
 * 같지 않은 두 문자열이 길이가 같은 경우는 제대로 판독 안됨
 */
char* GetMin(char* x, char* y) {
    switch (strcmp(x, y)) {
    case -1: return x;
    case 1: return y;
    default: return NULL;
    }
}

/**
 * for문 이용하여 배열 내에서의 최소값 구하고 return
 */
int GetMin(int* num) {
    int min = num[0];
    for (int i = 1; i < 10; i++) {
        if (num[i] < min) min = num[i];
    }
    return min;
}