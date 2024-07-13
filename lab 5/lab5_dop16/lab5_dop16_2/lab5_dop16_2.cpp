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
// Функция меню
void Menu() {
	cout << "\n1-Добавление записи\n";
	cout << "2-Вывод записей\n";
	cout << "3-Поиск по среднему баллу\n";
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
	cout << "ФИО:\n";
	do {
		cout << "Фамилия: ";
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

	cout << "Дата поступления: ";
	cout << "День: ";
	cin >> notes[num].data.day;
	while (notes[num].data.day < 0 || notes[num].data.day>31) {
		cout << "Ошибка\n";
		cin >> notes[num].data.day;
	}
	cout << "Месяц: ";
	cin >> notes[num].data.month;
	while (notes[num].data.month < 0 || notes[num].data.month>12) {
		cout << "Ошибка\n";
		cin >> notes[num].data.month;
	}
	cout << "Год: ";
	cin >> notes[num].data.year;
	while (notes[num].data.year < 0 || notes[num].data.year>9999) {
		cout << "Ошибка\n";
		cin >> notes[num].data.year;
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
		cout<<"Ошибка\n";
		cin >> notes[num].group;
	}

	do {
		cout << "Факультет: ";
		getchar();
		getline(cin, notes[num].fac);
		flag = false;
		for (int j = 0; notes[num].fac[j] != '\0'; j++) {
			if ((notes[num].fac[j] < 'а' || notes[num].fac[j] > 'я') && (notes[num].fac[j] > 'Я' || notes[num].fac[j] < 'А') && notes[num].fac[j] != ' ') {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);

	
	cout << "Средний балл: ";
	cin >> notes[num].mark;
	while (notes[num].mark < 0.0 || notes[num].mark>10.0) {
		cout << "ОШибка\n";
		cin >> notes[num].mark;
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

	cout << "вывод всех контактов" << endl;

	for (int j = 0; j < num; j++) {
		cout << "ФИО: " << notes[j].surname << notes[j].name << notes[j].otch << endl;
		cout << "Дата поступления: " << notes[j].data.day << notes[j].data.month << notes[j].data.year << endl;
		cout << "Группа: " << notes[j].group << endl;
		cout << "Факультет: " << notes[j].fac << endl;
		cout << "Средний балл: " << notes[j].mark << endl;
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
	cout << "Введите средний балл для поиска: ";
	cin >> mun.ball;
	for (int j = 0; j < num; j++) {
		if (mun.ball == notes[j].mark) {
			found = true;
			cout << "ФИО: " << notes[j].surname << notes[j].name << notes[j].otch << endl;
			cout << "Дата поступления: " << notes[j].data.day << notes[j].data.month << notes[j].data.year << endl;
			cout << "Группа: " << notes[j].group << endl;
			cout << "Факультет: " << notes[j].fac << endl;
			cout << "Средний балл: " << notes[j].mark << endl;
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
