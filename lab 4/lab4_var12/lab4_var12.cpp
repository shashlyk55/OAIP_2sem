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
	cout << "Ввод информации" << endl;
	cout << "Номер страны: " << num + 1 << endl;
	info[num].number = num + 1;
	cout << "Название страны: ";
	cin >> info[num].name;
	cout << "Столица: ";
	cin >> info[num].capital;
	cout << "Фамилия президента: ";
	cin >> info[num].president;
	cout << "Площадь страны(тыс. кв. км): ";
	cin >> info[num].square;
	cout << "Численность населения(тыс. чел.): ";
	cin >> info[num].people;
	num++;
	system("cls");
	menu();
	cout << "Что дальше? ";
	cin >> task;
}

void menu() {
	cout << "Введите: " << endl
		<< "1 - добавить запись" << endl
		<< "2 - вывести на экран" << endl
		<< "3 - удалить запись" << endl
		<< "4 - поиск записи" << endl
		<< "5 - запись информации в файл" << endl
		<< "6 - чтение данных из файла" << endl
		<< "7 - выход" << endl;
}

void print() {
	cout << "1 - вывод 1 страны" << endl
		<< "2 - вывод всех стран" << endl;
	int sw, n;
	cin >> sw;
	switch(sw) {
	case 1:
		cout << "Номер страны " << endl;
		cin >> n;
		cout << "Название страны: " << info[n - 1].name << endl;
		cout << "Столица: " << info[n - 1].capital << endl;
		cout << "Фамилия президента: " << info[n - 1].president << endl;
		cout << "Площадь страны(тыс. кв. км): " << info[n - 1].square << endl;
		cout << "Численность населения(тыс. чел.): " << info[n - 1].people << endl;
		break;
	case 2:
		for (int j = 0; j < num; j++) {
			printf("Страна номер %d\n", j + 1);
			cout << "Название страны: " << info[j].name << endl;
			cout << "Столица: " << info[j].capital << endl;
			cout << "Фамилия президента: " << info[j].president << endl;
			cout << "Площадь страны(тыс. кв. км): " << info[j].square << endl;
			printf("Численность населения(тыс. чел.): %f\n\n", info[j].people);
		}break;
	}
	menu();
	cout << "Что дальше? ";
	cin >> task;
}

void delElem() {
	int d;
	cout << "\nНомер страны, которую надо удалить (для удаления всех строк нажать 99)" << endl;  
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
	cout << "Страна удалена из списка" << endl;
	menu();
	cout << "Что дальше?" << endl;
	cin >> task;
}

void search() {
	cout << "Поиск информации по названию страны." << endl
		<< "Введите название страны: ";
	char name[30];
	int position = -1;
	cin >> name;
	for (int i = 0; i < num; i++) {
		if (strcmp(info[i].name, name)==0) {
			position = i;
		}
	}
	if (position >= 0) {
		cout << "Найдено: " << endl;
		cout << "Название страны: " << info[position].name << endl;
		cout << "Столица: " << info[position].capital << endl;
		cout << "Фамилия президента: " << info[position].president << endl;
		cout << "Площадь страны(тыс. кв. км): " << info[position].square << endl;
		cout << "Численность населения(тыс. чел.): " << info[position].people << endl;
	}
	else
		cout << "Ничего не найдено" << endl;
	cout << "Что дальше? ";
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
		fout << "Страна номер " << j + 1 << endl;
		fout << "Название " << strct[j].name << endl;
		fout << "Столица " << strct[j].capital << endl;
		fout << "Президент " << strct[j].president << endl;
		fout << "Площадь " << strct[j].square << endl;
		fout << "Население " << strct[j].people << endl << endl;
	}
	fout.close();
	cout << "Что дальше? ";
	cin >> task;
}


void out_file()
{
	fin.open("data.txt");
	while (!fin.eof()) {
		getline(fin, str);
		cout << str << endl;
	}
	cout << "Что дальше? ";
	cin >> task;
	fin.close();
}