/** ��ü�������α׷��� HW#4
*	���ϸ�: sungjuk4.cpp
*	�а�: ����Ʈ�����а�
*	�й�: 2021041018
*	�̸�: �忹��
*/

#include<iostream>
#include<cstring>
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
	Subject* Sub;		// ����
	int SubNum;
	float AveGPA;		// ������ ��� ����
};

inline void PrintMenu();											// �޴� ���
void InputData(Student* pSt, int StdNum);							// �л� �Ż� �� ���� ���� �Է�
inline void InputValue(char* str);									// char�� ������ �Է¹޴� �Լ�
inline void InputValue(int& i);										// int�� ������ �Է¹޴� �Լ�
void CalcGPA(Subject& Sub);											// ������ ���� ���
float CalcAveGPA(Subject* Sub, int SubNum);							// ���� �л��� ��� ���� ���
void PrintAllStdList(Student* pSt, int StdNum);						// ��ü �л� ��� ���
void PrintAllData(const Student* pSt, int StdNum);					// ��ü �л� �Ż�/���� ���� ���
void PrintOneData(const Student& rSt);								// ���� �л� �Ż�/���� ���� ���
Student* StdSearch(Student* pSt, int StdNum); 						// �л� �̸� �˻� �� �ش� �л� ���� �ִ� �� �ּ� ����
void ModifyStdInfo(Student* pSt);									// �л� ���� �����ϴ� �Լ�


int main() {

	int menunum;													// �޴� �������� �����ϴ� ����
	int check = 0;													// 1 �����ߴ��� üũ�ϴ� ����
	int StdNum;														// �л� �� �����ϴ� ����
	Student* Stu;

	do {
		/* �޴� ��� �� ���� */
		PrintMenu();
		InputValue(menunum);
		cout << "\n";

		switch (menunum) {
		case 1:	/* �л� ���� �Է� �� ���� ��� */
			check = 1;												// 1 ����� ���� �� ����
			cout << "������ �Է¹��� �л� ���� �Է�: ";				    // �л� �� �Է�
			InputValue(StdNum);
			cout << "\n";
			Stu = new Student[StdNum];								// �л� ����ŭ ���� ����ü �Ҵ�
			InputData(Stu, StdNum);									// �Ż� �� ���� ���� �Է�
			break;
		case 2: /* ��ü �л� ���� ���� */
			if (check == 1)											// 1 ���� �����ߴ��� üũ
				PrintAllData(Stu, StdNum);							// ��ü �л��� �Ż�/���� ���� ���
			else
				cout << "1������ ������ �ּ���.\n\n";
			break;
		case 3: /* �л� �̸� �˻� */
			if (check == 1) {										// 1 ���� �����ߴ��� üũ
				Student* SearchStd;
				SearchStd = StdSearch(Stu, StdNum);					// �л� �̸� �Է�(���� �� SearchStd = NULL)
				if (SearchStd != NULL)								// SearchStd�� �л� �̸��� ����� �Էµƴٸ�
					PrintOneData(*SearchStd);						// ���� �л��� ���� ���
			}
			else
				cout << "1������ ������ �ּ���.\n\n";
			break;
		case 4: /* ��ü �л� ��� ���� */
			if (check == 1)				   							// 1 ���� �����ߴ��� üũ
				PrintAllStdList(Stu, StdNum);						// ��ü �л� ��� ���
			else
				cout << "1������ ������ �ּ���.\n\n";
			break;
		case 5: /* �л� ���� ���� */
			if (check == 1) {			   							// 1 ���� �����ߴ��� üũ
				Student* temp = StdSearch(Stu, StdNum);				// �л� �̸��� �˻��� ��� �ش� �л��� �����Ѵٸ�
				if (temp != NULL)
					ModifyStdInfo(temp);							// �л� ���� �����ϴ� �Լ� ȣ��
			}
			else
				cout << "1������ ������ �ּ���.\n\n";
			break;
		case 6: /* ���α׷� ���� */
			cout << "���α׷��� �����մϴ�.\n\n";
			break;
		default: /* �߸��� Ŀ�ǵ� �Է� */
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���.\n\n";
		}
	} while (menunum != 6);											// 6 ������ ���� ��

	delete[] Stu->Sub;
	Stu->Sub = NULL;
	delete[] Stu;
	Stu = NULL;

	return 0;

}


void PrintMenu() {
	/* �޴� ��� */
	cout << "===== �޴� =====\n"
		"1. �л� ���� �Է�\n"
		"2. ��ü �л� ���� ����\n"
		"3. �л� �̸� �˻�\n"
		"4. ��ü �л� ��� ����\n"
		"5. �л� ���� ����\n"
		"6. ���α׷� ����\n\n"
		"���ϴ� ����� �Է��ϼ��� : ";
}


void InputData(Student* pSt, int StdNum) {
	/* ��ü �л� ���� �Է� */
	for (int i = 0; i < StdNum; i++) {
		cout << "* " << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : ";
		InputValue(pSt[i].StdName);
		cout << "�й� : ";
		InputValue(pSt[i].Hakbun);
		cout << "\n\n";
		cout << "������ ���� ���� �Է�: ";
		InputValue(pSt[i].SubNum);
		(pSt + i)->Sub = new Subject[pSt[i].SubNum];
		cout << "\n* ������ ������ �� �������, ��������, �������� �Է��ϼ���.\n";
		for (int j = 0; j < pSt[i].SubNum; j++) {
			cout << "������� : ";
			InputValue(pSt[i].Sub[j].SubName);
			cout << "���������� : ";
			InputValue(pSt[i].Sub[j].Hakjum);
			cout << "������<A+ ~ F> : ";
			InputValue(pSt[i].Sub[j].Grade);
			cout << "\n";
			CalcGPA(pSt[i].Sub[j]);									// ������ ���� ��� �Լ� ȣ��
		}
		pSt[i].AveGPA = CalcAveGPA(pSt[i].Sub, pSt[i].SubNum); 		// ��� ���� ��� �Լ� ȣ��
		cout << "\n\n\n";
	}
}

void InputValue(char* str) {
	cin >> str;
}

void InputValue(int& i) {
	cin >> i;
}

void CalcGPA(Subject& Sub) {
	/* ������ ���� ��� */
	switch (Sub.Grade[0]) {											// ���ڿ��� ù ��° ���� �������� �⺻���� �ο�
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
	if (Sub.Grade[1] == '+') {										// ���ڿ��� �� ��° ���ڰ� +�� ��� 0.5�� �߰� 
		Sub.GPA += 0.5;
	}
	Sub.GPA *= Sub.Hakjum; 											// ������ ���� ���� ���(=��޺� ���� * ����)
}

float CalcAveGPA(Subject* Sub, int SubNum) {
	/* ������ ��� ���� ��� */
	float GPAtot = 0;												// ������ ���� �����ϴ� ����
	for (int i = 0; i < SubNum; i++) {								// for���� ���� �� ������ ������ �� ���
		GPAtot += Sub[i].GPA;
	}
	return GPAtot / (float)SubNum;									// ��� ���� ��� (=�� ������ ������ �� / �� �����)
}

void PrintAllStdList(Student* pSt, int StdNum) {
	/* ��ü �л� ��� ��� */
	cout << "=================================\n";
	cout.width(10);
	cout << "�й�";
	cout.width(10);
	cout << "�̸�" << "\n";
	for (int i = 0; i < StdNum; i++) {
		cout.width(10);
		cout << pSt[i].Hakbun;
		cout.width(10);
		cout << pSt[i].StdName;
		cout << "\n";
	}
	cout << "=================================\n\n\n";
}

void PrintAllData(const Student* pSt, int StdNum) {
	/* ��ü �л� ���� ��� */
	cout.width(35);
	cout << "��ü �л� ���� ����\n";
	cout << "=================================================\n";
	for (int i = 0; i < StdNum; i++)
		PrintOneData(pSt[i]);										// ���� �л� ���� ��� �Լ��� ȣ��
}

void PrintOneData(const Student& rSt) {
	/* ���� �л� ���� ��� */
	cout << "�̸� : " << rSt.StdName << "	�й� : " << rSt.Hakbun << "\n";
	cout << "=================================================\n";
	cout.width(15);	cout << "�����";
	cout.width(10); cout << "��������";
	cout.width(10);	cout << "������";
	cout.width(10);	cout << "��������" << "\n";
	cout << "=================================================\n";
	for (int i = 0; i < rSt.SubNum; i++)
	{
		cout.width(15);	cout << rSt.Sub[i].SubName;
		cout.width(10);	cout << rSt.Sub[i].Hakjum;
		cout.width(10); cout << rSt.Sub[i].Grade;
		cout.width(10); cout.precision(2); cout << fixed; cout << rSt.Sub[i].GPA << "\n";
	}
	cout << "=================================================\n";
	cout.width(37);	cout << "�������";
	cout.width(8); cout.precision(2); cout << fixed; cout << rSt.AveGPA << "\n\n\n";
}

Student* StdSearch(Student* pSt, int StdNum) {
	/* Ư�� �л� ���� �˻� */
	cout << "�˻��� �л� �̸�: ";
	char SearchName[30];
	cin >> SearchName;
	cout << "\n";
	for (int i = 0; i < StdNum; i++) {
		if (!strcmp(SearchName, pSt[i].StdName))					// �˻��� �̸��� ����� �̸� ���ڿ� ��(������ 0)
			return &pSt[i];											// ã���� �ش� �л� ������ ����� �� ���� �ּ� ����
	}
	cout << "�˻��� �л��� �����Ͱ� �������� �ʽ��ϴ�.\n\n\n";				// ������ ���Ƶ� ������ �ش� �޽��� ��� �� NULL ����
	return NULL;
}

void ModifyStdInfo(Student* pSt) {
	/* Ư�� �л� ���� ���� */
	cout << "* <" << pSt->StdName << ", " << pSt->Hakbun << ">�� ������ �����ϼ���\n";
	cout << "�̸�: ";
	InputValue(pSt->StdName);
	cout << "�й�: ";
	InputValue(pSt->Hakbun);
	cout << "\n\n\n";
}
