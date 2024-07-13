#include<iostream>
#include<ctime>
using namespace std;

void insertSort(int* A, int size)
{
	int t, i, j;
	for (i = 1; i < size; i++)
	{
		t = A[i];
		for (j = i - 1; j >= 0 && A[j] > t; j--)
			A[j + 1] = A[j];
		A[j + 1] = t;
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
		cout << A[i] << " ";
	}
	cout << "\n\n";
	for (int i = 0, j = 0,k=1; k < n; i++,k++) {
		if ((A[k] % 2 != 0) && (i % 2 == 0)) {
			B1[j] = A[i];
			j++;
			count++;
			//cout << B1[j] << " ";
		}
	}
	for (int i = 0; i < count; i++) {
		cout << B1[i] << " ";
		B2[i] = B1[i];
	}
	cout << endl << endl;
	//Хоар
	cout << "Hoar: ";
	for (int i = 0; i < count; i++) {
		cout << B1[i] << " ";
	}
	cout << endl;
	
	unsigned int start = clock();
	sortHoar(B1, count - 1);
	unsigned int end = clock();
	int dif = end - start;
	for (int i = 0; i < count; i++) {
		cout << B1[i] << " ";
	}
	cout << "\nВремя B2: " << dif << " мс\n";

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
			min = (B2[j] > B2[min]) ? j : min;

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
