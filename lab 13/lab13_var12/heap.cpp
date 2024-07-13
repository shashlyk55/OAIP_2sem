#include "heap.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

void AAA::print()
{
	std::cout << x;
}
int AAA::getPriority() const
{
	return x;
}
namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
	void Heap::scan(int i) const     //Вывод значений элементов на экран
	{
		int probel = 14;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 9) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
			if (u == 14) {
				std::cout << std::endl;
			}
		}
		std::cout << '\n';
	}
	void* Heap::extractMin() {
		void* rc = nullptr;
		if (!isEmpty())
		{
			//void *min = storage[0];
			//int minI = 0;
			//for (int i = 0; i < size; i++) {
			//	if ((int*)min > (int*)storage[i]) {
			//		//min = storage[i];
			//		minI = i;
			//	}
			//}
			//rc = extractI(minI);
			//rc = min;
			//storage[minI] = storage[size - 1];
			rc = findMin();
			storage[findMinIndex()] = storage[size - 1];
			size--;
			heapify(0);
		} 
		return rc;
	}
	void* Heap::extractI(int i) {
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[i];
			storage[i] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
	void* Heap::findMin() {

		// Первый элемент является минимальным изначально
		void* minElement = storage[0];

		// Ищем минимальный элемент в куче
		for (int i = 1; i < size; i++) {
			if (*reinterpret_cast<int*>(storage[i]) < *reinterpret_cast<int*>(minElement))
				minElement = storage[i];
		}

		return minElement;
	}

	int Heap::findMinIndex() {
		int minIndex = 0;  // Индекс минимального элемента изначально равен 0

		// Ищем минимальный элемент в куче
		for (int i = 1; i < size; i++) {
			if (*reinterpret_cast<int*>(storage[i]) < *reinterpret_cast<int*>(storage[minIndex]))
				minIndex = i;
		}

		return minIndex;
	}
	//void* Heap::printHeap(void* arr[], int n, int i = 0, int level = 0) {
	//	if (i >= n) return 0; // если индекс выходит за границы массива, выходим из функции
	//	printHeap(arr, n, 2 * i + 2, level + 1); // обходим правое поддерево
	//	for (int j = 0; j < level; j++) {
	//		std::cout << "    "; // выводим отступы для текущего уровня
	//	}
	//	std::cout << arr[i] << std::endl; // выводим значение текущей вершины
	//	printHeap(arr, n, 2 * i + 1, level + 1); // обходим левое поддерево
	//	return 0;
	//}

}
