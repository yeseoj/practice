/** 객체지향프로그래밍 HW#7
 *	파일명: class_vector.cpp (vector class 사용해보기)
 *	학과: 소프트웨어학과
 *	학번: 2021041018
 *	이름: 장예서
 *  안내사항: 실습 시간에 질문하였을 때 RemoveAll() 함수는 작성할 필요 없다는 답변을 들어 삭제하였습니다.
 *	수정일: 2022-05-06
 */


#include<vector>
#include<iostream>
#include<string>
using namespace std;

void CountWords(string);
void PrintWords();

struct WORD {
    string str;             // 각 단어의 내용
    int count;              // 각 단어의 사용 빈도
};

vector<WORD*> words;        // WORD 구조체 포인터를 저장하는 벡터 객체

int main() {
    cout << "문자열 입력. 종료: Ctrl+Z\n";
    string buffer;
    while (cin >> buffer)
        CountWords(buffer); // 단어 세기
    PrintWords();           // 입력 결과 출력

    return 0;
}

/* 단어 카운트 함수 */
void CountWords(string str) {
    /* 단어 검색 후 해당 단어가 발견되면 해당 단어 빈도수 1 증가 */
    for (int i = 0; i < words.size(); i++) {
        if (words[i]->str == str) {
            words[i]->count++;
            return;
        }
    }
    /* 해당 단어가 발견되지 않으면 단어 추가 후 빈도수 1로 설정 */
    WORD *word = new WORD;
    word->str = str;
    word->count = 1;
    words.push_back(word);
}

/* 단어 출력 함수 */
void PrintWords() {
    cout << "==========\n";
    for (int i = 0; i < words.size(); i++) {
        cout << words[i]->str << ": " << words[i]->count << endl;
    }
    cout << "==========\n";
}
