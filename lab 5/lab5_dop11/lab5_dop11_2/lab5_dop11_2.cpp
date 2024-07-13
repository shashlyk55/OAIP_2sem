#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;

//Справочник автомобилей. Марка автомобиля, цвет, заводской номер, дата выпуска, тип кузова (седан, универсал и т. п.), дата последнего техосмотра, владелец. Выбор транспортных средств по владельцу.

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
// Функция меню
void Menu() {
	cout << "\n1-Добавление записи\n";
	cout << "2-Вывод записей\n";
	cout << "3-Поиск по названию\n";
	cout << "4-Выход\n";
	cout << "Что будем делать? ";
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
		cout << "Ошибка\n";
		cin >> mun.task;
	}
	while (true) {
		switch (mun.task) {
			cin >> mun.task;
			while (mun.task > '4' || mun.task < '1') {
				cout << "Ошибка\n";
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
	cout << "Ввод информации" << endl;
	cout << "Номер: " << num + 1 << endl;
	notes[num].number = num + 1;
	do {
		cout << "Марка авто: ";
		getchar();
		getline(cin, notes[num].marka);
		flag = false;
		for (int j = 0; notes[num].marka[j] != '\0'; j++) {
			if ((notes[num].marka[j] < 'а' || notes[num].marka[j] > 'я') && (notes[num].marka[j] > 'Я' || notes[num].marka[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);

	
	do {
		cout << "Фамилия владельца: ";
		getchar();
		getline(cin, notes[num].surname);
		flag = false;
		for (int j = 0; notes[num].surname[j] != '\0'; j++) {
			if ((notes[num].surname[j] < 'а' || notes[num].surname[j] > 'я') && (notes[num].surname[j] > 'Я' || notes[num].surname[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);

	do {
		cout << "Цвет: ";
		getchar();
		getline(cin, notes[num].color);
		flag = false;
		for (int j = 0; notes[num].color[j] != '\0'; j++) {
			if ((notes[num].color[j] < 'а' || notes[num].color[j] > 'я') && (notes[num].color[j] > 'Я' || notes[num].color[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);

	do {
		cout << "Серийный номер: ";
		getchar();
		getline(cin, notes[num].nomer);
		flag = false;
		for (int j = 0; notes[num].nomer[j] != '\0'; j++) {
			if ((notes[num].nomer[j] < 'а' || notes[num].nomer[j] > 'я') && (notes[num].nomer[j] > 'Я' || notes[num].nomer[j] < 'А') && (notes[num].nomer[j] > '9' || notes[num].nomer[j] < '0')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	
	do {
		cout << "Тип кузова: ";
		getchar();
		getline(cin, notes[num].type);
		flag = false;
		for (int j = 0; notes[num].type[j] != '\0'; j++) {
			if ((notes[num].type[j] < 'а' || notes[num].type[j] > 'я') && (notes[num].type[j] > 'Я' || notes[num].type[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);

	
		cout << "Дата выпуска: " << endl;
		cout << "День: ";
		cin >> notes[num].date1.day;
		while (notes[num].date1.day < 0 || notes[num].date1.day>31) {
			cout << "Ошибка\n";
			cin >> notes[num].date1.day;
		}
		cout << "Месяц: ";
		cin >> notes[num].date1.month;
		while (notes[num].date1.month < 0 || notes[num].date1.month>31) {
			cout << "Ошибка\n";
			cin >> notes[num].date1.month;
		}
		cout << "Год: ";
		cin >> notes[num].date1.year;
		while (notes[num].date1.year < 0 || notes[num].date1.year>31) {
			cout << "Ошибка\n";
			cin >> notes[num].date1.year;
		}

		cout << "Дата последнего техосмотра: " << endl;
		cout << "День: ";
		cin >> notes[num].date2.day;
		while (notes[num].date2.day < 0 || notes[num].date2.day>31) {
			cout << "Ошибка\n";
			cin >> notes[num].date2.day;
		}
		cout << "Месяц: ";
		cin >> notes[num].date2.month;
		while (notes[num].date2.month < 0 || notes[num].date2.month>31) {
			cout << "Ошибка\n";
			cin >> notes[num].date2.month;
		}
		cout << "Год: ";
		cin >> notes[num].date2.year;
		while (notes[num].date2.year < 0 || notes[num].date2.year>31) {
			cout << "Ошибка\n";
			cin >> notes[num].date2.year;
		}

	cout << endl;
	num++;
	system("cls");
	Menu();
	cout << "Что дальше? ";
	cin >> mun.task;
	while (mun.task > '4' || mun.task < '1') {
		cout << "Ошибка\n";
		cin >> mun.task;
	}
}

void print() {

	cout << "вывод всех записей" << endl;

	for (int j = 0; j < num; j++) {
		cout << "Марка автомобиля: " << notes[j].marka << endl;
		cout << "Фамилия владельца: " << notes[j].surname << endl;
		cout << "Цвет: " << notes[j].color << endl;
		cout << "Серийный номер: " << notes[j].nomer << endl;
		cout << "Дата выпуска: " << notes[j].date1.year << notes[j].date1.month << notes[j].date1.day << endl;
		cout << "Тип кузова: " << notes[j].type << endl;
		cout<<"Дата последнего техосмотра: " << notes[j].date2.year << notes[j].date2.month << notes[j].date2.day << endl;
	}
	Menu();
	cout << "Что дальше? ";
	cin >> mun.task;
	while (mun.task > '4' || mun.task < '1') {
		cout << "Ошибка\n";
		cin >> mun.task;
	}
}

void search() {

	bool found = false;
	cout << "Введите название для поиска: ";
	cin >> mun.surname;
	for (int j = 0; j < num; j++) {
		if (mun.surname == notes[j].surname) {
			found = true;
			cout << "Марка автомобиля: " << notes[j].marka << endl;
			cout << "Фамилия владельца: " << notes[j].surname << endl;
			cout << "Цвет: " << notes[j].color << endl;
			cout << "Серийный номер: " << notes[j].nomer << endl;
			cout << "Дата выпуска: " << notes[j].date1.year << notes[j].date1.month << notes[j].date1.day << endl;
			cout << "Тип кузова: " << notes[j].type << endl;
			cout << "Дата последнего техосмотра: " << notes[j].date2.year << notes[j].date2.month << notes[j].date2.day << endl;
		}
	}
	if (!found) {
		cout << "\nЗапись не найдена";
	}
	Menu();
	cout << "Что дальше? ";
	cin >> mun.task;
	while (mun.task > '4' || mun.task < '1') {
		cout << "Ошибка\n";
		cin >> mun.task;
	}
}
