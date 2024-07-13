
#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;
//�������� ������.�.�.�, ���� ��������, �����, �������, ����� ������ ��� �����, ���������.����� �� �������.
char stateMenu;
bool flag = false;
char a, b, c;

union Data {
	char day[2];
	char month[2];
	char year[4];
};

struct contacts {
	string name;
	string surname;
	string otch;
	string adres;
	string tel;
	string place;
	string job;
	Data date;
};

// ������� ����
void Menu() {
	cout << "\n1-���������� ��������\n";
	cout << "2-����� ���� ���������\n";
	cout << "3-����� �� �������\n";
	cout << "4-�����\n";
	cout << "��� ����� ������? ";
}

union Date {
	struct {
		char day[2];
		char month[2];
		char year[4];
	};
	int date[3];
};

struct contact {
	string name;
	string surname;
	string otch;
	string adres;
	string tel;
	string place;
	string job;
	Date date;
};

// ������� ��� ����� ����
void InputDate(Date& date) {
	
	cout << "������� ����: ";
	cin >> date.day;
	while ((date.day[0] < '0' || date.day[0]>'3') || (date.day[1] < '0' || date.day[1]>'9') || (date.day[0] == '3' && date.day[1] > '1')) {
		cout << "������\n";
		cin >> date.day;
	}
	cout << "������� �����: ";
	cin >> date.month;
	while ((date.month[0] < '0' || date.month[0]>'1') || ((date.month[0] == '1' && (date.month[1] < '0' || date.month[1]>'2')) || (date.month[0] == '0' && (date.month[1] < '1' || date.month[1]>'9'))) ){
		cout << "������\n";
		cin >> date.month;
	}
	cout << "������� ���: ";
	cin >> date.year;
	do {
		for (int i = 0; i < 4; i++) {
			if (date.year[i] < '0' || date.year[i]>'9') {
				cout << "������\n";
				flag = true;
				break;
			}
		}
	} while (flag);
	flag = false;
}

// ������� ��� ����� ��������
void InputContact(contact& cont) {
	do {
		cout << "������� �������: ";
		getchar();
		getline(cin, cont.surname);
		flag = false;
		for (int j = 0; cont.surname[j] != '\0'; j++) {
			if ((cont.surname[j] < '�' || cont.surname[j] > '�') && (cont.surname[j] > '�' || cont.surname[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "������� ���: ";
		getchar();
		getline(cin, cont.name);
		flag = false;
		for (int j = 0; cont.name[j] != '\0'; j++) {
			if ((cont.name[j] < '�' || cont.name[j] > '�') && (cont.name[j] > '�' || cont.name[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "������� ��������: ";
		getchar();
		getline(cin, cont.otch);
		flag = false;
		for (int j = 0; cont.otch[j] != '\0'; j++) {
			if ((cont.otch[j] < '�' || cont.otch[j] > '�') && (cont.otch[j] > '�' || cont.otch[j] < '�')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
	//InputDate(cont.date);

	cout << "������� ����: ";
	cin >> cont.date.day;
	while ((cont.date.day[0] < '0' || cont.date.day[0]>'3') || (cont.date.day[1] < '0' || cont.date.day[1]>'9') || (cont.date.day[0] == '3' && cont.date.day[1] > '1')) {
		cout << "������\n";
		cin >> cont.date.day;
	}
	cout << "������� �����: ";
	cin >> cont.date.month;
	while ((cont.date.month[0] < '0' || cont.date.month[0]>'1') || ((cont.date.month[0] == '1' && (cont.date.month[1] < '0' || cont.date.month[1]>'2')) || (cont.date.month[0] == '0' && (cont.date.month[1] < '1' || cont.date.month[1]>'9')))) {
		cout << "������\n";
		cin >> cont.date.month;
	}
	cout << "������� ���: ";
	cin >> cont.date.year;
	do {
		for (int i = 0; i < 4; i++) {
			if (cont.date.year[i] < '0' || cont.date.year[i]>'9') {
				cout << "������\n";
				flag = true;
				break;
			}
		}
	} while (flag);
	flag = false;

	do {
		cout << "������� �����: ";
		getchar();
		getline(cin, cont.adres);
		flag = false;
		for (int j = 0; cont.adres[j] != '\0'; j++) {
			if ((cont.adres[j] < '�' || cont.adres[j] > '�') && (cont.adres[j] > '�' || cont.adres[j] < '�') && cont.adres[j] != ' ' && (cont.adres[j] < '0' || cont.adres[j]>'9')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "�������: ";
		getchar();
		getline(cin, cont.adres);
		flag = false;
		for (int j = 0; cont.tel[j] != '\0'; j++) {
			if (cont.tel[j] < '0' || cont.tel[j]>'9') {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "����� ������: ";
		getchar();
		getline(cin, cont.place);
		flag = false;
		for (int j = 0; cont.place[j] != '\0'; j++) {
			if ((cont.place[j] < '�' || cont.place[j] > '�') && (cont.place[j] > '�' || cont.place[j] < '�') && cont.place[j] != ' ' && (cont.place[j] < '0' || cont.place[j]>'9')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "���������: ";
		getchar();
		getline(cin, cont.job);
		flag = false;
		for (int j = 0; cont.job[j] != '\0'; j++) {
			if ((cont.job[j] < '�' || cont.job[j] > '�') && (cont.job[j] > '�' || cont.job[j] < '�') && cont.job[j] != ' ' && (cont.job[j] < '0' || cont.job[j]>'9')) {
				flag = true;
				cout << "������\n";
				break;
			}
		}
	} while (flag);
	Menu();
	cin >> stateMenu;
	while (stateMenu > '4' || stateMenu < '1') {
		cout << "������\n";
		cin >> stateMenu;
	}
}

//������� ��� ������ ��������
void OutputContact(contact& cont) {
	cout << "�������: " << cont.surname << endl;
	cout << "���: " << cont.name << endl;
	cout << "��������: " << cont.otch << endl;
	cout << "���� ��������(��������): " << cont.date.day << endl;
	cout << "�����: " << cont.adres << endl;
	cout << "�������: " << cont.tel << endl;
	cout << "����� ������: " << cont.place << endl;
	cout << "���������: " << cont.job << endl;
}

// ������� ��� ������ ���� ���������
void OutputAllContacts(contact* cont, int size) {
	for (int i = 0; i < size; i++) {
		OutputContact(cont[i]);
		cout << endl;
	}
	Menu();
	cin >> stateMenu;
	while (stateMenu > '4' || stateMenu < '1') {
		cout << "������\n";
		cin >> stateMenu;
	}
}

// ������� ��� ������ �� �������
void SearchContactBySurname(contact* cont, int size) {
	string surname;
	cout << "������� �������: ";
	cin >> surname;
	for (int i = 0; i < size; i++) {
		if (cont[i].surname == surname) {
			OutputContact(cont[i]);
			cout << endl;
		}
	}
	Menu();
	cin >> stateMenu;
	while (stateMenu > '4' || stateMenu < '1') {
		cout << "������\n";
		cin >> stateMenu;
	}
}



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	contact* list = new contact[100];
	int size = 0;
	Menu();
	cin >> stateMenu;
	while (stateMenu > '4' || stateMenu < '1') {
		cout << "������\n";
		cin >> stateMenu;
	}
	while (true) {
		switch (stateMenu) {
			cin >> stateMenu;
			while (stateMenu > '4' || stateMenu < '1') {
				cout << "������\n";
				cin >> stateMenu;
			}
		case '1':
			InputContact(list[size]);
			size++;
			break;
		case '2':
			OutputAllContacts(list, size);
			break;
		case '3':
			SearchContactBySurname(list, size);
			break;
		case '4':
			exit(1);
		}
	}
	delete[] list;
}