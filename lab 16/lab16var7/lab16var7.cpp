#include<iostream>
using namespace std;

void print(int arr[],int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int getHoarBorder(int A[], int em, int sm = 0)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] < brd);
		while (A[++i] > brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
int* sortHoar(int A[], int em, int sm = 0)
{

	if (sm < em)
	{
		int hb = getHoarBorder(A, em, sm);
		sortHoar(A, hb, sm);
		sortHoar(A, em, hb + 1);
	}
	return A;
}

void main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int size, n = 0;
	cout << "size = ";
	cin >> size;

	int* A = new int[size];
	int* B = new int[size];
	for (int i = 0; i < size; i++) {
		A[i] = rand() % 50;
		B[i] = rand() % 50;
	}
	cout << "A: \n";
	print(A, size);
	cout << endl << endl;
	cout << "B: \n";
	print(B, size);
	cout << endl << endl;

	for (int i = 0; i < size; i++) {
		if (A[i] % 2 == 0) {
			n++;
		}
		if (B[i] % 2 != 0) {
			n++;
		}
	}
	int* C1 = new int[n];
	int* C2 = new int[n];
	for (int i = 0,j=0; i < size; i++) {
		if (A[i] % 2 == 0) {
			C1[j] = A[i];
			C2[j] = A[i];
			j++;
		}
		if (B[i] % 2 != 0) {
			C1[j] = B[i];
			C2[j] = B[i];
			j++;
		}
	}
	print(C1, n);
	//пузырики
	cout << "\n\nBubles C1: \n";
	unsigned int start = clock();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (C1[i] < C1[j]) {
				int temp;
				temp = C1[i];
				C1[i] = C1[j];
				C1[j] = temp;
			}
		}
	}
	print(C1, n);
	
	unsigned int end = clock();
	int dif = end - start;
	cout << "\nВремя bubles: " << dif << " мс\n";
	cout << endl;

	//Хоар
	print(C2, n);
	cout << endl << endl;
	cout << "Hoar: ";
	start = clock();
	sortHoar(C2, n - 1);
	end = clock();
	dif = end - start;
	cout << endl;
	print(C2, n);
	cout << "\nВремя Hoar: " << dif << " мс\n";
}