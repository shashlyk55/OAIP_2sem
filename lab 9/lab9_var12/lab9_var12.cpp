
//deleteX (int x) – функция удаления первого встречающегося элемента с заданным значением x.	

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
	cout << "1. Добавить значение" << endl;
	cout << "2. Удаление" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Запись в файл" << endl;
	cout << "6. Чтение из файла" << endl;
	cout << "7. Выход" << endl;
	cout << "Что дальше?" << endl;
	cin >> task;
	return task;
}
//-----------------------------------------------------------
void insert(node* e, node** phead, node** plast) //Добавление в конец списка
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
node* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	node* temp = new node();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти";
		return NULL;
	}
	cout << "Введите значение элемента ";
	cin >> temp->info;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(node** phead, node** plast)      //Вывод списка на экран
{
	node* t = *phead;
	while (t)
	{
		cout << t->info << ' ';
		t = t->next;
	}
}
//-----------------------------------------------------------
void find(node** phead)    // Поиск имени в списке
{
	node* t = *phead;
	int num;
	cout << "Введите число, которое хотите найти\n";
	cin >> num;
	while (t)
	{
		if (num == t->info) break;
		t = t->next;
	}
	if (!t)
		cout << "Значение не найдено" << endl;
	else
		cout << t->info << endl;
}
//-----------------------------------------------------------
void deleteX(node** phead, node** plast){
	node* t = *phead;
	int num;
	cout << "Введите число, которое хотите удалить\n";
	cin >> num;
	while (t)
	{
		if (num == t->info)  break;
		t = t->next;
	}
	if (!t)
	cerr << "Имя не найдено" << endl;
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
		cout << "Элемент удален" << endl;
	}
}
//-----------------------------------------------------------
void writeToFile(node** phead)       //Запись в файл
{
	struct node* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct node), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------
void readFromFile(node** phead, node** plast)          //Считывание из файла
{
	struct node* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new node();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
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
