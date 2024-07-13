#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void inFile(ifstream& f, string& text, string& file) //Функция чтения из файла
{
	f.open(file);
	if (f.fail()) {
		cout << "\n Error";
		exit(1);
	}
	int size, min = 99;
	string buf;
	while (f >> text) {

		size = text.length();
		if (min > size) {
			min = size;
			buf = text;
		}
	}
	cout << buf;
	f.close();
}
void fromFile(ofstream& f, string& text, string& file) //Функция записи в файл
{
	f.open(file);
	if (f.fail())
	{
		cout << "\nError";
		exit(1);
	}
	f << text;
	f.close();
}

void main() {
	ifstream fin;
	ofstream fout;
	string file = "text.txt", str1, str2;
	getline(cin, str1);
	fromFile(fout, str1, file);
	inFile(fin, str2, file);
}