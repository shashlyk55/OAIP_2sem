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
void delNote();

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
		cout << "Название: ";
		getchar();
		getline(cin, notes[num].name);
		flag = false;
		for (int j = 0; notes[num].name[j] != '\0'; j++) {
			if ((notes[num].name[j] < 'а' || notes[num].name[j] > 'я') && (notes[num].name[j] > 'Я' || notes[num].name[j] < 'А')&& notes[num].name[j]!=' ') {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);

	do {
		cout << "Столица: ";
		getchar();
		getline(cin, notes[num].capital);
		flag = false;
		for (int j = 0; notes[num].capital[j] != '\0'; j++) {
			if ((notes[num].capital[j] < 'а' || notes[num].capital[j] > 'я') && (notes[num].capital[j] > 'Я' || notes[num].capital[j] < 'А')&& notes[num].capital[j]!=' ') {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);

	do {
		cout << "Фамилия президента: ";
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


	cout << "Численность населения(тыс. чел.): ";
	cin >> notes[num].county;
	while (notes[num].county < 0.0 || notes[num].county>9999999.0) {
		cout << "ОШибка\n";
		cin >> notes[num].county;
	}

	cout << "Площадь(тыс. км кв.): ";
	cin >> notes[num].square;
	while (notes[num].square < 0.0 || notes[num].square>9999999.0) {
		cout << "ОШибка\n";
		cin >> notes[num].square;
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
		cout << "Название: " << notes[j].name << endl;
		cout << "Столица: " << notes[j].capital << endl;
		cout << "Фамилия президента: " << notes[j].surname << endl;
		cout << "Численность населения: " << notes[j].county << endl;
		cout << "Площадь: " << notes[j].square << endl;
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

	mun.found = false;
	cout << "Введите название для поиска: ";
	getchar();
	getline(cin, country);
	for (int j = 0; j < num; j++) {
		if (country == notes[j].name) {
			mun.found = true;
			cout << "Название: " << notes[j].name << endl;
			cout << "Столица: " << notes[j].capital << endl;
			cout << "Фамилия президента: " << notes[j].surname << endl;
			cout << "Численность населения: " << notes[j].county << endl;
			cout << "Площадь: " << notes[j].square << endl;
		}
	}
	if (!mun.found) {
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
