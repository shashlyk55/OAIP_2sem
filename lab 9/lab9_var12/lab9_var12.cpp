
//deleteX (int x) � ������� �������� ������� �������������� �������� � �������� ��������� x.	

#include <iostream>
#include <fstream>
using namespace std;
int task;

struct node
{
	int info;
	node* next;
	node* prev;
};
//-----------------------------------------------------------
int menu(void)
{
	cout << endl;
	cout << "1. �������� ��������" << endl;
	cout << "2. ��������" << endl;
	cout << "3. ����� �� �����" << endl;
	cout << "4. �����" << endl;
	cout << "5. ������ � ����" << endl;
	cout << "6. ������ �� �����" << endl;
	cout << "7. �����" << endl;
	cout << "��� ������?" << endl;
	cin >> task;
	return task;
}
//-----------------------------------------------------------
void insert(node* e, node** phead, node** plast) //���������� � ����� ������
{
	node* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
node* setElement()      // �������� �������� � ���� ��� �������� � ���������� 
{
	node* temp = new node();
	if (!temp)
	{
		cerr << "������ ��������� ������";
		return NULL;
	}
	cout << "������� �������� �������� ";
	cin >> temp->info;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(node** phead, node** plast)      //����� ������ �� �����
{
	node* t = *phead;
	while (t)
	{
		cout << t->info << ' ';
		t = t->next;
	}
}
//-----------------------------------------------------------
void find(node** phead)    // ����� ����� � ������
{
	node* t = *phead;
	int num;
	cout << "������� �����, ������� ������ �����\n";
	cin >> num;
	while (t)
	{
		if (num == t->info) break;
		t = t->next;
	}
	if (!t)
		cout << "�������� �� �������" << endl;
	else
		cout << t->info << endl;
}
//-----------------------------------------------------------
void deleteX(node** phead, node** plast){
	node* t = *phead;
	int num;
	cout << "������� �����, ������� ������ �������\n";
	cin >> num;
	while (t)
	{
		if (num == t->info)  break;
		t = t->next;
	}
	if (!t)
	cerr << "��� �� �������" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "������� ������" << endl;
	}
}
//-----------------------------------------------------------
void writeToFile(node** phead)       //������ � ����
{
	struct node* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	cout << "���������� � ����" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct node), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------
void readFromFile(node** phead, node** plast)          //���������� �� �����
{
	struct node* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "�������� �� �����" << endl;
	while (!feof(fp))
	{
		t = new node();
		if (!t)
		{
			cerr << "������ ��������� ������" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct node), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}



int main(void)
{
	node* head = NULL;
	node* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	int a;
	while (true)
	{
		switch (menu())
		{
		case 1:  
			insert(setElement(), &head, &last);
			break;
		case 2: 
			deleteX(&head, &last);
			break;
		case 3:  
			outputList(&head, &last);
			break;
		case 4: 
			find(&head);
			break;
		case 5:
			writeToFile(&head);
			break;
		case 6:
			readFromFile(&head, &last);
			break;
		case 7:  exit(2);
		default: exit(1);
		}
	}
	return 0;
}
