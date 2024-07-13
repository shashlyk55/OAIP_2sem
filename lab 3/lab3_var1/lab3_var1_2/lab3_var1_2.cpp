#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void inFile(ifstream& f, string& string) //Функция чтения из файла
{
	if (!f.is_open())  
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	int num, flag1, flag2;
	/*while (f >> string) {
		for (int i = 0; string[i] != '\0'; i++) {
			if (string[i] >= '0' && string[i] <= '9') {
				num = string[i] - '0';
				if (num % 2 != 0) {
					cout << num << endl;
				}
			}
		}
	}*/
	while (f >> string) {
		for (int i = 0;string[i]!='\0'; i++) {

			if (string[i] >= '0' && string[i] <= '9') {
				flag1 = i;
				while (string[i] >= '0' && string[i] <= '9') {
					i++;
				}
				i--;
				flag2 = i;
				
				if (((int)(string[i] - '0')) % 2 != 0) {
					for (int j = flag1; j <= flag2; j++) {
						cout << string[j];
					}
					cout << endl;
				}
			}

		}
	}
	f.close();

}
void fromFile(ofstream& f, string& string) //Функция записи в файл
{
	
	if (!f.is_open())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	f << string;           
	f.close();
}

void main() {
	setlocale(LC_ALL, "ru");
	string str;
	cout << "Введите строку: ";
	getline(cin, str);
	
	ofstream fout("file.txt");
	fromFile(fout,str);

	ifstream fin("file.txt");
	string word;
	inFile(fin, word);
}

