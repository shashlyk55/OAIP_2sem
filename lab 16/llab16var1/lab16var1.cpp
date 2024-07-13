#include<iostream>
#include<ctime>
using namespace std;

void insertSort(int* A, int size)
{
	int t, i, j;
	for (i = 0; i < size; i++)
	{
		t = A[i];
		for (j = i - 1; j >= 0 && A[j] < t; j--)
			A[j + 1] = A[j];
		A[j + 1] = t;
	}
}


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
			if (B1[i] < B1[j]) {
				int temp;
				temp = B1[i];
				B1[i] = B1[j];
				B1[j] = temp;
			}
		}
	}
unsigned int end = clock();
	for (int i = 0; i < count; i++) {
		cout << B1[i] << " ";
	}
	
	int dif = end - start;
	cout << "\nВремя B1: " << dif << " мс\n";
	cout << endl;

	//Вставка
	cout << "\n\nVstavka B: \n";
	for (int i = 0; i < count; i++) {
		cout << B2[i] << " ";
	}
	cout << endl;
	start = clock();
	insertSort(B2,count);
	end = clock();
	dif = end - start;
	for (int i = 0; i < count; i++) {
		cout << B2[i] << " ";
	}
	cout << "\nВремя B2: " << dif << " мс\n";
	return 0;
}



