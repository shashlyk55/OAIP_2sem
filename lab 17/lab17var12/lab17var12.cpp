#include<iostream>
using namespace std;
void vybor(int D[],int N) {
	int min, buf;
	for (int i = 0; i < N; i++) {
		min = i;

		for (int j = i + 1; j < N; j++)
			min = (D[j] < D[min]) ? j : min;

		if (i != min) {
			buf = D[i];
			D[i] = D[min];
			D[min] = buf;
		}
	}
}

int getHoarBorder(int A[], int em, int sm = 0)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] > brd);
		while (A[++i] < brd);
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

void heapify(int A[], int pos, int n)
{
	int t, tm;
	while (2 * pos + 1 < n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n && A[2 * pos + 2] >= A[t])
			t = 2 * pos + 2;
		if (A[pos] < A[t])
		{
			tm = A[pos];
			A[pos] = A[t];
			A[t] = tm;
			pos = t;
		}
		else break;
	}
}
void piramSort(int A[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		heapify(A, i, n);
	while (n > 0)
	{
		int tm = A[0];
		A[0] = A[n - 1];
		A[n - 1] = tm;
		n--;
		heapify(A, 0, n);
	}
}

void print(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	srand(time(NULL));
	unsigned int start, end;
	float time;
	int size;
	cout << "size: ";
	cin >> size;
	int* arr = new int[size];
	int* A = new int[size];
	int* B = new int[size];
	int* C = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 50;
		A[i] = arr[i];
		B[i] = arr[i];
		C[i] = arr[i];
	}
	print(arr, size);
	cout << endl << "sort" << endl << "Hoar: " << endl;
	start = clock();
	sortHoar(A, size - 1);
	end = clock();
	print(A, size);
	cout << endl << "sort time: " << end - start << " ms" << endl << endl;

	cout << "piramida: " << endl;
	start = clock();
	piramSort(B, size);
	end = clock();
	print(B, size);
	cout << endl << "sort time: " << end - start << " ms" << endl << endl;

	cout << "vybor: " << endl;
	start = clock();
	vybor(C, size);
	end = clock();
	print(C, size);
	cout << endl << "sort time: " << end - start << " ms" << endl << endl;

	return 0;
}