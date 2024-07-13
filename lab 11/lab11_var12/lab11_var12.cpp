#include <iostream>
using namespace std;

int c = 0;
int tabs = 0; 
//Структура ветки
struct Branch
{
	int Data; 
	Branch* LeftBranch; 
	Branch* RightBranch;
};


Branch* Add(int aData, Branch*& aBranch)
{
	if (aBranch==NULL)
	{ 
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftBranch = NULL;
		aBranch->RightBranch = NULL;
		return aBranch;
	}
	
	if (aData < aBranch->Data) {
		
		aBranch->LeftBranch = Add(aData, aBranch->LeftBranch);
	}
	else if (aData > aBranch->Data) {
		
		aBranch->RightBranch = Add(aData, aBranch->RightBranch);
	}
	
	return aBranch;  
}

//Функция вывода дерева
void print(Branch* aBranch)
{
	
	if (aBranch) {
		tabs++;

		print(aBranch->LeftBranch);

		for (int i = 0; i < tabs; i++) cout << "\t";
		cout << aBranch->Data << endl;


		print(aBranch->RightBranch);

		tabs--;
	}
}

void view(Branch* t, int level) //Вывод дерева 
{
	if (t)
	{
		view(t->RightBranch, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->Data;
		cout << tm << ' ';
		view(t->LeftBranch, level + 1);	//вывод левого поддерева
	}
}

void deleteTree(Branch* node) {
	if (node != NULL)
	{
		deleteTree(node->LeftBranch);
		deleteTree(node->RightBranch);
		delete node;
	}
}


void FreeTree(Branch* aBranch)
{
	if (aBranch!=NULL) {
		FreeTree(aBranch->LeftBranch);
		FreeTree(aBranch->RightBranch);
		delete aBranch;
		aBranch = NULL;
	}
}

void menu() {
	cout << "1-добавить элемент" << endl
		<< "2-вывод дерева" << endl
		<< "3-поиск элемента" << endl
		<< "4-удаление элемента" << endl
		<< "5-подсчет четных узлов" << endl
		<< "6-количество листьев(доп 7)" << endl
		<< "7-сумма значений листьев(доп 16)" << endl
		<< "8-сумма значений всех узлов(доп 10)" << endl
		<< "9-чистка дерева" << endl
		<< "0-выход" << endl
		<< "Что делать?" << endl;
}

Branch* search(Branch* n, int a)  //Поиск элемента по ключу 
{
	Branch* rc = n;
	if (rc != NULL)
	{
		if (a < (a, n->Data))
			rc = search(n->LeftBranch, a);
		else
			if (a > (a, n->Data))
				rc = search(n->RightBranch, a);
		return rc;
	}
	else {
		//cout << "Нет такого элемента\n";
		return 0;
	}
}



Branch* delElem(Branch* Root, int key)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Branch* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->Data != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->Data > key)
			Del = Del->LeftBranch;
		else
			Del = Del->RightBranch;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->RightBranch == NULL) // поиск элемента R для замены
		R = Del->LeftBranch;
	else
		if (Del->LeftBranch == NULL)
			R = Del->RightBranch;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->LeftBranch;
			while (R->RightBranch != NULL)
			{
				Prev_R = R;
				R = R->RightBranch;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->RightBranch = Del->RightBranch;
			else
			{
				R->RightBranch = Del->RightBranch;
				Prev_R->RightBranch = R->LeftBranch;
				R->LeftBranch = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->Data < Prev_Del->Data)
			Prev_Del->LeftBranch = R; // на левую ветвь 
		else
			Prev_Del->RightBranch = R;	// на правую ветвь
	int tmp = Del->Data;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}

Branch* minValueNode(Branch* node) {
	Branch* current = node;

	// Поиск самого левого узла
	while (current && current->LeftBranch != NULL) {
		current = current->LeftBranch;
	}
	return current;
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


void delAll(Branch* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->LeftBranch);
		delAll(t->RightBranch);
		delete t;
	}
}


int counting(Branch* aBranch) {
	if (aBranch == NULL) {
		return 0;
	}
	int countLeft = counting(aBranch->LeftBranch);
	int countRight = counting(aBranch->RightBranch);

	
	if (aBranch->Data % 2 == 0) {
		
		return 1 + countLeft + countRight;
	}
	else {
		
		return countLeft + countRight;
	}
	
}

int countLeaves(Branch* root) {
	if (root == nullptr) { // если дерево пустое
		return 0;
	}
	else if (root->LeftBranch == nullptr && root->RightBranch == nullptr) { // если узел является листом
		return 1;
	}
	else { // если узел не является листом, переходим к его потомкам
		return countLeaves(root->LeftBranch) + countLeaves(root->RightBranch);
	}
}

int sum(Branch* root) {
	if (root == nullptr) { // если дерево пустое
		return 0;
	}
	else if (root->LeftBranch == nullptr && root->RightBranch == nullptr) { // если узел является листом
		return root->Data;
	}
	else { // если узел не является листом, переходим к его потомкам
		return sum(root->LeftBranch) + sum(root->RightBranch);
	}
}
int sumUzl = 0;
void sumUzlov(Branch* t) {
	if (t)
	{
		sumUzlov(t->RightBranch);	//вывод правого поддерева
		sumUzl += t->Data;
		sumUzlov(t->LeftBranch);	//вывод левого поддерева
	}
}

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
			cout << "Количество листьев(доп 7): " << countLeaves(Root) << endl;
			break;
		case 7:
			cout << "Сумма листьев(доп 16): " << sum(Root) << endl;
			break;
		case 8:
			sumUzlov(Root);
			cout << "сумма значений узлов(доп 10)" << sumUzl << endl;
			break;
		case 9:
			deleteTree(Root);
			break;
		case 0:
			exit(1);
		}

	}
	return 0;
}