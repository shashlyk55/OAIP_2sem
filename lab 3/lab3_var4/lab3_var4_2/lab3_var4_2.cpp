#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void inFile(ifstream& f, string& text, string file, int& maximum) //Функция чтения из файла
{
	f.open(file);
	if (f.fail()) {
		cout << "\n Error";
		exit(1);
	}
	else {
		string longest_word;
		while (f >> text) { 
			int len = text.length(); 
			if (len > maximum) { 
				maximum = len;             
				longest_word = text;
			}                                                        
		}
		cout << longest_word;
		f.close();
	}
}

void fromFile(ofstream& f, string text,string& file) //Функция записи в файл
{
	f.open(file);
	if (f.fail())
	{
		cout << "\nError";
		exit(1);
	}
	else {
		f << text;
		f.close();
	}
}


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main() {
	string file = "task.txt", word, str;
	cout << "Enter a string: ";
	getline(cin, str); 
	ofstream fout; 
	fromFile(fout, str,file);
	ifstream fin;	
	int max = 0;
	inFile(fin, word,file, max);
	cout << endl << max << " characters.";
}