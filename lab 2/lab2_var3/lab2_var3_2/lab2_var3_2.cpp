#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int size;
	cin >> size;
	srand(time(NULL));
	FILE* pfa = fopen("nameA.txt", "w");
	int* a = new int[size];
	for (int i = 0; i < size; i++) {
		a[i] = rand() % 10;
		cout << a[i] << ' ';
		fprintf(pfa, "%d ", a[i]);
	}
	cout << endl;
	fprintf(pfa, "\n");
	delete[] a;
	fclose(pfa);

	FILE* pfb = fopen("nameB.txt", "w");
	int* b = new int[size];
	for (int i = 0; i < size; i++) {
		b[i] = rand() % 10;
		cout << b[i] << ' ';
		fprintf(pfb, "%d ", b[i]);
	}
	fprintf(pfb, "\n");
	cout << endl;
	delete[] b;
	fclose(pfb);

	FILE* pfc = fopen("nameC.txt", "w");
	int* c = new int[size];
	for (int i = 0; i < size; i++) {
		c[i] = rand() % 10;
		cout << c[i] << ' ';
		fprintf(pfc, "%d ", c[i]);
	}
	fprintf(pfc, "\n");
	cout << endl;
	delete[] c;
	fclose(pfc);

	FILE* pfd = fopen("nameD.txt", "w");
	int* d1 = new int[size];
	int* d2 = new int[size];
	int* d3 = new int[size];

	pfa = fopen("nameA.txt", "r");
	for (int i = 0; i < size; i++) {
		fscanf_s(pfa, "%d", &d1[i]);
	}

	pfb = fopen("nameB.txt", "r");
	for (int i = 0; i < size; i++) {
		fscanf_s(pfb, "%d", &d2[i]);
	}

	pfc = fopen("nameC.txt", "r");
	for (int i = 0; i < size; i++) {
		fscanf_s(pfc, "%d", &d3[i]);
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		printf("%d %d %d ", d1[i], d2[i], d3[i]);
		fprintf(pfd, "%d %d %d ", d1[i], d2[i], d3[i]);
	}
	delete[] d1;
	delete[] d2;
	delete[] d3;
	fclose(pfa);
	fclose(pfb);
	fclose(pfc);
	fclose(pfd);
}