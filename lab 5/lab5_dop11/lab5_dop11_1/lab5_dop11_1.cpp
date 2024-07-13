#include<iostream>
#include<windows.h>
#include<string>
#define maxSize 20
using namespace std;

void menu();
void search();
void addNote();
void delNote();
void print();

struct Data {
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 12;
};

struct list {
	string surname;
	string product;
	string prise;
	string sum;
	Data date;
	int save;
	int number;
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
		case '1': addNote(); break;
		case '2': print(); break;
		case '3': delNote(); break;
		case '4': search(); break;
		case '5': exit(1); break;
		}
	}
}

void menu() {
	cout << "\n1 - добавить запись\n2 - вывод на экран\n3 - удаление записи\n4 - выбор записи\n5 - выход из программы\n";
}

int a;
void addNote() {
	cout << "Ввод информации" << endl;
	cout << "Номер: " << num + 1 << endl;
	list[num].number = num + 1;
	do {
		cout << "Фамилию: ";
		getchar();
		getline(cin, list[num].surname);
		flag = false;
		for (int j = 0; list[num].surname[j] != '\0'; j++) {
			if ((list[num].surname[j] < 'а' || list[num].surname[j] > 'я') && (list[num].surname[j] > 'Я' || list[num].surname[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	
	do {
		cout << "Название товара: ";
		getchar();
		getline(cin, list[num].product);
		flag = false;
		for (int j = 0; list[num].product[j] != '\0'; j++) {
			if ((list[num].product[j] < 'а' || list[num].product[j] > 'я') && (list[num].product[j] > 'Я' || list[num].product[j] < 'А') && list[num].product[j] != ' ') {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	cout << "Дата сдачи: ";
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
		cout << "Оценочная стоимость: ";
		getchar();
		getline(cin, list[num].prise);
		flag = false;
		for (int i = 0; list[num].prise[i] != '\0'; i++) {
			if ((list[num].prise[i] < '0' || list[num].prise[i]>'9') && list[num].prise[i] != '.') {
				flag = true;
				cout << "ОШибка\n";
				break;
			}
		}
	} while (flag);

	do {
		cout << "сумма, выданная под залог: ";
		getchar();
		getline(cin, list[num].sum);
		flag = false;
		for (int i = 0; list[num].sum[i] != '\0'; i++) {
			if ((list[num].sum[i] < '0' || list[num].sum[i]>'9') && list[num].sum[i] != '.') {
				flag = true;
				cout << "ОШибка\n";
				break;
			}
		}
	} while (flag);
				
	cout << "срок хранения(дни): ";
	//cout << "Дата сдачи: ";
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
	/*cin >> list[num].save;
	while (list[num].save < 0 || list[num].save>9999) {
		cout << "Ошибка\n";
		cin >> list[num].save;
	}*/

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

void delNote() {
	int d;
	cout << "\nНомер записи, которую надо удалить (для удаления всех нажать 99)" << endl;
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
	cout << "Запись удалена из списка" << endl;
	menu();
	cout << "Что дальше?" << endl;
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "Ошибка\n";
		cin >> task;
	}
}

void print() {
	cout << "вывод всех записей\n";
	
		for (int j = 0; j < num; j++) {
			cout << "Фамилия: " << list[j].surname << endl;
			cout << "Наименование товара: " << list[j].product << endl;
			cout << "Оценочная стоимость: " << list[j].prise << endl;
			cout << "Сумма, выданная под залог: " << list[j].sum << endl;
			cout << "Дата сдачи: " << list[j].date.day << "." << list[j].date.month << "." << list[j].date.year << endl;
			cout << "Срок храннения: " << list[j].save << '\n\n';
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
	int srok;
	bool found = false;
	cout << "Введите срок хранения(дни): ";
	cin >> srok;
	for (int j = 0; j < num; j++) {
		if (list[j].save >= srok) {
			found = true;
			cout << "Фамилия: " << list[j].surname << endl;
			cout << "Наименование товара: " << list[j].product << endl;
			cout << "Оценочная стоимость: " << list[j].prise << endl;
			cout << "Сумма, выданная под залог: " << list[j].sum << endl;
			cout << "Дата сдачи: " << list[j].date.day << "." << list[j].date.month << "." << list[j].date.year << endl;
			cout << "Срок храннения: " << list[j].save << '\n\n';
		}
		found = false;
	}
	if (!found) {
		cout << "\nЗапись не найдена";
	}
	menu();
	cout << "Что дальше? ";
	cin >> task;
	while (task > '4' || task < '1') {
		cout << "Ошибка\n";
		cin >> task;
	}
}