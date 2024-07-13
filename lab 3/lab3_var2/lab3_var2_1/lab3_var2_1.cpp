#include <iostream>
#include <fstream>
#include <string>

const int n = 40;
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	ifstream file1("FILE1.txt");
	ofstream file2("FILE2.txt");

	string str; int count = 0;
	bool find_num = false;
	while (getline(file1, str)) {
		if (str[0] == 'A') {
			file2 << str << '\n';
			for (int i = 0; str[i] != '\0'; i++) {
				if (i == 0 || str[i] == ' ' || str[i] == '\n') {
					count++;
				}
			}
		}
	}
	cout << count;
	file1.close();
	file2.close();
	return 0;
}