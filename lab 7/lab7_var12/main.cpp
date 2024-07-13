#include <iostream>
#include "myStack.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; 
	myStk->head = NULL;       
	for (;;) {
		cout << "Выберите команду:" << endl
			<< "1 - Добавление элемента в стек" << endl
			<< "2 - Извлечение элемента из стека" << endl
			<< "3 - Вывод стека" << endl
			<< "4 - Запись стека в файл" << endl
			<< "5 - Вывод стека из файла" << endl
			<< "6 - Очистить стек" << endl
			<< "7 - разделение стека на 2" << endl
			<< "8 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "Извлеченный элемент: " << choice << endl;
			break;
		case 3: cout << "Весь стек: " << endl;
			show(myStk);
			break;
		case 4:writeToFile(myStk);
			break;
		case 5:
			clear(myStk);
			readFromFile(myStk);
			break;
		case 6:clear(myStk);
			break;
		case 7:separation(myStk);
			break;
		case 8: return 0;
			break;
		}
	}
	return 0;
}

