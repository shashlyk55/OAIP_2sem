#include "List.h"
#include <iostream>
#include<windows.h>
#include<string>
using namespace std;

struct Country
{
	string name;
	string capital;
	double people;
	double square;
	string president;
	Country* next;
};

void print(void* b)       //������� ������������ ��� ������ 
{
	Country* a = (Country*)b;
	cout << a->name << "\t" << a->capital << a->people << "\t" << a->square << "\t" << a->president << "\n";
}

int task, num = 0;

void menu() {
	cout << "�������: " << endl
		<< "1 - �������� �������" << endl
		<< "2 - ����� ������" << endl
		<< "3 - ������� �������" << endl
		<< "4 - ����� ��������" << endl
		<< "5 - �������� ������" << endl
		<< "6 - ������� ��������� ������" << endl
		<< "7 - �����" << endl;
	cin >> task;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
	Country a;
	bool rc;
	Object L1 = Create();

	Element* e;
	Country* aa;
	while (true) {
		switch (task) {
		case 1: {
			cout << "�������� ������: ";
			getchar();
			getline(cin, a.name);
			cout << "�������: ";
			getchar();
			getline(cin, a.capital);
			cout << "������� ����������: ";
			cin >> a.president;
			cout << "������� ������(���. ��. ��): ";
			cin >> a.square;
			cout << "����������� ���������(���. ���.): ";
			cin >> a.people;
			L1.Insert(&a); 
		}
			break;
		case 2:L1.PrintList(print);
			break;
		case 3:rc = L1.Delete(&a);
			if (rc == true) cout << "������ �������" << endl;
			break;
		case 4:
			e = L1.Search(&a);
			aa = (Country*)e->Data;
			cout << "������ ������� = " << aa->name << endl;
			break;
		case 5:L1.DeleteList();
			break;
		case 6:
			cout << "���������� ��������� � ������: " << L1.CountList() << endl;
			break;
		case 7:exit(1); 

		}
		cin >> task;
	}







	
	return 0;

	
}
