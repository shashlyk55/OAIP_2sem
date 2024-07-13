#include <iostream>
#include <list>
#include <utility>
#include<string>
using namespace std;

class HashTable {
private:
	int size;
	list<pair<int, string>>* table;

	// Hash function
	int hash(int key) {
		int hash = 0;
		hash = hash ^ key;
		return key % size;
	}

	/*int hash(int key, string data) {
		unsigned int hash = 0;
		for (int i = 0; data[i] != '\0'; i++) {
			hash ^= data[i];
		}
		return (key + hash) % size;
	}

	unsigned int xor_hash(string data) {
		unsigned int hash = 0;
		for (int i = 0; data[i] != '\0'; i++) {
			hash ^= data[i];
		}
		return hash % size;
	}*/


public:
	HashTable(int size) {
		this->size = size;
		table = new list<pair<int, string>>[size];
	}

	~HashTable() {
		delete[] table;
	}

	// Insert element into the hash table
	void insert(int key, string value) {
		int index = hash(key);
		table[index].push_front(make_pair(key, value));
	}

	// Search for an element in the hash table
	bool search(int key) {
		int index = hash(key);
		for (auto& it : table[index]) {
			if (it.first == key) {
				return true;
			}
		}
		return false;
	}

	// Get the value associated with a key
	string get(int key) {
		int index = hash(key);
		for (auto& it : table[index]) {
			if (it.first == key) {
				return it.second;
			}
		}
		return "";
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
	int size, choice, k;
	cout << "������ �������: ";
	cin >> size;
	HashTable table(size);

	for (;;)
	{
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����:" << endl;   
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: table.print();
			break;
		case 2: {
			int num;
			string str;
			cout << "����� �������: ";
			cin >> num;
			while (table.search(num)) {
				cout << "����� ����� ��� ���� � �������!\n������� ������: ";
				cin >> num;
			}
			cout << "���: ";
			getchar();
			getline(cin, str);
			table.insert(num, str);
			}
			break;
		case 3: {  
			cout << "������� ���� ��� ��������: " << endl;
			cin >> k;
			table.remove(k);
			}  
			break;
		case 4: {  cout << "������� ���� ��� ������" << endl;
			cin >> k;
			unsigned int start = clock();
			if (table.search(k) == NULL)
				cout << "������� �� ������" << endl;
			else
				cout << k << " " << table.get(k) << endl;
			unsigned int end = clock();
			float dif = end - start;
			cout << endl << dif << " ��\n";
		}  break;
		}
	}

	return 0;
}
