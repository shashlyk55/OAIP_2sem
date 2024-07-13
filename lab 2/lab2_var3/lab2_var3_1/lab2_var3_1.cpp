#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<iostream>

using namespace std;
int main() {
	FILE* pf1;
	pf1 = fopen("test.txt", "w");

	int n;
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
	}

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	fclose(pf1);

	pf1 = fopen("test.txt", "r");
	FILE* pf2;
	pf2 = fopen("test2.txt", "w");

	int x;
	fscanf_s(pf1, "%d", &x);
	int** buf = new int* [x];
	for (int i = 0; i < x; i++)
		buf[i] = new int[x];

	int** transp = new int* [x];
	for (int i = 0; i < x; i++)
		transp[i] = new int[x];

	for (int i = 0; i < x; i++)
		for (int j = 0; j < x; j++) {
			fscanf_s(pf1, "%d", &(buf[i][j]));
		}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			fprintf(pf2, "%d ", transp[i][j] = buf[j][i]);
		}
		fprintf(pf2, "\n");
	}


	for (int i = 0; i < n; i++) {
		delete[] buf[i];
	}
	delete[] buf;

	for (int i = 0; i < n; i++) {
		delete[] transp[i];
	}
	delete[] transp;	

	fclose(pf2);
	fclose(pf1);

	return 0;
}


