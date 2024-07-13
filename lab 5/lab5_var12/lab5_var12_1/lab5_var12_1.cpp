#include<iostream>
#include<windows.h>
#include<string>
#define maxSize 20
using namespace std;

void menu();
void search();
void addContact();
void delContact();
void print();

struct birth {
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 12;
};

struct famNameOtch {
	string fam;
	string name;
	string otch;
}fio;

struct list {
	famNameOtch fio;
	string adres;
	string job;
	string title;
	string tel;
	int number;
	struct birth date;
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
		case '1': addContact(); break;
		case '2': print(); break;
		case '3': delContact(); break;
		case '4': search(); break;
		case '5': exit(1); break;
		}
	}
}

void menu() {
	cout << "\n1 - �������� �������\n2 - ����� �� �����\n3 - �������� ��������\n4 - ����� ��������\n5 - ����� �� ���������\n";
}

int a;
void addContact() {
	cout << "���� ����������" << endl;
	cout << "�����: " << num + 1 << endl;
	list[num].number = num + 1;
	cout << "���: " << endl;
	do {
		cout << "�������: ";
		getchar();
		getline(cin, list[num].fio.fam);
		flag = false;
		for (int j = 0; list[num].fio.fam[j] != '\0'; j++) {
			if ((list[num].fio.fam[j] < '�' || list[num].fio.fam[j] > '�') && (list[num].fio.fam[j] > '�' || list[num].fio.fam[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "���: ";
		getchar();
		getline(cin, list[num].fio.name);
		flag = false;
		for (int j = 0; list[num].fio.name[j] != '\0'; j++) {
			if ((list[num].fio.name[j] < '�' || list[num].fio.name[j] > '�') && (list[num].fio.name[j] > '�' || list[num].fio.name[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "��������: ";
		getchar();
		getline(cin, list[num].fio.otch);
		flag = false;
		for (int j = 0; list[num].fio.otch[j] != '\0'; j++) {
			if ((list[num].fio.otch[j] < '�' || list[num].fio.otch[j] > '�') && (list[num].fio.otch[j] > '�' || list[num].fio.otch[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "�����: ";
		getchar();
		getline(cin, list[num].adres);
		flag = false;
		for (int j = 0; list[num].adres[j] != '\0'; j++) {
			if ((list[num].adres[j] < '�' || list[num].adres[j] > '�') && (list[num].adres[j] > '�' || list[num].adres[j] < '�') && (list[num].adres[j] < '0' || list[num].adres[j]>'9')&& list[num].adres[j]!=' ') {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
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
	do {
		cout << "�������: ";
		getchar();
		getline(cin, list[num].tel);
		flag = false;
		for (int j = 0; list[num].tel[j] != '\0'; j++) {
			if (list[num].tel[j] < '0' || list[num].tel[j]>'9') {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
	
	
	
	do {
		cout << "����� ������: ";
		getchar();
		getline(cin, list[num].job);
		flag = false;
		for (int j = 0; list[num].job[j] != '\0'; j++) {
			if ((list[num].job[j] < '�' || list[num].job[j] > '�') && (list[num].job[j] > '�' || list[num].job[j] < '�') && list[num].job[j] != ' ' && (list[num].job[j] < '0' || list[num].job[j]>'9')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "���������: ";
		getchar();
		getline(cin, list[num].title);
		flag = false;
		for (int j = 0; list[num].title[j] != '\0'; j++) {
			if ((list[num].title[j] < '�' || list[num].title[j] > '�') && (list[num].title[j] > '�' || list[num].title[j] < '�') && list[num].title[j] != ' ' && (list[num].title[j] < '0' || list[num].title[j]>'9')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
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

void delContact() {
	int d;
	cout << "\n����� ��������, ������� ���� ������� (��� �������� ���� ������ 99)" << endl;
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
	cout << "������� ������ �� ������" << endl;
	menu();
	cout << "��� ������?" << endl;
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "������\n";
		cin >> task;
	}
}

void print() {
	cout << "1 - ����� 1 ��������" << endl
		<< "2 - ����� ���� ���������" << endl;
	int sw, n;
	cin >> sw;
	switch (sw) {
	case 1:
		cout << "����� �������� ������� " << endl;
		cin >> n;
		cout << "���: \n�������: " << list[n - 1].fio.fam << endl;
		cout << "���: " << list[n - 1].fio.name << endl;
		cout << "��������: " << list[n - 1].fio.otch << endl;
		cout << "�����: " << list[n - 1].adres << endl;
		cout << "���� ��������: " << list[n - 1].date.day << "." << list[n - 1].date.month << "." << list[n - 1].date.year << endl;
		cout << "������: " << list[n - 1].job << endl;
		cout << "���������: " << list[n - 1].title << endl;
		cout << "����� ��������: " << list[n - 1].tel << endl << endl;
		break;
	case 2:
		for (int j = 0; j < num; j++) {
			cout << "���: \n�������: " << list[j].fio.fam << endl;
			cout << "���: " << list[j].fio.name << endl;
			cout << "��������: " << list[j].fio.otch << endl;
			cout << "�����: " << list[j].adres << endl;
			cout << "���� ��������: " << list[j].date.day << "." << list[j].date.month << "." << list[j].date.year << endl;
			cout << "������: " << list[j].job << endl;
			cout << "���������: " << list[j].title << endl;
			cout << "����� ��������: " << list[j].tel << endl << endl;
		}break;
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
	string surname;
	bool found = false;
	cout << "������� ������� ��� ������: ";
	cin >> surname;
	for (int i = 0; i < num; i++) {
		if (list[i].fio.fam == surname) {
			found = true;
			cout << "���: \n�������: " << list[i].fio.fam << endl;
			cout << "���: " << list[i].fio.name << endl;
			cout << "��������: " << list[i].fio.otch << endl;
			cout << "�����: " << list[i].adres << endl;
			cout << "���� ��������: " << list[i].date.day << "." << list[i].date.month << "." << list[i].date.year << endl;
			cout << "������: " << list[i].job << endl;
			cout << "���������: " << list[i].title << endl;
			cout << "����� ��������: " << list[i].tel << endl << endl;
		}
		found = false;
	}
	if(found){
		cout << "\n������ �� ������";
	}
	menu();
	cout << "��� ������? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "������\n";
		cin >> task;
	}
}