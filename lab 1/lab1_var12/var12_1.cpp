#include<iostream>
using namespace std;

void change(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void printArr(int array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
}

void sdvig(int array[],int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		if (array[i] < 0) {
			int temp = array[i] = 0, count = 0;
			count++;
			for (int j = i; j < sizeArr; j++) {
				array[j] = array[j + 1];
			}
			array[sizeArr - count] = temp;
			i--;
		}
	}
}

void func(int n,int first, ...) {
	int find = 0, size = n;
	int* ptr = &first;
	int* arr = new int[n];
	for (int i = 0; size;size--,i++) {
		arr[i] = *ptr;
		ptr++;
		if (arr[i] < 0) {
			find++;
		}
	}
	size = n;
	printArr(arr, size);
	if (find) {
		cout << endl << "there are negative elements" << endl;
		sdvig(arr, size);
	}
	else
		cout << endl << "there are no negative elements" << endl;
	printArr(arr, size);
}

void main() {
	func(5, 6, -3, 8, -9, 3);
	cout << endl << endl;
	func(10, 7, 0, -4, -1, 5, 345, -23, 93, 0, -5);
	cout << endl << endl;
	func(13, 6, 7, -8, -9, 0, -5, 3, -2, -5, -4, 2, 0, 9);

}