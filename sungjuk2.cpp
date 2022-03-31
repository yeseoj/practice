/** ��ü�������α׷��� HW#3
*	���ϸ�: sungjuk2.cpp
*	�а�: ����Ʈ�����а�
*	�й�: 2021041018
*	�̸�: �忹��
*/

#include<iostream>
#include<string.h>
#define STDNUM 2		// ���� �Է��� �л� ��
using namespace std;


struct Subject {		// ���� ����
	char SubName[30];	// �����̸�
	int Hakjum;			// ��������
	char Grade[10];		// ������
	float GPA;			// ��������
};
struct Student {		// �л� ����
	char StdName[30];	// �л��̸�
	int Hakbun;			// �й�
	Subject Sub[3];		// ����
	float AveGPA;		// ������ ��� ����
};

void PrintMenu();							// �޴� ���
void EnterStdInfo(Student& StIn);			// �л� ���� �Է�
void EnterSubInfo(Subject& SbIn);			// ���� ���� �Է�
void CalcGPA(Subject& Sub);					// ������ ���� ���
float CalcAveGPA(Subject* Sub);				// ���� �л��� ��� ���� ���
void PrintAllData(const Student* pSt);		// ��ü �л� �Ż�/���� ���� ���
void PrintOneData(const Student& rSt);		// ���� �л� �Ż�/���� ���� ���
Student* StdSearch(Student* pSt); 			// �л� �̸� �˻� �� �ش� �л� ���� �ִ� �� �ּ� ����


int main() {

	int menunum;												// �޴� �������� �����ϴ� ����
	int check = 0;												// 1 �����ߴ��� üũ�ϴ� ����
	Student Stu[STDNUM];

	do {

		/* �޴� ��� �� ���� */
		PrintMenu();
		cin >> menunum;
		cout << "\n";

		if (menunum == 1) {
			/* �л� ���� �Է� �� ���� ��� */
			check = 1;											// 1 ����� ���� �� ����
			for (int i = 0; i < STDNUM; i++) {
				cout << "* " << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
				EnterStdInfo(Stu[i]);							// �л� ���� �Է�
				cout << "\n\n\n";
				cout << "* ������ ���� 3���� �� �������, ��������, �������� �Է��ϼ���.\n";
				for (int j = 0; j < 3; j++) {
					EnterSubInfo(Stu[i].Sub[j]);				// ���� ���� �Է�
					CalcGPA(Stu[i].Sub[j]);						// ������ ���� ���
					Stu[i].AveGPA = CalcAveGPA(Stu[i].Sub);		// ��� ���� ���
				}
				cout << "\n\n\n";
			}
		}
		else if (menunum == 2) {
			/* ��ü �л� ���� ���� */
			if (check == 1)										// 1 ���� �����ߴ��� üũ
				PrintAllData(Stu);								// ��ü �л��� ���� ���
			else
				cout << "1������ ������ �ּ���.\n\n";
		}
		else if (menunum == 3) {
			/* �л� �̸� �˻� */
			if (check == 1) {									// 1 ���� �����ߴ��� üũ
				Student* SearchStd;
				SearchStd = StdSearch(Stu);						// �л� �̸� �Է�(���� �� SearchStd = NULL)
				if (SearchStd != NULL)							// SearchStd�� �л� �̸��� ����� �Էµƴٸ�
					PrintOneData(*SearchStd);					// ���� �л��� ���� ���
			}
			else
				cout << "1������ ������ �ּ���.\n\n";
		}
	} while (menunum != 4);										// 4 ���� ������ �ݺ�(4 ������ ���� ��)

	/* ���α׷� ���� */
	cout << "���α׷��� �����մϴ�." << "\n";

	return 0;

}


void PrintMenu() {
	/* �޴� ��� */
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n2. ��ü �л� ���� ����\n3. �л� �̸� �˻�\n4. ���α׷� ����\n\n";
	cout << "���ϴ� ����� �Է��ϼ��� : ";
}

void EnterStdInfo(Student& StIn) {
	/* �л� ���� �Է� */
	cout << "�̸� : ";
	cin >> StIn.StdName;
	cout << "�й� : ";
	cin >> StIn.Hakbun;
}

void EnterSubInfo(Subject& SbIn) {
	/* ���� ���� �Է� */
	cout << "������� : ";
	cin >> SbIn.SubName;
	cout << "���������� : ";
	cin >> SbIn.Hakjum;
	cout << "������<A+ ~ F> : ";
	cin >> SbIn.Grade;
	cout << "\n";
}

void CalcGPA(Subject& Sub) {
	/* ������ ���� ��� */
	switch (Sub.Grade[0]) {									// ���ڿ��� ù ��° ���� �������� �⺻���� �ο�
	case 'A':
		Sub.GPA = 4.0; break;
	case 'B':
		Sub.GPA = 3.0; break;
	case 'C':
		Sub.GPA = 2.0; break;
	case 'D':
		Sub.GPA = 1.0; break;
	default:
		Sub.GPA = 0; break;
	}
	if (Sub.Grade[1] == '+') {								// ���ڿ��� �� ��° ���ڰ� +�� ��� 0.5�� �߰� 
		Sub.GPA += 0.5;
	}
	Sub.GPA *= Sub.Hakjum; 									// ������ ���� ���� ���(=��޺� ���� * ����)
}

float CalcAveGPA(Subject* Sub) {
	/* ������ ��� ���� ��� */
	float GPAtot = 0;										// ������ ���� �����ϴ� ����
	for (int i = 0; i < 3; i++) {							// for���� ���� �� ������ ������ �� ���
		GPAtot += Sub[i].GPA;
	}
	return GPAtot / 3.0f;									// ��� ���� ��� (=�� ������ ������ �� / �� �����)
}

void PrintAllData(const Student* pSt) {
	/* ��ü �л� ���� ��� */
	cout.width(35);
	cout << "��ü �л� ���� ����\n";
	cout << "=================================================\n";
	for (int i = 0; i < STDNUM; i++)
		PrintOneData(pSt[i]);								// ���� �л� ���� ��� �Լ��� ȣ��
}

void PrintOneData(const Student& rSt) {
	/* ���� �л� ���� ��� */
	cout << "�̸� : " << rSt.StdName << "	�й� : " << rSt.Hakbun << "\n";
	cout << "=================================================\n";
	cout << "	�����	    �������� ������ ��������\n";
	cout << "=================================================\n";
	for (int i = 0; i < 3; i++)
	{
		cout.width(15);
		cout << rSt.Sub[i].SubName;
		cout.width(10);
		cout << rSt.Sub[i].Hakjum;
		cout.width(10);
		cout << rSt.Sub[i].Grade;
		cout.width(10);
		cout.precision(2);
		cout << fixed;
		cout << rSt.Sub[i].GPA << "\n";
	}
	cout << "=================================================\n";
	cout.width(37);
	cout << "�������";
	cout.width(8);
	cout.precision(2);
	cout << fixed;
	cout << rSt.AveGPA << "\n\n\n";
}

Student* StdSearch(Student* pSt) {
	/* Ư�� �л� ���� �˻� */
	cout << "�˻��� �л� �̸�: ";
	char SearchName[30];
	cin >> SearchName;
	cout << "\n";
	for (int i = 0; i < STDNUM; i++) {
		if (!strcmp(SearchName, pSt[i].StdName))			// �˻��� �̸��� ����� �̸� ���ڿ� ��(������ 0)
			return &pSt[i];									// ã���� �ش� �л� ������ ����� �� ���� �ּ� ����
	}
	cout << "�˻��� �л��� �����Ͱ� �������� �ʽ��ϴ�.\n\n\n";		// ������ ���Ƶ� ������ �ش� �޽��� ��� �� NULL ����
	return NULL;
}