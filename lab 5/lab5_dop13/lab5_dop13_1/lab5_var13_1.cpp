#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>
#define maxSize 20
using namespace std;

bool flag = false;
char b, c, task;
int num = 0, a, f;

enum Facuities {
	FIT = 1, HTIT, PIM, TOV
} faculty;

struct Date {
	unsigned int day: 5;
	unsigned int month: 4;
	unsigned int year: 12;
};

struct list {
	string name;
	string capital;
	string otch;
	string spec;
	string fac;
	Date data;
	char group;
	int number;
	float county;
};
struct list notes[maxSize];
struct list nothing;
int size = 0;
// ������� ����
void Menu() {
	cout << "\n1-���������� ������\n";
	cout << "2-����� �������\n";
	cout << "3-����� �� �������� �����\n";
	cout << "4-�������� ������\n";
	cout << "5-�����\n";
	cout << "��� ����� ������? ";
}

void addNote();
void print();
void search();
void delNote();

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu();
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "������\n";
		cin >> task;
	}
	while (true) {
		switch (task) {
			cin >> task;
			while (task > '4' || task < '1') {
				cout << "������\n";
				cin >> task;
			}
		case '1':
			addNote();
			break;
		case '2':
			print();
			break;
		case '3':
			search();
			break;
		case '4':
			delNote();
			break;
		case '5':
			exit(1);
		}
	}
}

void delNote() {
	int d;
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ������ 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int del = (d - 1); del < num; del++) {
			notes[del] = notes[del + 1];
		}
		num -= 1;
	}
	if (d == 99) {
		for (int i = 0; i < maxSize; i++) {
			notes[i] = nothing;
		}
	}
	cout << "������ ������� �� ������" << endl;
	Menu();
	cout << "��� ������?" << endl;
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "������\n";
		cin >> task;
	}
}

void addNote() {
	cout << "���� ����������" << endl;
	cout << "�����: " << num + 1 << endl;
	notes[num].number = num + 1;
	cout << "���:\n";
	do {
		cout << "�������: ";
		getchar();
		getline(cin, notes[num].capital);
		flag = false;
		for (int j = 0; notes[num].capital[j] != '\0'; j++) {
			if ((notes[num].capital[j] < '�' || notes[num].capital[j] > '�') && (notes[num].capital[j] > '�' || notes[num].capital[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);

	do {
		cout << "���: ";
		getchar();
		getline(cin, notes[num].name);
		flag = false;
		for (int j = 0; notes[num].name[j] != '\0'; j++) {
			if ((notes[num].name[j] < '�' || notes[num].name[j] > '�') && (notes[num].name[j] > '�' || notes[num].name[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);

	do {
		cout << "��������: ";
		getchar();
		getline(cin, notes[num].otch);
		flag = false;
		for (int j = 0; notes[num].otch[j] != '\0'; j++) {
			if ((notes[num].otch[j] < '�' || notes[num].otch[j] > '�') && (notes[num].otch[j] > '�' || notes[num].otch[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);

	cout << "���� �����������(��������): ";
	cout << "����: ";
	cin >> a;
	notes[num].data.day = a;
	while (a < 0 || a>31) {
		cout << "������\n";
		cin >> a;
		notes[num].data.day = a;
	}
	cout << "�����: ";
	cin >> a;
	notes[num].data.month = a;
	while (a < 0 || a>12) {
		cout << "������\n";
		cin >> a;
		notes[num].data.month = a;
	}
	cout << "���: ";
	cin >> a;
	notes[num].data.year = a;
	while (a < 0 || notes[num].data.year>9999) {
		cout << "������\n";
		cin >> a;
		notes[num].data.year = a;
	}

	do {
		cout << "�������������: ";
		getchar();
		getline(cin, notes[num].spec);
		flag = false;
		for (int j = 0; notes[num].spec[j] != '\0'; j++) {
			if ((notes[num].spec[j] < '�' || notes[num].spec[j] > '�') && (notes[num].spec[j] > '�' || notes[num].spec[j] < '�') && notes[num].spec[j] != ' ') {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);

	cout << "������: ";
	cin >> notes[num].group;
	while (notes[num].group < '0' || notes[num].group>'9') {
		cout << "������\n";
		cin >> notes[num].group;
	}

		cout << "���������(1-���,2-����,3-���,4-���): ";
		cin >> f;
		while (f < 1 || f > 4) {
			cout << "������\n";
			cin >> f;
		}
		switch (f) {
		case FIT: 
			notes[num].fac = "���";
			break;
		case HTIT:
			notes[num].fac = "����";
			break;
		case PIM:
			notes[num].fac = "���";
			break;
		case TOV:
			notes[num].fac = "���";
			break;
		}

	cout << "������� ����: ";
	cin >> notes[num].county;
	while (notes[num].county < 0.0 || notes[num].county>10.0) {
		cout << "������\n";
		cin >> notes[num].county;
	}

	cout << endl;
	num++;
	system("cls");
	Menu();
	cout << "��� ������? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "������\n";
		cin >> task;
	}
}

void print() {

	cout << "����� ���� ���������" << endl;

	for (int j = 0; j < num; j++) {
		cout << "���: " << notes[j].capital << notes[j].name << notes[j].otch << endl;
		cout << "���� �����������: " << notes[j].data.day << notes[j].data.month << notes[j].data.year << endl;
		cout << "������: " << notes[j].group << endl;
		cout << "���������: " << notes[j].fac << endl;
		cout << "������� ����: " << notes[j].county << endl;
	}
	Menu();
	cout << "��� ������? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "������\n";
		cin >> task;
	}
}

void search() {
	float ball;
	bool found = false;
	cout << "������� ������� ���� ��� ������: ";
	cin >> ball;
	for (int j = 0; j < num; j++) {
		if (ball == notes[j].county) {
			found = true;
			cout << "���: " << notes[j].capital << notes[j].name << notes[j].otch << endl;
			cout << "���� �����������: " << notes[j].data.day << notes[j].data.month << notes[j].data.year << endl;
			cout << "������: " << notes[j].group << endl;
			cout << "���������: " << notes[j].fac << endl;
			cout << "������� ����: " << notes[j].county << endl;
		}
	}
	if (!found) {
		cout << "\n������ �� �������";
	}
	Menu();
	cout << "��� ������? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "������\n";
		cin >> task;
	}
}
