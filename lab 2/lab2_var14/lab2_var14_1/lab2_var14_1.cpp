#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<iostream>

using namespace std;
int main() {
	FILE* pf1;
	pf1 = fopen("test.txt", "w");

	FILE* pf2;
	pf2 = fopen("test2.txt", "w");

	int k, n;
	cout << "size: ";
	cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	fprintf(pf1, "%d\n", n);
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fprintf(pf1, "%d ", arr[i][j] = rand() % 10);
		}
		fprintf(pf1, "\n");
		cout << endl;
	}

	cout << "\ncolumn k: ";
	cin >> k;
	fprintf(pf2, "%d\n", k);

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	fclose(pf1);

	pf1 = fopen("test.txt", "r");

	int x;
	fscanf_s(pf1, "%d", &x);
	int** arr2 = new int* [x];
	for (int i = 0; i < x; i++)
		arr2[i] = new int[x];
	for (int i = 0; i < x; i++)
		for (int j = 0; j < x; j++) {
			fscanf_s(pf1, "%d", &(arr2[i][j]));
		}


	for (int i = 0; i < x; i++) {
		fprintf(pf2, "\n%d", arr2[i][k - 1]);
	}

	for (int i = 0; i < n; i++) {
		delete[] arr2[i];
	}
	delete[] arr2;

	fclose(pf2);
	fclose(pf1);

	return 0;
}


