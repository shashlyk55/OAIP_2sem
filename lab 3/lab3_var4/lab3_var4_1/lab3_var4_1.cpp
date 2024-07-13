#include <iostream>
#include <fstream>
#include <string>

const int n = 40;
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	ifstream file1("FILE1.txt");
	ofstream file2("FILE2.txt");
	
	string str; int count = 0; 
	bool find_num = false;
	while (getline(file1, str)) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				find_num = true;
				continue;
			}
		}
		if (!find_num) {
			file2 << str << endl;
			if (str[0] == 'A') {
				count++;
			}
		}
		find_num = false;
	}
	cout << count;
	file1.close();
	file2.close();
	return 0;
}