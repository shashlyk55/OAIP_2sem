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
		cout << "Ошибка\n";
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
	cout << "\n1 - добавить контакт\n2 - вывод на экран\n3 - удаление контакта\n4 - поиск контакта\n5 - выход из программы\n";
}

int a;
void addContact() {
	cout << "Ввод информации" << endl;
	cout << "Номер: " << num + 1 << endl;
	list[num].number = num + 1;
	cout << "ФИО: " << endl;
	do {
		cout << "Фамилию: ";
		getchar();
		getline(cin, list[num].fio.fam);
		flag = false;
		for (int j = 0; list[num].fio.fam[j] != '\0'; j++) {
			if ((list[num].fio.fam[j] < 'а' || list[num].fio.fam[j] > 'я') && (list[num].fio.fam[j] > 'Я' || list[num].fio.fam[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "Имя: ";
		getchar();
		getline(cin, list[num].fio.name);
		flag = false;
		for (int j = 0; list[num].fio.name[j] != '\0'; j++) {
			if ((list[num].fio.name[j] < 'а' || list[num].fio.name[j] > 'я') && (list[num].fio.name[j] > 'Я' || list[num].fio.name[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "Отчество: ";
		getchar();
		getline(cin, list[num].fio.otch);
		flag = false;
		for (int j = 0; list[num].fio.otch[j] != '\0'; j++) {
			if ((list[num].fio.otch[j] < 'а' || list[num].fio.otch[j] > 'я') && (list[num].fio.otch[j] > 'Я' || list[num].fio.otch[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "Адрес: ";
		getchar();
		getline(cin, list[num].adres);
		flag = false;
		for (int j = 0; list[num].adres[j] != '\0'; j++) {
			if ((list[num].adres[j] < 'а' || list[num].adres[j] > 'я') && (list[num].adres[j] > 'Я' || list[num].adres[j] < 'А') && (list[num].adres[j] < '0' || list[num].adres[j]>'9')&& list[num].adres[j]!=' ') {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	cout << "Дата рождения: ";
	cout << "День: ";
	cin >> a;
	while (a < 0 || a>31) {
		cout << "Ошибка\n";
		cin >> a;
	}
	list[num].date.day = a;
	cout << "Месяц: ";
	cin >> a;
	while (a < 0 || a>12) {
		cout << "Ошибка\n";
		cin >> a;
	}
	list[num].date.month = a;
	cout << "Год: ";
	cin >> a;
	while (a < 0 || a>9999) {
		cout << "Ошибка\n";
		cin >> a;
	}
	list[num].date.year = a;
	do {
		cout << "Телефон: ";
		getchar();
		getline(cin, list[num].tel);
		flag = false;
		for (int j = 0; list[num].tel[j] != '\0'; j++) {
			if (list[num].tel[j] < '0' || list[num].tel[j]>'9') {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	
	
	
	do {
		cout << "Место работы: ";
		getchar();
		getline(cin, list[num].job);
		flag = false;
		for (int j = 0; list[num].job[j] != '\0'; j++) {
			if ((list[num].job[j] < 'а' || list[num].job[j] > 'я') && (list[num].job[j] > 'Я' || list[num].job[j] < 'А') && list[num].job[j] != ' ' && (list[num].job[j] < '0' || list[num].job[j]>'9')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "Должность: ";
		getchar();
		getline(cin, list[num].title);
		flag = false;
		for (int j = 0; list[num].title[j] != '\0'; j++) {
			if ((list[num].title[j] < 'а' || list[num].title[j] > 'я') && (list[num].title[j] > 'Я' || list[num].title[j] < 'А') && list[num].title[j] != ' ' && (list[num].title[j] < '0' || list[num].title[j]>'9')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	cout << endl;
	num++;
	system("cls");
	menu();
	cout << "Что дальше? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "Ошибка\n";
		cin >> task;
	}
}

void delContact() {
	int d;
	cout << "\nНомер контакта, который надо удалить (для удаления всех нажать 99)" << endl;
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
	cout << "Контакт удален из списка" << endl;
	menu();
	cout << "Что дальше?" << endl;
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "Ошибка\n";
		cin >> task;
	}
}

void print() {
	cout << "1 - вывод 1 контакта" << endl
		<< "2 - вывод всех контактов" << endl;
	int sw, n;
	cin >> sw;
	switch (sw) {
	case 1:
		cout << "Номер контакта всписке " << endl;
		cin >> n;
		cout << "ФИО: \nФамилия: " << list[n - 1].fio.fam << endl;
		cout << "Имя: " << list[n - 1].fio.name << endl;
		cout << "Отчество: " << list[n - 1].fio.otch << endl;
		cout << "Адрес: " << list[n - 1].adres << endl;
		cout << "Дата рождения: " << list[n - 1].date.day << "." << list[n - 1].date.month << "." << list[n - 1].date.year << endl;
		cout << "Работы: " << list[n - 1].job << endl;
		cout << "Должность: " << list[n - 1].title << endl;
		cout << "Номер телефона: " << list[n - 1].tel << endl << endl;
		break;
	case 2:
		for (int j = 0; j < num; j++) {
			cout << "ФИО: \nФамилия: " << list[j].fio.fam << endl;
			cout << "Имя: " << list[j].fio.name << endl;
			cout << "Отчество: " << list[j].fio.otch << endl;
			cout << "Адрес: " << list[j].adres << endl;
			cout << "Дата рождения: " << list[j].date.day << "." << list[j].date.month << "." << list[j].date.year << endl;
			cout << "Работы: " << list[j].job << endl;
			cout << "Должность: " << list[j].title << endl;
			cout << "Номер телефона: " << list[j].tel << endl << endl;
		}break;
	}
	menu();
	cout << "Что дальше? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "Ошибка\n";
		cin >> task;
	}
}

void search() {
	string surname;
	bool found = false;
	cout << "Введите фамилию для поиска: ";
	cin >> surname;
	for (int i = 0; i < num; i++) {
		if (list[i].fio.fam == surname) {
			found = true;
			cout << "ФИО: \nФамилия: " << list[i].fio.fam << endl;
			cout << "Имя: " << list[i].fio.name << endl;
			cout << "Отчество: " << list[i].fio.otch << endl;
			cout << "Адрес: " << list[i].adres << endl;
			cout << "Дата рождения: " << list[i].date.day << "." << list[i].date.month << "." << list[i].date.year << endl;
			cout << "Работы: " << list[i].job << endl;
			cout << "Должность: " << list[i].title << endl;
			cout << "Номер телефона: " << list[i].tel << endl << endl;
		}
		found = false;
	}
	if(found){
		cout << "\nКонтак не найден";
	}
	menu();
	cout << "Что дальше? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "Ошибка\n";
		cin >> task;
	}
}