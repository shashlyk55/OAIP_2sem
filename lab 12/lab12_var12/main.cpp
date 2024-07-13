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
			cout << "������� ��������: ";
			cin >> a;
			Add(a, Root);
			break;
		case 2:
			if (Root->Data >= 0)
			{
				print(Root);
			}
			else cout << "������ ������\n";
			break;
		case 3:
			int src;
			Branch* b;
			cout << "������� �������: ";
			cin >> src;
			b = search(Root, src);
			if (b == 0) {
				cout << "��� ������ ��������\n";
				break;
			}
			cout << "������ �������: " << b->Data << endl;
			break;
		case 4:
			int a;
			cout << "��������� ����: ";
			cin >> a;
			deleteNode(Root, a);
			break;
		case 5:
			cout << "���������� ������ �����: " << counting(Root) << endl;
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
				cout << "������ ��������������" << endl;
			}
			else
				cout << "�� ��������������" << endl;
			break;
		case 0:
			exit(1);
		}

	}
	return 0;
}