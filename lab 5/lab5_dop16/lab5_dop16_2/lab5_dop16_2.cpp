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
	float ball;
}mun;

struct Date {
	int day;
	int month;
	int year;
};

struct list {
	string name;
	string surname;
	string otch;
	string spec;
	string fac;
	Date data;
	char group;
	int number;
	float mark;
};
struct list notes[100];
int size = 0;
// ������� ����
void Menu() {
	cout << "\n1-���������� ������\n";
	cout << "2-����� �������\n";
	cout << "3-����� �� �������� �����\n";
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
	cout << "���:\n";
	do {
		cout << "�������: ";
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

	cout << "���� �����������: ";
	cout << "����: ";
	cin >> notes[num].data.day;
	while (notes[num].data.day < 0 || notes[num].data.day>31) {
		cout << "������\n";
		cin >> notes[num].data.day;
	}
	cout << "�����: ";
	cin >> notes[num].data.month;
	while (notes[num].data.month < 0 || notes[num].data.month>12) {
		cout << "������\n";
		cin >> notes[num].data.month;
	}
	cout << "���: ";
	cin >> notes[num].data.year;
	while (notes[num].data.year < 0 || notes[num].data.year>9999) {
		cout << "������\n";
		cin >> notes[num].data.year;
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
		cout<<"������\n";
		cin >> notes[num].group;
	}

	do {
		cout << "���������: ";
		getchar();
		getline(cin, notes[num].fac);
		flag = false;
		for (int j = 0; notes[num].fac[j] != '\0'; j++) {
			if ((notes[num].fac[j] < '�' || notes[num].fac[j] > '�') && (notes[num].fac[j] > '�' || notes[num].fac[j] < '�') && notes[num].fac[j] != ' ') {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);

	
	cout << "������� ����: ";
	cin >> notes[num].mark;
	while (notes[num].mark < 0.0 || notes[num].mark>10.0) {
		cout << "������\n";
		cin >> notes[num].mark;
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

	cout << "����� ���� ���������" << endl;

	for (int j = 0; j < num; j++) {
		cout << "���: " << notes[j].surname << notes[j].name << notes[j].otch << endl;
		cout << "���� �����������: " << notes[j].data.day << notes[j].data.month << notes[j].data.year << endl;
		cout << "������: " << notes[j].group << endl;
		cout << "���������: " << notes[j].fac << endl;
		cout << "������� ����: " << notes[j].mark << endl;
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
	cout << "������� ������� ���� ��� ������: ";
	cin >> mun.ball;
	for (int j = 0; j < num; j++) {
		if (mun.ball == notes[j].mark) {
			found = true;
			cout << "���: " << notes[j].surname << notes[j].name << notes[j].otch << endl;
			cout << "���� �����������: " << notes[j].data.day << notes[j].data.month << notes[j].data.year << endl;
			cout << "������: " << notes[j].group << endl;
			cout << "���������: " << notes[j].fac << endl;
			cout << "������� ����: " << notes[j].mark << endl;
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
