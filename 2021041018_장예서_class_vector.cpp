/** ��ü�������α׷��� HW#7
 *	���ϸ�: class_vector.cpp (vector class ����غ���)
 *	�а�: ����Ʈ�����а�
 *	�й�: 2021041018
 *	�̸�: �忹��
 *  �ȳ�����: �ǽ� �ð��� �����Ͽ��� �� RemoveAll() �Լ��� �ۼ��� �ʿ� ���ٴ� �亯�� ��� �����Ͽ����ϴ�.
 *	������: 2022-05-06
 */


#include<vector>
#include<iostream>
#include<string>
using namespace std;

void CountWords(string);
void PrintWords();

struct WORD {
    string str;             // �� �ܾ��� ����
    int count;              // �� �ܾ��� ��� ��
};

vector<WORD*> words;        // WORD ����ü �����͸� �����ϴ� ���� ��ü

int main() {
    cout << "���ڿ� �Է�. ����: Ctrl+Z\n";
    string buffer;
    while (cin >> buffer)
        CountWords(buffer); // �ܾ� ����
    PrintWords();           // �Է� ��� ���

    return 0;
}

/* �ܾ� ī��Ʈ �Լ� */
void CountWords(string str) {
    /* �ܾ� �˻� �� �ش� �ܾ �߰ߵǸ� �ش� �ܾ� �󵵼� 1 ���� */
    for (int i = 0; i < words.size(); i++) {
        if (words[i]->str == str) {
            words[i]->count++;
            return;
        }
    }
    /* �ش� �ܾ �߰ߵ��� ������ �ܾ� �߰� �� �󵵼� 1�� ���� */
    WORD *word = new WORD;
    word->str = str;
    word->count = 1;
    words.push_back(word);
}

/* �ܾ� ��� �Լ� */
void PrintWords() {
    cout << "==========\n";
    for (int i = 0; i < words.size(); i++) {
        cout << words[i]->str << ": " << words[i]->count << endl;
    }
    cout << "==========\n";
}
