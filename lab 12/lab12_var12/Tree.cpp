#include"Tree.h"
#include<iostream>
using namespace std;

int tabs = 0;
int c = 0;

void menu() {
	cout << "1-добавить элемент" << endl
		<< "2-вывод дерева" << endl
		<< "3-поиск элемента" << endl
		<< "4-удаление элемента" << endl
		<< "5-подсчет четных узлов" << endl
		<< "6-чистка дерева" << endl
		<< "7-смешанный обход дерева(лкп)" << endl
		<< "8-прямой обход дерева(клп)" << endl
		<< "9-проверка на сблансированность" << endl
		<< "0-выход" << endl
		<< "Что делать?" << endl;
}

Branch* Add(int aData, Branch*& aBranch)
{
	if (aBranch == NULL)
	{
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->RightBranch = NULL;
		aBranch->LeftBranch = NULL;
		return aBranch;
	}

	if (aData > aBranch->Data) {

		aBranch->RightBranch = Add(aData, aBranch->RightBranch);
	}
	else if (aData < aBranch->Data) {

		aBranch->LeftBranch = Add(aData, aBranch->LeftBranch);
	}

	return aBranch;
}

void print(Branch* aBranch)
{

	if (aBranch) {
		tabs++;

		print(aBranch->RightBranch);

		for (int i = 0; i < tabs; i++) cout << "\t";
		cout << aBranch->Data << endl;


		print(aBranch->LeftBranch);

		tabs--;
	}
}

Branch* search(Branch* n, int a)
{
	Branch* rc = n;
	if (rc != NULL)
	{
		if (a < (a, n->Data))
			rc = search(n->RightBranch, a);
		else
			if (a > (a, n->Data))
				rc = search(n->LeftBranch, a);
		return rc;
	}
	else {
		cout << "Нет такого элемента\n";
		return 0;
	}
}

Branch* deleteNode(Branch* root, int key) {
	// Пустое дерево
	if (root == NULL) {
		return root;
	}

	// Если ключ меньше, чем значение текущего узла, рекурсивно ищем в левом поддереве
	if (key < root->Data) {
		root->LeftBranch = deleteNode(root->LeftBranch, key);
	}
	// Если ключ больше, чем значение текущего узла, рекурсивно ищем в правом поддереве
	else if (key > root->Data) {
		root->RightBranch = deleteNode(root->RightBranch, key);
	}
	// Если ключ равен значению текущего узла, то это узел, который нужно удалить
	else {
		// Узел без потомков или только с одним потомком
		if (root->LeftBranch == NULL) {
			Branch* temp = root->RightBranch;
			delete root;
			return temp;
		}
		else if (root->RightBranch == NULL) {
			Branch* temp = root->LeftBranch;
			delete root;
			return temp;
		}
		// Узел с двумя потомками
		Branch* temp = minValueNode(root->RightBranch);
		root->Data = temp->Data;
		root->RightBranch = deleteNode(root->RightBranch, temp->Data);
	}
	return root;
}

Branch* minValueNode(Branch* node) {
	Branch* current = node;

	// Поиск самого левого узла
	while (current && current->RightBranch != NULL) {
		current = current->RightBranch;
	}
	return current;
}

void deleteTree(Branch* node) {
	if (node != NULL)
	{
		deleteTree(node->RightBranch);
		deleteTree(node->LeftBranch);
		delete node;
	}
}

int counting(Branch* aBranch) {
	if (aBranch == NULL) {
		return 0;
	}
	int countLeft = counting(aBranch->RightBranch);
	int countRight = counting(aBranch->LeftBranch);


	if (aBranch->Data % 2 == 0) {

		return 1 + countLeft + countRight;
	}
	else {

		return countLeft + countRight;
	}

}

void inOrderTraversal(Branch* root) {
	if (root == NULL) return;
	inOrderTraversal(root->LeftBranch);
	cout << root->Data << " ";
	inOrderTraversal(root->RightBranch);
}

void preOrderTraversal(Branch* root) {
	if (root == NULL) return;
	cout << root->Data << " ";
	preOrderTraversal(root->LeftBranch);
	preOrderTraversal(root->RightBranch);
}

int checkHeight(Branch* node) {
	if (node == nullptr) {
		return 0;
	}
	int leftHeight = checkHeight(node->RightBranch);
	if (leftHeight == -1) {
		return -1;
	}
	int rightHeight = checkHeight(node->LeftBranch);
	if (rightHeight == -1) {
		return -1;
	}
	int heightDiff = abs(leftHeight - rightHeight);
	if (heightDiff > 1) {
		return -1;
	}
	else {
		return max(leftHeight, rightHeight) + 1;
	}
}

bool isBalanced(Branch* root) {
	return (checkHeight(root) != -1);
}
