
#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;
//Записная книжка.Ф.И.О, дата рождения, адрес, телефон, место работы или учебы, должность.Поиск по фамилии.
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

// Функция меню
void Menu() {
	cout << "\n1-Добавление контакта\n";
	cout << "2-Вывод всех контактов\n";
	cout << "3-Поиск по фамилии\n";
	cout << "4-Выход\n";
	cout << "Что будем делать? ";
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

// Функция для ввода даты
void InputDate(Date& date) {
	
	cout << "Введите день: ";
	cin >> date.day;
	while ((date.day[0] < '0' || date.day[0]>'3') || (date.day[1] < '0' || date.day[1]>'9') || (date.day[0] == '3' && date.day[1] > '1')) {
		cout << "Ошибка\n";
		cin >> date.day;
	}
	cout << "Введите месяц: ";
	cin >> date.month;
	while ((date.month[0] < '0' || date.month[0]>'1') || ((date.month[0] == '1' && (date.month[1] < '0' || date.month[1]>'2')) || (date.month[0] == '0' && (date.month[1] < '1' || date.month[1]>'9'))) ){
		cout << "Ошибка\n";
		cin >> date.month;
	}
	cout << "Введите год: ";
	cin >> date.year;
	do {
		for (int i = 0; i < 4; i++) {
			if (date.year[i] < '0' || date.year[i]>'9') {
				cout << "Ошибка\n";
				flag = true;
				break;
			}
		}
	} while (flag);
	flag = false;
}

// Функция для ввода экзамена
void InputContact(contact& cont) {
	do {
		cout << "Введите фамилию: ";
		getchar();
		getline(cin, cont.surname);
		flag = false;
		for (int j = 0; cont.surname[j] != '\0'; j++) {
			if ((cont.surname[j] < 'а' || cont.surname[j] > 'я') && (cont.surname[j] > 'Я' || cont.surname[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "Введите имя: ";
		getchar();
		getline(cin, cont.name);
		flag = false;
		for (int j = 0; cont.name[j] != '\0'; j++) {
			if ((cont.name[j] < 'а' || cont.name[j] > 'я') && (cont.name[j] > 'Я' || cont.name[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "Введите отчество: ";
		getchar();
		getline(cin, cont.otch);
		flag = false;
		for (int j = 0; cont.otch[j] != '\0'; j++) {
			if ((cont.otch[j] < 'а' || cont.otch[j] > 'я') && (cont.otch[j] > 'Я' || cont.otch[j] < 'А')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	//InputDate(cont.date);

	cout << "Введите день: ";
	cin >> cont.date.day;
	while ((cont.date.day[0] < '0' || cont.date.day[0]>'3') || (cont.date.day[1] < '0' || cont.date.day[1]>'9') || (cont.date.day[0] == '3' && cont.date.day[1] > '1')) {
		cout << "Ошибка\n";
		cin >> cont.date.day;
	}
	cout << "Введите месяц: ";
	cin >> cont.date.month;
	while ((cont.date.month[0] < '0' || cont.date.month[0]>'1') || ((cont.date.month[0] == '1' && (cont.date.month[1] < '0' || cont.date.month[1]>'2')) || (cont.date.month[0] == '0' && (cont.date.month[1] < '1' || cont.date.month[1]>'9')))) {
		cout << "Ошибка\n";
		cin >> cont.date.month;
	}
	cout << "Введите год: ";
	cin >> cont.date.year;
	do {
		for (int i = 0; i < 4; i++) {
			if (cont.date.year[i] < '0' || cont.date.year[i]>'9') {
				cout << "Ошибка\n";
				flag = true;
				break;
			}
		}
	} while (flag);
	flag = false;

	do {
		cout << "Введите адрес: ";
		getchar();
		getline(cin, cont.adres);
		flag = false;
		for (int j = 0; cont.adres[j] != '\0'; j++) {
			if ((cont.adres[j] < 'а' || cont.adres[j] > 'я') && (cont.adres[j] > 'Я' || cont.adres[j] < 'А') && cont.adres[j] != ' ' && (cont.adres[j] < '0' || cont.adres[j]>'9')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "Телефон: ";
		getchar();
		getline(cin, cont.adres);
		flag = false;
		for (int j = 0; cont.tel[j] != '\0'; j++) {
			if (cont.tel[j] < '0' || cont.tel[j]>'9') {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "Место работы: ";
		getchar();
		getline(cin, cont.place);
		flag = false;
		for (int j = 0; cont.place[j] != '\0'; j++) {
			if ((cont.place[j] < 'а' || cont.place[j] > 'я') && (cont.place[j] > 'Я' || cont.place[j] < 'А') && cont.place[j] != ' ' && (cont.place[j] < '0' || cont.place[j]>'9')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	do {
		cout << "Должность: ";
		getchar();
		getline(cin, cont.job);
		flag = false;
		for (int j = 0; cont.job[j] != '\0'; j++) {
			if ((cont.job[j] < 'а' || cont.job[j] > 'я') && (cont.job[j] > 'Я' || cont.job[j] < 'А') && cont.job[j] != ' ' && (cont.job[j] < '0' || cont.job[j]>'9')) {
				flag = true;
				cout << "Ошибка\n";
				break;
			}
		}
	} while (flag);
	Menu();
	cin >> stateMenu;
	while (stateMenu > '4' || stateMenu < '1') {
		cout << "Ошибка\n";
		cin >> stateMenu;
	}
}

//Функция для вывода контакта
void OutputContact(contact& cont) {
	cout << "Фамилия: " << cont.surname << endl;
	cout << "Имя: " << cont.name << endl;
	cout << "Отчество: " << cont.otch << endl;
	cout << "Дата рождения(ДДММГГГГ): " << cont.date.day << endl;
	cout << "Адрес: " << cont.adres << endl;
	cout << "Телефон: " << cont.tel << endl;
	cout << "Место работы: " << cont.place << endl;
	cout << "Должность: " << cont.job << endl;
}

// Функция для вывода всех контактов
void OutputAllContacts(contact* cont, int size) {
	for (int i = 0; i < size; i++) {
		OutputContact(cont[i]);
		cout << endl;
	}
	Menu();
	cin >> stateMenu;
	while (stateMenu > '4' || stateMenu < '1') {
		cout << "Ошибка\n";
		cin >> stateMenu;
	}
}

// Функция для поиска по фамилии
void SearchContactBySurname(contact* cont, int size) {
	string surname;
	cout << "Введите фамилию: ";
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
		cout << "Ошибка\n";
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
		cout << "Ошибка\n";
		cin >> stateMenu;
	}
	while (true) {
		switch (stateMenu) {
			cin >> stateMenu;
			while (stateMenu > '4' || stateMenu < '1') {
				cout << "Ошибка\n";
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