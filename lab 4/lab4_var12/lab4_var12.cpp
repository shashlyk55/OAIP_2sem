#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>

#define maxSize 20
using namespace std;

 struct country {
	char name[30];
	char capital[30];
	char president[30];
	float square;
	float people;
	unsigned int number;
}strana;

int task, num = 0;
struct country info[maxSize];
struct country nothing;

void addElem();
void menu();
void print();
void delElem();
void search();
//void input(int size);
//void output();
void into_file(country* strct);
void out_file();


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	menu();
	cin >> task;
	while (true) {
		switch (task) {
		cin >> task;
		case 1:addElem(); break;
		case 2:print(); break;
		case 3:delElem(); break;
		case 4:search(); break;
		case 5:into_file(info); break;
		case 6:out_file(); break;
		case 7:exit(1); break;
		}
	}
}

void addElem() {
	cout << "���� ����������" << endl;
	cout << "����� ������: " << num + 1 << endl;
	info[num].number = num + 1;
	cout << "�������� ������: ";
	cin >> info[num].name;
	cout << "�������: ";
	cin >> info[num].capital;
	cout << "������� ����������: ";
	cin >> info[num].president;
	cout << "������� ������(���. ��. ��): ";
	cin >> info[num].square;
	cout << "����������� ���������(���. ���.): ";
	cin >> info[num].people;
	num++;
	system("cls");
	menu();
	cout << "��� ������? ";
	cin >> task;
}

void menu() {
	cout << "�������: " << endl
		<< "1 - �������� ������" << endl
		<< "2 - ������� �� �����" << endl
		<< "3 - ������� ������" << endl
		<< "4 - ����� ������" << endl
		<< "5 - ������ ���������� � ����" << endl
		<< "6 - ������ ������ �� �����" << endl
		<< "7 - �����" << endl;
}

void print() {
	cout << "1 - ����� 1 ������" << endl
		<< "2 - ����� ���� �����" << endl;
	int sw, n;
	cin >> sw;
	switch(sw) {
	case 1:
		cout << "����� ������ " << endl;
		cin >> n;
		cout << "�������� ������: " << info[n - 1].name << endl;
		cout << "�������: " << info[n - 1].capital << endl;
		cout << "������� ����������: " << info[n - 1].president << endl;
		cout << "������� ������(���. ��. ��): " << info[n - 1].square << endl;
		cout << "����������� ���������(���. ���.): " << info[n - 1].people << endl;
		break;
	case 2:
		for (int j = 0; j < num; j++) {
			printf("������ ����� %d\n", j + 1);
			cout << "�������� ������: " << info[j].name << endl;
			cout << "�������: " << info[j].capital << endl;
			cout << "������� ����������: " << info[j].president << endl;
			cout << "������� ������(���. ��. ��): " << info[j].square << endl;
			printf("����������� ���������(���. ���.): %f\n\n", info[j].people);
		}break;
	}
	menu();
	cout << "��� ������? ";
	cin >> task;
}

void delElem() {
	int d;
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ����� ������ 99)" << endl;  
	cin >> d;
	if (d != 99)
	{
		for (int del = (d - 1); del < num; del++) {
			info[del] = info[del + 1];
		}
		num -= 1;
	}
	if (d == 99) {
		for (int i = 0; i < maxSize; i++) {
			info[i] = nothing;
		}
	}
	cout << "������ ������� �� ������" << endl;
	menu();
	cout << "��� ������?" << endl;
	cin >> task;
}

void search() {
	cout << "����� ���������� �� �������� ������." << endl
		<< "������� �������� ������: ";
	char name[30];
	int position = -1;
	cin >> name;
	for (int i = 0; i < num; i++) {
		if (strcmp(info[i].name, name)==0) {
			position = i;
		}
	}
	if (position >= 0) {
		cout << "�������: " << endl;
		cout << "�������� ������: " << info[position].name << endl;
		cout << "�������: " << info[position].capital << endl;
		cout << "������� ����������: " << info[position].president << endl;
		cout << "������� ������(���. ��. ��): " << info[position].square << endl;
		cout << "����������� ���������(���. ���.): " << info[position].people << endl;
	}
	else
		cout << "������ �� �������" << endl;
	cout << "��� ������? ";
	cin >> task;
}


ofstream fout;
ifstream fin;
string str;

void into_file(country* strct)
{
	fout.open("data.txt", ios_base::out);
	for (int j = 0; j < num; j++)
	{
		fout << "������ ����� " << j + 1 << endl;
		fout << "�������� " << strct[j].name << endl;
		fout << "������� " << strct[j].capital << endl;
		fout << "��������� " << strct[j].president << endl;
		fout << "������� " << strct[j].square << endl;
		fout << "��������� " << strct[j].people << endl << endl;
	}
	fout.close();
	cout << "��� ������? ";
	cin >> task;
}


void out_file()
{
	fin.open("data.txt");
	while (!fin.eof()) {
		getline(fin, str);
		cout << str << endl;
	}
	cout << "��� ������? ";
	cin >> task;
	fin.close();
}