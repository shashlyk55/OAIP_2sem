#include<iostream>
#include"Tree.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	int task, a;
	Branch* Root = NULL;

	while (true) {
		menu();
		cin >> task;
		switch (task) {
		case 1:
			cout << "Введите значение: ";
			cin >> a;
			Add(a, Root);
			break;
		case 2:
			if (Root->Data >= 0)
			{
				print(Root);
			}
			else cout << "Дерево пустое\n";
			break;
		case 3:
			int src;
			Branch* b;
			cout << "Введите элемент: ";
			cin >> src;
			b = search(Root, src);
			if (b == 0) {
				cout << "Нет такого элемента\n";
				break;
			}
			cout << "Найден элемент: " << b->Data << endl;
			break;
		case 4:
			int a;
			cout << "Удаляемый узел: ";
			cin >> a;
			deleteNode(Root, a);
			break;
		case 5:
			cout << "Количество четных узлов: " << counting(Root) << endl;
			break;
		case 6:
			deleteTree(Root);
			break;
		case 7:
			inOrderTraversal(Root);
			cout << endl;
			break;
		case 8:
			preOrderTraversal(Root);
			cout << endl;
			break;
		case 9:
			if (isBalanced(Root)) {
				cout << "Дерево сбалансировано" << endl;
			}
			else
				cout << "не сбалансировано" << endl;
			break;
		case 0:
			exit(1);
		}

	}
	return 0;
}