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

void print(void* b)       //Функция используется при выводе 
{
	Country* a = (Country*)b;
	cout << a->name << "\t" << a->capital << a->people << "\t" << a->square << "\t" << a->president << "\n";
}

int task, num = 0;

void menu() {
	cout << "Введите: " << endl
		<< "1 - добавить элемент" << endl
		<< "2 - вывод списка" << endl
		<< "3 - удалить элемент" << endl
		<< "4 - поиск элемента" << endl
		<< "5 - удаление списка" << endl
		<< "6 - подсчет элементов списка" << endl
		<< "7 - выход" << endl;
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
			cout << "Название страны: ";
			getchar();
			getline(cin, a.name);
			cout << "Столица: ";
			getchar();
			getline(cin, a.capital);
			cout << "Фамилия президента: ";
			cin >> a.president;
			cout << "Площадь страны(тыс. кв. км): ";
			cin >> a.square;
			cout << "Численность населения(тыс. чел.): ";
			cin >> a.people;
			L1.Insert(&a); 
		}
			break;
		case 2:L1.PrintList(print);
			break;
		case 3:rc = L1.Delete(&a);
			if (rc == true) cout << "Удален элемент" << endl;
			break;
		case 4:
			e = L1.Search(&a);
			aa = (Country*)e->Data;
			cout << "Найден элемент = " << aa->name << endl;
			break;
		case 5:L1.DeleteList();
			break;
		case 6:
			cout << "Количество элементов в списке: " << L1.CountList() << endl;
			break;
		case 7:exit(1); 

		}
		cin >> task;
	}







	
	return 0;

	
}
