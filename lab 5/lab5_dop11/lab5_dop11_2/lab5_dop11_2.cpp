#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;

//���������� �����������. ����� ����������, ����, ��������� �����, ���� �������, ��� ������ (�����, ��������� � �. �.), ���� ���������� ����������, ��������. ����� ������������ ������� �� ���������.

bool flag = false;
char a, b, c;
int num = 0;

union un {
	char task;
	char surname[50];
}mun;

struct Date {
	int day;
	int month;
	int year;
};

struct list {
	string marka;
	string color;
	string nomer;
	Date date1;
	Date date2;
	string type;
	string surname;
	int number;
};
struct list notes[100];
int size = 0;
// ������� ����
void Menu() {
	cout << "\n1-���������� ������\n";
	cout << "2-����� �������\n";
	cout << "3-����� �� ��������\n";
	cout << "4-�����\n";
	cout << "��� ����� ������? ";
}

void addNote();
void print();
void search();

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	Menu();
	cin >> mun.task;
	while (mun.task > '4' || mun.task < '1') {
		cout << "������\n";
		cin >> mun.task;
	}
	while (true) {
		switch (mun.task) {
			cin >> mun.task;
			while (mun.task > '4' || mun.task < '1') {
				cout << "������\n";
				cin >> mun.task;
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
			exit(1);
		}
	}
}


void addNote() {
	cout << "���� ����������" << endl;
	cout << "�����: " << num + 1 << endl;
	notes[num].number = num + 1;
	do {
		cout << "����� ����: ";
		getchar();
		getline(cin, notes[num].marka);
		flag = false;
		for (int j = 0; notes[num].marka[j] != '\0'; j++) {
			if ((notes[num].marka[j] < '�' || notes[num].marka[j] > '�') && (notes[num].marka[j] > '�' || notes[num].marka[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);

	
	do {
		cout << "������� ���������: ";
		getchar();
		getline(cin, notes[num].surname);
		flag = false;
		for (int j = 0; notes[num].surname[j] != '\0'; j++) {
			if ((notes[num].surname[j] < '�' || notes[num].surname[j] > '�') && (notes[num].surname[j] > '�' || notes[num].surname[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);

	do {
		cout << "����: ";
		getchar();
		getline(cin, notes[num].color);
		flag = false;
		for (int j = 0; notes[num].color[j] != '\0'; j++) {
			if ((notes[num].color[j] < '�' || notes[num].color[j] > '�') && (notes[num].color[j] > '�' || notes[num].color[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);

	do {
		cout << "�������� �����: ";
		getchar();
		getline(cin, notes[num].nomer);
		flag = false;
		for (int j = 0; notes[num].nomer[j] != '\0'; j++) {
			if ((notes[num].nomer[j] < '�' || notes[num].nomer[j] > '�') && (notes[num].nomer[j] > '�' || notes[num].nomer[j] < '�') && (notes[num].nomer[j] > '9' || notes[num].nomer[j] < '0')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
	
	do {
		cout << "��� ������: ";
		getchar();
		getline(cin, notes[num].type);
		flag = false;
		for (int j = 0; notes[num].type[j] != '\0'; j++) {
			if ((notes[num].type[j] < '�' || notes[num].type[j] > '�') && (notes[num].type[j] > '�' || notes[num].type[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);

	
		cout << "���� �������: " << endl;
		cout << "����: ";
		cin >> notes[num].date1.day;
		while (notes[num].date1.day < 0 || notes[num].date1.day>31) {
			cout << "������\n";
			cin >> notes[num].date1.day;
		}
		cout << "�����: ";
		cin >> notes[num].date1.month;
		while (notes[num].date1.month < 0 || notes[num].date1.month>31) {
			cout << "������\n";
			cin >> notes[num].date1.month;
		}
		cout << "���: ";
		cin >> notes[num].date1.year;
		while (notes[num].date1.year < 0 || notes[num].date1.year>31) {
			cout << "������\n";
			cin >> notes[num].date1.year;
		}

		cout << "���� ���������� ����������: " << endl;
		cout << "����: ";
		cin >> notes[num].date2.day;
		while (notes[num].date2.day < 0 || notes[num].date2.day>31) {
			cout << "������\n";
			cin >> notes[num].date2.day;
		}
		cout << "�����: ";
		cin >> notes[num].date2.month;
		while (notes[num].date2.month < 0 || notes[num].date2.month>31) {
			cout << "������\n";
			cin >> notes[num].date2.month;
		}
		cout << "���: ";
		cin >> notes[num].date2.year;
		while (notes[num].date2.year < 0 || notes[num].date2.year>31) {
			cout << "������\n";
			cin >> notes[num].date2.year;
		}

	cout << endl;
	num++;
	system("cls");
	Menu();
	cout << "��� ������? ";
	cin >> mun.task;
	while (mun.task > '4' || mun.task < '1') {
		cout << "������\n";
		cin >> mun.task;
	}
}

void print() {

	cout << "����� ���� �������" << endl;

	for (int j = 0; j < num; j++) {
		cout << "����� ����������: " << notes[j].marka << endl;
		cout << "������� ���������: " << notes[j].surname << endl;
		cout << "����: " << notes[j].color << endl;
		cout << "�������� �����: " << notes[j].nomer << endl;
		cout << "���� �������: " << notes[j].date1.year << notes[j].date1.month << notes[j].date1.day << endl;
		cout << "��� ������: " << notes[j].type << endl;
		cout<<"���� ���������� ����������: " << notes[j].date2.year << notes[j].date2.month << notes[j].date2.day << endl;
	}
	Menu();
	cout << "��� ������? ";
	cin >> mun.task;
	while (mun.task > '4' || mun.task < '1') {
		cout << "������\n";
		cin >> mun.task;
	}
}

void search() {

	bool found = false;
	cout << "������� �������� ��� ������: ";
	cin >> mun.surname;
	for (int j = 0; j < num; j++) {
		if (mun.surname == notes[j].surname) {
			found = true;
			cout << "����� ����������: " << notes[j].marka << endl;
			cout << "������� ���������: " << notes[j].surname << endl;
			cout << "����: " << notes[j].color << endl;
			cout << "�������� �����: " << notes[j].nomer << endl;
			cout << "���� �������: " << notes[j].date1.year << notes[j].date1.month << notes[j].date1.day << endl;
			cout << "��� ������: " << notes[j].type << endl;
			cout << "���� ���������� ����������: " << notes[j].date2.year << notes[j].date2.month << notes[j].date2.day << endl;
		}
	}
	if (!found) {
		cout << "\n������ �� �������";
	}
	Menu();
	cout << "��� ������? ";
	cin >> mun.task;
	while (mun.task > '4' || mun.task < '1') {
		cout << "������\n";
		cin >> mun.task;
	}
}
