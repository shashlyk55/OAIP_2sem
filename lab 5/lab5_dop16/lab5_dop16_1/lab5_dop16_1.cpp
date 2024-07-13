#include<iostream>
#include<windows.h>
#include<string>
#define maxSize 20
using namespace std;

void menu();
void search();
void addNote();
void delNote();
void print();

enum Facuities {
	MATEM = 1, PHIS, ANGL
} faculty;

struct Exam_Date {
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 12;
};

struct list {
	int number;
	string surname;
	string exam;
	Exam_Date date;
};

int num = 0;
struct list list[maxSize];
struct list nothing;
bool flag = false;
char task;

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "������\n";
		cin >> task;
	}
	while (true) {
		switch (task) {
		case '1': addNote(); break;
		case '2': print(); break;
		case '3': delNote(); break;
		case '4': search(); break;
		case '5': exit(1); break;
		}
	}
}

void menu() {
	cout << "\n1 - �������� ������\n2 - ����� �� �����\n3 - �������� ������\n4 - ����� ������\n5 - �����\n";
}

int a;
void addNote() {
	cout << "���� ����������" << endl;
	cout << "�����: " << num + 1 << endl;
	list[num].number = num + 1;
	do {
		cout << "�������: ";
		getchar();
		getline(cin, list[num].surname);
		flag = false;
		for (int j = 0; list[num].surname[j] != '\0'; j++) {
			if ((list[num].surname[j] < '�' || list[num].surname[j] > '�') && (list[num].surname[j] > '�' || list[num].surname[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);


	

	cout << "�������(1-�����,2-������,3-����): ";
	int f;
	cin >> f;
	while (f < 1 || f > 4) {
		cout << "������\n";
		cin >> f;
	}
	switch (f) {
	case MATEM:
		list[num].exam = "����������";
		break;
	case PHIS:
		list[num].exam = "������";
		break;
	case ANGL:
		list[num].exam = "����������";
		break;
	}


	cout << "���� ��������: ";
	cout << "����: ";
	cin >> a;
	while (a < 0 || a>31) {
		cout << "������\n";
		cin >> a;
	}
	list[num].date.day = a;
	cout << "�����: ";
	cin >> a;
	while (a < 0 || a>12) {
		cout << "������\n";
		cin >> a;
	}
	list[num].date.month = a;
	cout << "���: ";
	cin >> a;
	while (a < 0 || a>9999) {
		cout << "������\n";
		cin >> a;
	}
	list[num].date.year = a;
	
	cout << endl;
	num++;
	system("cls");
	menu();
	cout << "��� ������? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "������\n";
		cin >> task;
	}
}

void delNote() {
	int d;
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ������ 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int del = (d - 1); del < num; del++) {
			list[del] = list[del + 1];
		}
		num -= 1;
	}
	if (d == 99) {
		for (int i = 0; i < maxSize; i++) {
			list[i] = nothing;
		}
	}
	cout << "������ ������� �� ������" << endl;
	menu();
	cout << "��� ������?" << endl;
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "������\n";
		cin >> task;
	}
}

void print() {
	
	cout << "����� ���� ���������" << endl;
	
		for (int j = 0; j < num; j++) {
			cout << "�������: " << list[j].surname << endl;
			cout << "�������� ��������: " << list[j].exam << endl << endl;			
			cout << "���� ��������: " << list[j].date.day << "." << list[j].date.month << "." << list[j].date.year << endl;
		}
	menu();
	cout << "��� ������? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "������\n";
		cin >> task;
	}
}

void search() {
	int data[3];
	bool found = false;
	cout << "������� ���� �������� ��� ������: ";
	cout << "���� ��������: ";
	cout << "����: ";
	cin >> data[0];
	while (data[0] < 0 || data[0]>31) {
		cout << "������\n";
		cin >> data[0];
	}
	cout << "�����: ";
	cin >> data[1];
	while (data[1] < 0 || data[1]>12) {
		cout << "������\n";
		cin >> data[1];
	}
	cout << "���: ";
	cin >> data[2];
	while (data[2] < 0 || data[2]>9999) {
		cout << "������\n";
		cin >> data[2];
	}
	for (int i = 0; i < num; i++) {
		if (list[i].date.day == data[0] && list[i].date.month == data[1] && list[i].date.year == data[2]) {
			found = true;
			cout << "\n�������: " << list[i].surname << endl;
			cout << "�������� ��������: " << list[i].exam << endl;
			cout << "���� ��������: " << list[i].date.day << "." << list[i].date.month << "." << list[i].date.year << endl;
		}
		found = false;
	}
	if (found) {
		cout << "\n������ �� �������";
	}
	menu();
	cout << "��� ������? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "������\n";
		cin >> task;
	}
}