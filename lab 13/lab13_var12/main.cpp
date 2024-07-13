#include "heap.h"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
//void* printHeap(void* arr[], int n, int i = 0, int level = 0) {
//	if (i >= n) return; // если индекс выходит за границы массива, выходим из функции
//	printHeap(arr, n, 2 * i + 2, level + 1); // обходим правое поддерево
//	for (int j = 0; j < level; j++) {
//		cout << "    "; // выводим отступы для текущего уровня
//	}
//	cout << arr[i] << endl; // выводим значение текущей вершины
//	printHeap(arr, n, 2 * i + 1, level + 1); // обходим левое поддерево
//	return;
//}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	heap::Heap h3 = heap::create(30, cmpAAA);

	for (;;)
	{
		cout << "1 - вывод кучи на экран" << endl;
		cout << "2 - добавить элемент" << endl;
		cout << "3 - удалить максимальный элемент" << endl;
		cout << "0 - выход" << endl;
		cout << "4 - удалить минимальный" << endl
			<< "5 - удаление iтого элемента" << endl
			<< "6 - добавление элемента во 2 кучу" << endl
			<< "7 - вывод 2 кучи" << endl
			<< "8 - объединение 2 куч в одну" << endl;
		cout << "сделайте выбор" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  h1.scan(0);
			break;
		case 2: {	AAA* a = new AAA;
			cout << "введите ключ" << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 3:   h1.extractMax();
			break;
		case 4:
			h1.extractMin();
			break;
		case 5:
			int ind;
			cout << "индекс: ";
			cin >> ind;
			h1.extractI(ind);
			break;
		case 6:
		{	AAA* a = new AAA;
		cout << "введите ключ" << endl; 	cin >> k;
		a->x = k;
		h2.insert(a);
		}
		break;
		case 7:
			h2.scan(0);
			//printHeap(h2.storage, h2.size);
			break;
		case 8:
			for (int i = 0; i < h2.size; i++) {
				h1.insert(h2.storage[i]);
			}
			break;
		default:  cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}
