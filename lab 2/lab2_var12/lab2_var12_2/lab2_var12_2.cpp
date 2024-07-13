#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int size;
	cin >> size;
	srand(time(NULL));
	FILE* fileA = fopen("nameA.txt", "w");
	int* a = new int[size];
	for (int i = 0; i < size; i++) {
		a[i] = rand() % 10;
		cout << a[i] << ' ';
		fprintf(fileA, "%d ", a[i]);
	}
	cout << endl;
	fprintf(fileA, "\n");
	delete[] a;
	fclose(fileA);

	FILE* fileB = fopen("nameB.txt", "w");
	int* b = new int[size];
	for (int i = 0; i < size; i++) {
		b[i] = rand() % 10;
		cout << b[i] << ' ';
		fprintf(fileB, "%d ", b[i]);
	}
	fprintf(fileB, "\n");
	cout << endl;
	delete[] b;
	fclose(fileB);

	FILE* fileC = fopen("nameC.txt", "w");
	int* c = new int[size];
	for (int i = 0; i < size; i++) {
		c[i] = rand() % 10;
		cout << c[i] << ' ';
		fprintf(fileC, "%d ", c[i]);
	}
	fprintf(fileC, "\n");
	cout << endl;
	delete[] c;
	fclose(fileC);

	FILE* fileD = fopen("nameD.txt", "w");
	int* d1 = new int[size];
	int* d2 = new int[size];
	int* d3 = new int[size];
	int* d = new int[size];

	fileA = fopen("nameA.txt", "r");
	for (int i = 0; i < size; i++) {
		fscanf_s(fileA, "%d", &d1[i]);
	}

	fileB = fopen("nameB.txt", "r");
	for (int i = 0; i < size; i++) {
		fscanf_s(fileB, "%d", &d2[i]);
	}

	fileC = fopen("nameC.txt", "r");
	for (int i = 0; i < size; i++) {
		fscanf_s(fileC, "%d", &d3[i]);
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (d1[i] <= d2[i] && d1[i] < d3[i]) {
			fprintf(fileD, "%d ", d1[i]);
			printf("%d ", d1[i]);
			continue;
		}
		if (d2[i] < d1[i] && d2[i] <= d3[i]) {
			fprintf(fileD, "%d ", d2[i]);
			printf("%d ", d2[i]);
			continue;
		}
		if (d3[i] < d2[i] && d3[i] <= d1[i]) {
			fprintf(fileD, "%d ", d3[i]);
			printf("%d ", d3[i]);
			continue;
		}
		if (d1[i] == d2[i] && d2[i] == d3[i] && d1[i] == d3[i]) {
			printf("%d ", d1[i]);
			fprintf(fileD, "%d ", d3[i]);
		}
		
		
	
	}
	delete[] d1;
	delete[] d2;
	delete[] d3;
	delete[] d;
	fclose(fileA);
	fclose(fileB);
	fclose(fileC);
	fclose(fileD);
}