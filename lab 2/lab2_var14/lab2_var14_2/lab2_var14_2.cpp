#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include<cstring>
#include<stdio.h>
using namespace std;

void main() {
	srand(time(NULL));
	FILE* pf1 = fopen("file1.txt", "w");
	bool write = 1;
	char str[500];
	cout << "Enter strings.For exit put '~'." << endl;
	int i = 0;
	while (write) {
		gets_s(str);
		fputs(str, pf1); fputs("\n", pf1);
		for (i = 0; i < 500; i++) {
			if (str[i] == '~') {
				break;
			}
		}
		if (i < 500) break;
	}
	
	fclose(pf1);
	cout << endl << endl;

	pf1 = fopen("file1.txt", "r");
	FILE* pf2 = fopen("file2.txt", "w");

	char buf[1000];
	
	while (int c = fgetc(pf1) != EOF){
		fscanf(pf1, "%[^\n]", &buf);
		if (buf[0] >= '0' && buf[0] <= '9') {
			fprintf(pf2, "%s\n", buf);
		}
	}
	
	fclose(pf1);
	fclose(pf2);
}

