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
		cout << "�������� �������:" << endl
			<< "1 - ���������� �������� � ����" << endl
			<< "2 - ���������� �������� �� �����" << endl
			<< "3 - ����� �����" << endl
			<< "4 - ������ ����� � ����" << endl
			<< "5 - ����� ����� �� �����" << endl
			<< "6 - �������� ����" << endl
			<< "7 - ���������� ����� �� 2" << endl
			<< "8 - �����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "������� �������: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "����������� �������: " << choice << endl;
			break;
		case 3: cout << "���� ����: " << endl;
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

