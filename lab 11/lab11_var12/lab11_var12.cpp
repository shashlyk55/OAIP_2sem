#include <iostream>
using namespace std;

int c = 0;
int tabs = 0; 
//��������� �����
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

//������� ������ ������
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

void view(Branch* t, int level) //����� ������ 
{
	if (t)
	{
		view(t->RightBranch, level + 1);	//����� ������� ���������
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->Data;
		cout << tm << ' ';
		view(t->LeftBranch, level + 1);	//����� ������ ���������
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
	cout << "1-�������� �������" << endl
		<< "2-����� ������" << endl
		<< "3-����� ��������" << endl
		<< "4-�������� ��������" << endl
		<< "5-������� ������ �����" << endl
		<< "6-���������� �������(��� 7)" << endl
		<< "7-����� �������� �������(��� 16)" << endl
		<< "8-����� �������� ���� �����(��� 10)" << endl
		<< "9-������ ������" << endl
		<< "0-�����" << endl
		<< "��� ������?" << endl;
}

Branch* search(Branch* n, int a)  //����� �������� �� ����� 
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
		//cout << "��� ������ ��������\n";
		return 0;
	}
}



Branch* delElem(Branch* Root, int key)  //�������� �������� �� �����
{	// Del, Prev_Del - ��������� ������� � ��� ���������� ;
	// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
	Branch* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->Data != key)//����� �������� � ��� �������� 
	{
		Prev_Del = Del;
		if (Del->Data > key)
			Del = Del->LeftBranch;
		else
			Del = Del->RightBranch;
	}
	if (Del == NULL)              // ������� �� ������
	{
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->RightBranch == NULL) // ����� �������� R ��� ������
		R = Del->LeftBranch;
	else
		if (Del->LeftBranch == NULL)
			R = Del->RightBranch;
		else
		{
			Prev_R = Del; //����� ������ ������� �������� � ����� ���������
			R = Del->LeftBranch;
			while (R->RightBranch != NULL)
			{
				Prev_R = R;
				R = R->RightBranch;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
				R->RightBranch = Del->RightBranch;
			else
			{
				R->RightBranch = Del->RightBranch;
				Prev_R->RightBranch = R->LeftBranch;
				R->LeftBranch = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//�������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->Data < Prev_Del->Data)
			Prev_Del->LeftBranch = R; // �� ����� ����� 
		else
			Prev_Del->RightBranch = R;	// �� ������ �����
	int tmp = Del->Data;
	cout << "\n������ ������� � ������ " << tmp << endl;
	delete Del;
	return Root;
}

Branch* minValueNode(Branch* node) {
	Branch* current = node;

	// ����� ������ ������ ����
	while (current && current->LeftBranch != NULL) {
		current = current->LeftBranch;
	}
	return current;
}

Branch* deleteNode(Branch* root, int key) {
	// ������ ������
	if (root == NULL) {
		return root;
	}

	// ���� ���� ������, ��� �������� �������� ����, ���������� ���� � ����� ���������
	if (key < root->Data) {
		root->LeftBranch = deleteNode(root->LeftBranch, key);
	}
	// ���� ���� ������, ��� �������� �������� ����, ���������� ���� � ������ ���������
	else if (key > root->Data) {
		root->RightBranch = deleteNode(root->RightBranch, key);
	}
	// ���� ���� ����� �������� �������� ����, �� ��� ����, ������� ����� �������
	else {
		// ���� ��� �������� ��� ������ � ����� ��������
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
		// ���� � ����� ���������
		Branch* temp = minValueNode(root->RightBranch);
		root->Data = temp->Data;
		root->RightBranch = deleteNode(root->RightBranch, temp->Data);
	}
	return root;
}


void delAll(Branch* t) //������� ������
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
	if (root == nullptr) { // ���� ������ ������
		return 0;
	}
	else if (root->LeftBranch == nullptr && root->RightBranch == nullptr) { // ���� ���� �������� ������
		return 1;
	}
	else { // ���� ���� �� �������� ������, ��������� � ��� ��������
		return countLeaves(root->LeftBranch) + countLeaves(root->RightBranch);
	}
}

int sum(Branch* root) {
	if (root == nullptr) { // ���� ������ ������
		return 0;
	}
	else if (root->LeftBranch == nullptr && root->RightBranch == nullptr) { // ���� ���� �������� ������
		return root->Data;
	}
	else { // ���� ���� �� �������� ������, ��������� � ��� ��������
		return sum(root->LeftBranch) + sum(root->RightBranch);
	}
}
int sumUzl = 0;
void sumUzlov(Branch* t) {
	if (t)
	{
		sumUzlov(t->RightBranch);	//����� ������� ���������
		sumUzl += t->Data;
		sumUzlov(t->LeftBranch);	//����� ������ ���������
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
			cout << "���������� �������(��� 7): " << countLeaves(Root) << endl;
			break;
		case 7:
			cout << "����� �������(��� 16): " << sum(Root) << endl;
			break;
		case 8:
			sumUzlov(Root);
			cout << "����� �������� �����(��� 10)" << sumUzl << endl;
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