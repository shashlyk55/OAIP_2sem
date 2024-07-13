#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void main() {

	setlocale(LC_ALL, "ru");

	ofstream fout;
	ifstream fin;
	string str, file1 = "FILE1.txt", file2 = "FILE2.txt";
	int count = 1, size = 0;

	fin.open(file1);
	fout.open(file2);

	while (!fin.eof()) {
		str = "";
		getline(fin, str);
		if (count % 2 == 0) {
			fout << str << '\n';
		}
		count++;
	}
	fin.close();
	fout.close();

	fin.open(file1); 
	while (getline(fin, str)) {
		for (int i = 0; str[i] != '\0'; i++) {
			size++;
		}
		size += 2;
	}

	size -= 2;
	fin.close();
	printf("file1 %d bytes", size);
	size = 0;
	fin.open(file2);
	while (getline(fin, str)) {
		for (int i = 0; str[i] != '\0'; i++) {
			size++;
		}
		size += 2;
	}
	printf("\nfile2 %d bytes", size);
	fin.close();
}

