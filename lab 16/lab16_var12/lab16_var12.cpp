#include<iostream>
using namespace std;
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int n, count = 0;
	cout << "size: ";
	cin >> n;
	int* A = new int[n];
	int* B1 = new int[count];
	int* B2 = new int[count];


	for (int i = 0; i < n; i++) {
		A[i] = rand() % 30;
		if (i % 2 == 0) {
			count++;
		}
		cout << A[i] << " ";
	}
	cout << "\n\n";
	for (int i = 0, j = 0; i < n; i += 2, j++) {
		B1[j] = A[i];
		
		cout << B1[j] << " ";
	}
	//Пузырики
	cout << "\n\nBubles B: \n";
	for (int i = 0; i < count; i++) {
		cout << B1[i] << " ";
		B2[i] = B1[i];
	}
	cout << endl;
	unsigned int start = clock();
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (B1[i] > B1[j]) {
				int temp;
				temp = B1[i];
				B1[i] = B1[j];
				B1[j] = temp;
			}
		}
	}

	for (int i = 0; i < count; i++) {
		cout << B1[i] << " ";
	}
	unsigned int end = clock();
	int dif = end - start;
	cout << "\nВремя B1: " << dif << " мс\n";
	cout << endl;

	//Выборка
	cout << "\n\nVyborka B: \n";
	for (int i = 0; i < count; i++) {
		cout << B2[i] << " ";
	}
	cout << endl;
	start = clock();
	int min, buf;
	for (int i = 0; i < count; i++) {
		min = i;

		for (int j = i + 1; j < count; j++)
			min = (B2[j] < B2[min]) ? j : min;

		if (i != min) {
			buf = B2[i];
			B2[i] = B2[min];
			B2[min] = buf;
		}
	}
	for (int i = 0; i < count; i++) {
		cout << B2[i] << " ";
	}
	end = clock();
	dif = end - start;
	cout << "\nВремя B2: " << dif << " мс\n";
	return 0;
}

