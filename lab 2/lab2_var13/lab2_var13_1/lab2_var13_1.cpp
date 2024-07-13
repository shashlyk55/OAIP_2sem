#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
using namespace std;

void main() {
	srand(time(NULL));
	FILE* pfa = fopen("fileA.txt", "w");
	
	int size, val = 10;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % val;
		printf("%d ", arr[i]);
		fprintf(pfa, "%d ", arr[i]);
	}
	delete[] arr;
	fclose(pfa);

	FILE* pfb = fopen("fileB.txt", "w");
	pfa = fopen("fileA.txt", "r");
	int* arr2 = new int[size];
	int count = 0;

	cout << endl;

	for (int i = 0; i < size; i++) {
		fscanf_s(pfa, "%d ", &arr2[i]);
	}
	for (int i = 0; i < val; i++) {
		for (int j = 0; j < size; j++) {
			if (i == arr2[j]) {
				count++;
			}
			if (count == 2) {
				fprintf(pfb, "%d ", arr2[j]);
				printf("%d ", arr2[j]);
				break;
			}
		}
		count = 0;
	}

	delete[] arr2;
	fclose(pfa);
	fclose(pfb);
}