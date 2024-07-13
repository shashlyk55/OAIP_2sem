#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;

bool flag = false;
char a, b, c;
int num = 0;

union un {
	char task;
	bool found;
}mun;

struct Date {
	int day;
	int month;
	int year;
};

struct list {
	string name;
	string capital;
	string surname;
	int number;
	float square;
	float county;
};
struct list notes[100];
struct list nothing;
string country;
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
void delNote();

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
		cout << "��������: ";
		getchar();
		getline(cin, notes[num].name);
		flag = false;
		for (int j = 0; notes[num].name[j] != '\0'; j++) {
			if ((notes[num].name[j] < '�' || notes[num].name[j] > '�') && (notes[num].name[j] > '�' || notes[num].name[j] < '�')&& notes[num].name[j]!=' ') {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);

	do {
		cout << "�������: ";
		getchar();
		getline(cin, notes[num].capital);
		flag = false;
		for (int j = 0; notes[num].capital[j] != '\0'; j++) {
			if ((notes[num].capital[j] < '�' || notes[num].capital[j] > '�') && (notes[num].capital[j] > '�' || notes[num].capital[j] < '�')&& notes[num].capital[j]!=' ') {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);

	do {
		cout << "������� ����������: ";
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


	cout << "����������� ���������(���. ���.): ";
	cin >> notes[num].county;
	while (notes[num].county < 0.0 || notes[num].county>9999999.0) {
		cout << "������\n";
		cin >> notes[num].county;
	}

	cout << "�������(���. �� ��.): ";
	cin >> notes[num].square;
	while (notes[num].square < 0.0 || notes[num].square>9999999.0) {
		cout << "������\n";
		cin >> notes[num].square;
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
		cout << "��������: " << notes[j].name << endl;
		cout << "�������: " << notes[j].capital << endl;
		cout << "������� ����������: " << notes[j].surname << endl;
		cout << "����������� ���������: " << notes[j].county << endl;
		cout << "�������: " << notes[j].square << endl;
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

	mun.found = false;
	cout << "������� �������� ��� ������: ";
	getchar();
	getline(cin, country);
	for (int j = 0; j < num; j++) {
		if (country == notes[j].name) {
			mun.found = true;
			cout << "��������: " << notes[j].name << endl;
			cout << "�������: " << notes[j].capital << endl;
			cout << "������� ����������: " << notes[j].surname << endl;
			cout << "����������� ���������: " << notes[j].county << endl;
			cout << "�������: " << notes[j].square << endl;
		}
	}
	if (!mun.found) {
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
