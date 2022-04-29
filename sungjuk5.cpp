/** ��ü�������α׷��� HW#6
 *	���ϸ�: sungjuk5.cpp
 *	�а�: ����Ʈ�����а�
 *	�й�: 2021041018
 *	�̸�: �忹��
 *	�ȳ�����: ModifyStdInfo() �Լ����� StdSearch() �Լ��� ȣ���ϱ� ���� ���Ƿ� StdNum ���ڸ� �߰��Ͽ����ϴ�.
 *	������: 2022-04-29
 */

#include<iostream>
#include<cstring>
#include<string>
using namespace std;


struct Subject {		// ���� ����
	string SubName;		// �����̸�
	int Hakjum;			// ��������
	string Grade;		// ������
	float GPA;			// ��������
};
struct Student {		// �л� ����
	string StdName;		// �л��̸�
	int Hakbun;			// �й�
	Subject* Sub;		// ����
	int SubNum;			// ���� ��
	float AveGPA;		// ������ ��� ����
};

inline void PrintMenu();											// �޴� ���
inline void InputValue(string& str);								// string�� ������ �Է¹޴� �Լ�
inline void InputValue(int& i);										// int�� ������ �Է¹޴� �Լ�
void InputData(Student* pSt, int StdNum);							// �л� �Ż� �� ���� ���� �Է�
void CalcGPA(Subject& Sub);											// ������ ���� ���
float CalcAveGPA(Subject* Sub, int SubNum);							// ���� �л��� ��� ���� ���
void PrintAllStdList(Student* pSt, int StdNum);						// ��ü �л� ��� ���
void PrintAllData(const Student* pSt, int StdNum);					// ��ü �л� �Ż�/���� ���� ���
void PrintOneData(const Student& rSt);								// ���� �л� �Ż�/���� ���� ���
Student* StdSearch(Student* pSt, int StdNum); 						// �л��� �˻� �� �ش� �л� ���� �ּ� ����
Subject* SubSearch(const Student* pSt);								// ����� �˻� �� �ش� ���� ���� �ּ� ����
void ModifyStdInfo(Student* pSt, int StdNum);						// �л� ���� �����ϴ� �Լ�



int main() {

	int menunum;													// �޴� �������� �����ϴ� ����
	int StdNum;														// �л� �� �����ϴ� ����
	Student* Stu = NULL;

	do {
		/* �޴� ��� �� ���� */
		PrintMenu();
		InputValue(menunum);
		cout << "\n";

		switch (menunum) {
		case 1:	/* �л� ���� �Է� �� ���� ��� */
			cout << "������ �Է¹��� �л� ���� �Է�: ";
			InputValue(StdNum);										// �л� �� �Է�
			cout << "\n";
			Stu = new Student[StdNum];								// �л� ����ŭ ���� ����ü �Ҵ�
			InputData(Stu, StdNum);									// �Ż� �� ���� ���� �Է�
			break;
		case 2: /* ��ü �л� ���� ���� */
			if (Stu != NULL)										// 1 ���� �����ߴ��� üũ
				PrintAllData(Stu, StdNum);							// ��ü �л��� �Ż�/���� ���� ���
			else
				cout << "1������ ������ �ּ���.\n\n";
			break;
		case 3: /* �л� �̸� �˻� */
			if (Stu != NULL) {										// 1 ���� �����ߴ��� üũ
				Student* SearchStd = StdSearch(Stu, StdNum);		// �л� �̸� �Է�(���� �� SearchStd = NULL)
				if (SearchStd != NULL)								// SearchStd�� �л� �̸��� ����� �Էµƴٸ�
					PrintOneData(*SearchStd);						// ���� �л��� ���� ���
			}
			else
				cout << "1������ ������ �ּ���.\n\n";
			break;
		case 4: /* ��ü �л� ��� ���� */
			if (Stu != NULL)										// 1 ���� �����ߴ��� üũ
				PrintAllStdList(Stu, StdNum);						// ��ü �л� ��� ���
			else
				cout << "1������ ������ �ּ���.\n\n";
			break;
		case 5: /* �л�/���� ���� ���� */
			if (Stu != NULL)										// 1 ���� �����ߴ��� üũ
				ModifyStdInfo(Stu, StdNum);							// �л� ���� ���� �Լ� ȣ��
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

/* �޴� ��� */
void PrintMenu() {
	cout << "===== �޴� =====\n"
		"1. �л� ���� �Է�\n"
		"2. ��ü �л� ���� ����\n"
		"3. �л� �̸� �˻�\n"
		"4. ��ü �л� ��� ����\n"
		"5. �л� ���� ����\n"
		"6. ���α׷� ����\n\n"
		"���ϴ� ����� �Է��ϼ��� : ";
}

/* ���ڿ� �� �Է� */
void InputValue(string& str) {
	getline(cin, str);
}

/* ���� �� �Է� */
void InputValue(int& i) {
	cin >> i;
	cin.ignore();
}

/* ��ü �л� ���� �Է� */
void InputData(Student* pSt, int StdNum) {
	for (int i = 0; i < StdNum; i++) {
		cout << "* " << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : ";
		InputValue(pSt[i].StdName);
		cout << "�й� : ";
		InputValue(pSt[i].Hakbun);
		cout << "\n\n";
		cout << "������ ���� ���� �Է�: ";
		InputValue(pSt[i].SubNum);
		pSt[i].Sub = new Subject[pSt[i].SubNum];
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

/* ������ ���� ��� */
void CalcGPA(Subject& Sub) {
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

/* ������ ��� ���� ��� */
float CalcAveGPA(Subject* Sub, int SubNum) {
	float GPAtot = 0;												// ������ ���� �����ϴ� ����
	for (int i = 0; i < SubNum; i++) {								// for���� ���� �� ������ ������ �� ���
		GPAtot += Sub[i].GPA;
	}
	return GPAtot / (float)SubNum;									// ��� ���� ��� (=�� ������ ������ �� / �� �����)
}

/* ��ü �л� ��� ��� */
void PrintAllStdList(Student* pSt, int StdNum) {
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

/* ��ü �л� ���� ��� */
void PrintAllData(const Student* pSt, int StdNum) {
	cout.width(38);
	cout << "��ü �л� ���� ����\n";
	cout << "======================================================\n";
	for (int i = 0; i < StdNum; i++)
		PrintOneData(pSt[i]);										// ���� �л� ���� ��� �Լ��� ȣ��
}

/* ���� �л� ���� ��� */
void PrintOneData(const Student& rSt) {
	cout << "�̸� : " << rSt.StdName << "	�й� : " << rSt.Hakbun;
	cout << "\n======================================================\n";
	cout.width(20);	cout << "�����";
	cout.width(10); cout << "��������";
	cout.width(10);	cout << "������";
	cout.width(10);	cout << "��������";
	cout << "\n======================================================\n";
	for (int i = 0; i < rSt.SubNum; i++)
	{
		cout.width(20);	cout << rSt.Sub[i].SubName;
		cout.width(10);	cout << rSt.Sub[i].Hakjum;
		cout.width(10); cout << rSt.Sub[i].Grade;
		cout.width(10); cout.precision(2); cout << fixed; cout << rSt.Sub[i].GPA << "\n";
	}
	cout << "======================================================\n";
	cout.width(40);	cout << "�������";
	cout.width(10); cout.precision(2); cout << fixed; cout << rSt.AveGPA << "\n\n\n";
}

/* Ư�� �л� ���� �˻� */
Student* StdSearch(Student* pSt, int StdNum) {
	cout << "�˻��� �л� �̸�: ";
	string SearchName;
	getline(cin, SearchName);
	cout << "\n";
	for (int i = 0; i < StdNum; i++) {
		if (SearchName == pSt[i].StdName)							// �˻��� �̸��� ����� �̸� ���ڿ� ��
			return &pSt[i];											// ã���� �ش� �л� ������ ����� �� �ּ� ����
	}
	cout << "�˻��� �л��� �����Ͱ� �������� �ʽ��ϴ�.\n\n\n";			// ������ ���Ƶ� ������ �ش� �޽��� ��� �� NULL ����
	return NULL;
}

/* Ư�� ���� ���� �˻� */
Subject* SubSearch(const Student* pSt) {
	cout << "\n�˻��� ���� �̸�: ";
	string SearchName;
	getline(cin, SearchName);
	cout << "\n";
	for (int i = 0; i < pSt->SubNum; i++) {
		if (SearchName == pSt->Sub[i].SubName)						// �˻��� �̸��� ����� �̸� ���ڿ� ��
			return &(pSt->Sub[i]);									// ã���� �ش� ���� ������ ����� �� �ּ� ����
	}
	cout << "�˻��� ������ �����Ͱ� �������� �ʽ��ϴ�.\n\n\n"; 			// ������ ���Ƶ� ������ �ش� �޽��� ��� �� NULL ����
	return NULL;
}

/* Ư�� �л�/���� ���� ���� */
void ModifyStdInfo(Student* pSt, int StdNum) {
	Student *Stdtemp = StdSearch(pSt, StdNum);
	if (Stdtemp != NULL) {											// �л� �̸��� �˻��� ��� �ش� �л��� �����Ѵٸ� ���� ����
		string Type;
		cout << "����(�л�����/��������): ";
		InputValue(Type);
		/* �л������� �Է��� ��� */
		if (Type == "�л�����") {
			cout << "\n* <" << Stdtemp->StdName << ", " << Stdtemp->Hakbun << ">�� ������ �����ϼ���\n";
			cout << "�̸�: ";
			InputValue(Stdtemp->StdName);
			cout << "�й�: ";
			InputValue(Stdtemp->Hakbun);
			cout << "\n\n\n";
		}
		/* ���������� �Է��� ��� */
		else if (Type == "��������") {
			Subject* Subtemp = SubSearch(Stdtemp);
			if (Subtemp != NULL) {
				cout << "\n* <" << Stdtemp->StdName << ", " << Stdtemp->Hakbun << "> �л��� �����ϴ� <" 
					 << Subtemp->SubName << ", ����: " << Subtemp->Hakjum << ", ���: " << Subtemp->Grade << "> ������ ������ �����ϼ���\n";
				cout << "������� : ";
				InputValue(Subtemp->SubName);
				cout << "���������� : ";
				InputValue(Subtemp->Hakjum);
				cout << "������<A+ ~ F> : ";
				InputValue(Subtemp->Grade);
				cout << "\n\n\n";
				/* ���� ����/��޿� ���� ������ ����� �Լ��� ȣ�� */
				CalcGPA(*Subtemp); 
				Stdtemp->AveGPA = CalcAveGPA(Stdtemp->Sub, Stdtemp->SubNum);
			}
		}
		/* �߸� �Է��� ��� */
		else cout << "�߸� �Է��ϼ̽��ϴ�.\n\n";
	}
}
