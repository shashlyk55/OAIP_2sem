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
// Функция меню
void Menu() {
	cout << "\n1-Добавление записи\n";
	cout << "2-Вывод записей\n";
	cout << "3-Поиск по среднему баллу\n";
	cout << "4-Удаление записи\n";
	cout << "5-Выход\n";
	cout << "Что будем делать? ";
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
		cout << "Ошибка\n";
		cin >> task;
	}
	while (true) {
		switch (task) {
			cin >> task;
			while (task > '4' || task < '1') {
				cout << "Ошибка\n";
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
	cout << "\nНомер записи, которую надо удалить (для удаления всех нажать 99)" << endl;
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
	cout << "Запись удалена из списка" << endl;
	Menu();
	cout << "Что дальше?" << endl;
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "Ошибка\n";
		cin >> task;
	}
}

void addNote() {
	cout << "Ввод информации" << endl;
	cout << "Номер: " << num + 1 << endl;
	notes[num].number = num + 1;
	cout << "ФИО:\n";
	do {
		cout << "Фамилия: ";
		getchar();
		getline(cin, notes[num].capital);
		flag = false;
		for (int j = 0; notes[num].capital[j] != '\0'; j++) {
			if ((notes[num].capital[j] < 'а' || notes[num].capital[j] > 'я') && (notes[num].capital[j] > 'Я' || notes[num].capital[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);

	do {
		cout << "Имя: ";
		getchar();
		getline(cin, notes[num].name);
		flag = false;
		for (int j = 0; notes[num].name[j] != '\0'; j++) {
			if ((notes[num].name[j] < 'а' || notes[num].name[j] > 'я') && (notes[num].name[j] > 'Я' || notes[num].name[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);

	do {
		cout << "Отчество: ";
		getchar();
		getline(cin, notes[num].otch);
		flag = false;
		for (int j = 0; notes[num].otch[j] != '\0'; j++) {
			if ((notes[num].otch[j] < 'а' || notes[num].otch[j] > 'я') && (notes[num].otch[j] > 'Я' || notes[num].otch[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);

	cout << "Дата поступления(ДДММГГГГ): ";
	cout << "День: ";
	cin >> a;
	notes[num].data.day = a;
	while (a < 0 || a>31) {
		cout << "Ошибка\n";
		cin >> a;
		notes[num].data.day = a;
	}
	cout << "Месяц: ";
	cin >> a;
	notes[num].data.month = a;
	while (a < 0 || a>12) {
		cout << "Ошибка\n";
		cin >> a;
		notes[num].data.month = a;
	}
	cout << "Год: ";
	cin >> a;
	notes[num].data.year = a;
	while (a < 0 || notes[num].data.year>9999) {
		cout << "Ошибка\n";
		cin >> a;
		notes[num].data.year = a;
	}

	do {
		cout << "Специальность: ";
		getchar();
		getline(cin, notes[num].spec);
		flag = false;
		for (int j = 0; notes[num].spec[j] != '\0'; j++) {
			if ((notes[num].spec[j] < 'а' || notes[num].spec[j] > 'я') && (notes[num].spec[j] > 'Я' || notes[num].spec[j] < 'А') && notes[num].spec[j] != ' ') {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);

	cout << "Группа: ";
	cin >> notes[num].group;
	while (notes[num].group < '0' || notes[num].group>'9') {
		cout << "Ошибка\n";
		cin >> notes[num].group;
	}

		cout << "Факультет(1-ФИТ,2-ХТИТ,3-ПИМ,4-ТОВ): ";
		cin >> f;
		while (f < 1 || f > 4) {
			cout << "Ошибка\n";
			cin >> f;
		}
		switch (f) {
		case FIT: 
			notes[num].fac = "ФИТ";
			break;
		case HTIT:
			notes[num].fac = "ХТИТ";
			break;
		case PIM:
			notes[num].fac = "ПИМ";
			break;
		case TOV:
			notes[num].fac = "ТОВ";
			break;
		}

	cout << "Средний балл: ";
	cin >> notes[num].county;
	while (notes[num].county < 0.0 || notes[num].county>10.0) {
		cout << "ОШибка\n";
		cin >> notes[num].county;
	}

	cout << endl;
	num++;
	system("cls");
	Menu();
	cout << "Что дальше? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "Ошибка\n";
		cin >> task;
	}
}

void print() {

	cout << "вывод всех контактов" << endl;

	for (int j = 0; j < num; j++) {
		cout << "ФИО: " << notes[j].capital << notes[j].name << notes[j].otch << endl;
		cout << "Дата поступления: " << notes[j].data.day << notes[j].data.month << notes[j].data.year << endl;
		cout << "Группа: " << notes[j].group << endl;
		cout << "Факультет: " << notes[j].fac << endl;
		cout << "Средний балл: " << notes[j].county << endl;
	}
	Menu();
	cout << "Что дальше? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "Ошибка\n";
		cin >> task;
	}
}

void search() {
	float ball;
	bool found = false;
	cout << "Введите средний балл для поиска: ";
	cin >> ball;
	for (int j = 0; j < num; j++) {
		if (ball == notes[j].county) {
			found = true;
			cout << "ФИО: " << notes[j].capital << notes[j].name << notes[j].otch << endl;
			cout << "Дата поступления: " << notes[j].data.day << notes[j].data.month << notes[j].data.year << endl;
			cout << "Группа: " << notes[j].group << endl;
			cout << "Факультет: " << notes[j].fac << endl;
			cout << "Средний балл: " << notes[j].county << endl;
		}
	}
	if (!found) {
		cout << "\nЗапись не найдена";
	}
	Menu();
	cout << "Что дальше? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "Ошибка\n";
		cin >> task;
	}
}
