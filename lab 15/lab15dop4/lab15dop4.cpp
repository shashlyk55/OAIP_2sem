#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>
#include<fstream>
using namespace std;
class HashTable {
private:
	int tableSize;
	std::vector<std::list<int>> table;
public:
	HashTable(int size) : tableSize(size), table(size) {}

	int hash(int key) {
		return key % tableSize;
	}

	void insert(int key) {
		int index = hash(key);
		table[index].push_back(key);
	}

	bool search(int key) {			// В ПОИСКЕ ВЫДАЮТ ОШИБККУ
		int index = hash(key);
		for (int value : table[index]) {
			if (value == key) {
				return true;
			}
		}
		return false;
	}

	void printHashTable() {
		for (int i = 0; i < tableSize; ++i) {
			std::cout << "Bucket " << i << ": ";
			for (int value : table[i]) {
				std::cout << value << " ";
			}
			std::cout << std::endl;
		}
	}

	void clearHashTable() {
		for (int i = 0; i < tableSize; ++i) {
			table[i].clear();
		}
	}
};
void menu() {
	cout << "1-чтение из файла\n2-поиск\n3-вывод таблицы\n4-выход\n";
}
ifstream fin;

int main() {
	setlocale(LC_ALL, "ru");
	int task;
	//ifstream inputFile("input.txt");
	fin.open("data.txt");
	
	string line;
	getline(fin, line);
	istringstream iss(line);
	int value;
	vector<int> values;

	for (int i = 0; !fin.eof(); i++) {
		if (i == 0) {
			while (iss >> value) {
				values.push_back(value);
			}
		}
		else {
			getline(fin, line);
			istringstream iss(line);
			while (iss >> value) {
				values.push_back(value);
			}
		}
	}
	
	HashTable hashTable(values.size());
	for (int value : values) {
		if (hashTable.search(value)) {
			continue;
		}
		hashTable.insert(value);
	}
	fin.close();
	while (true) {
		menu();
		cin >> task;
		switch (task) {
		case 1: {
			hashTable.clearHashTable();
			fin.open("data.txt");
			while (!fin.eof()) {
				getline(fin, line);

				istringstream iss(line);
				int value;
				vector<int> values;
				while (iss >> value) {
					values.push_back(value);
				}
				for (int value : values) {
					if (hashTable.search(value)) {
						continue;
					}
					hashTable.insert(value);
				}
			}
			fin.close();
		}
			  break;
		case 2: {
			std::cout << "Enter a number to search in the hash table: ";
			int searchValue;
			std::cin >> searchValue;
			unsigned int start = clock();
			bool found = hashTable.search(searchValue);
			unsigned int end = clock();
			cout << endl << end - start << endl;
			if (found) {
				std::cout << "Number found in the hash table." << std::endl;
			}
			else {
				std::cout << "Number not found in the hash table." << std::endl;
			}
		}
			  break;
		case 3: {
			hashTable.printHashTable();
		}
			  break;
		case 4:
			exit(1);
		}	
	}
	return 0;
}
