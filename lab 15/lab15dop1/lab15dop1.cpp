#include <iostream>
#include <list>
#include <utility>
#include<string>
#include<set>
using namespace std;

class HashTable {
private:
	int size;
	list<pair<int, char>>* table;

	// Hash function
	int hash(int key) {
		return key % size;
	}
public:
	HashTable(int size) {
		this->size = size;
		table = new list<pair<int, char>>[size];
	}

	~HashTable() {
		delete[] table;
	}

	// Insert element into the hash table
	void insert(int key, char value) {
		int index = hash(value);
		table[index].push_front(make_pair(key, value));
	}

	// Search for an element in the hash table
	bool search(char value) {
		int index = hash(value);
		//for (auto& it : table[index]) {
		for (auto& it: table[index]) {
			if (it.second == value) {
				return true;
			}
		}
		return false;
	}

	// Get the value associated with a key
	int get(char value) {
		char index = hash(value);
		for (auto& it : table[index]) {
			if (it.second == value) {
				return it.first;
			}
		}
		return '\0';
	}

	// Remove an element from the hash table
	void remove(int key) {
		int index = hash(key);
		for (auto it = table[index].begin(); it != table[index].end(); it++) {
			if (it->first == key) {
				table[index].erase(it);
				break;
			}
		}
	}

	// Print the hash table
	void print() {
		for (int i = 0; i < size; i++) {
			cout << i;
			for (auto& it : table[i]) {
				cout << " -> (" << it.first << ", " << it.second << ")";
			}
			cout << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "ru");
	int size = 0, choice, k, count = 0;
	/*cout << "размер таблицы: ";
	cin >> size;*/
	
	string s;
	cout << "строка: ";
	getline(cin, s);
	set<char>chars;
	for (int i = 0; i < s.length(); i++) {
		chars.insert(s[i]);
	}
	size = chars.size();
	HashTable table(size);
	for (int i = 0, j = 0; s[i] != '\0'; i++) {
		for (j = 0; s[j] != '\0'; j++) {
			if (s[i] == s[j]) {
				count++;
			}
		}
		if (!table.search(s[i])) {
			table.insert(count, s[i]);
			size++;
		}
		//HashTable table(size);
		count = 0;
	}
	table.print();
	while (true) {
		cout << "1-поиск по символу\n2-выход\nчто делать?\n";
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "введите символ: ";
			char ch;
			cin >> ch;
			if (table.search(ch) == NULL)
				cout << "Ёлемент не найден" << endl;
			else
				cout << ch << " " << table.get(ch) << endl;
			
		}
			  break;
		case 2:
			exit(0);
		}
	}
	return 0;
}
