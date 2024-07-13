#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
using namespace std;

void main() {
	srand(time(NULL));
	FILE* pff = fopen("fileF.txt", "w");

	int size;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
		printf("%d ", arr[i]);
		fprintf(pff, "%d ", arr[i]);
	}
	delete[] arr;
	fclose(pff);

	FILE* pfg = fopen("fileG.txt", "w");
	pff = fopen("fileF.txt", "r");
	int* buf = new int[size],* arr2 = new int[size];
	int count = 0;

	cout << endl;
	for (int i = 0; i < size; i++) {
		fscanf_s(pff, "%d ", &buf[i]);
	}
	int i = 0, k = 0;
	for (i = 0; i < size; i++) {
		for (k = 0; k < i; k++) {
			if (buf[i] == buf[k]) {
				count++;
			}
		}
		if (count == 0) {
			printf("%d ", buf[i]);
			fprintf(pfg, "%d ", buf[i]);
		}
		count = 0;
	}

	delete[] arr2;
	delete[] buf;
	fclose(pff);
	fclose(pfg);
}
