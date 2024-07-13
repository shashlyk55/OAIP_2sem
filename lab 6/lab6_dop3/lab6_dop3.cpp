#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() {
		head = nullptr;
	}
	void append(int value) {
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}
	void remove(int value) {
		if (head == nullptr) {
			cout << "List is empty" << endl;
			return;
		}
		if (head->data == value) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node* current = head;
		while (current->next != nullptr && current->next->data != value) {
			current = current->next;
		}
		if (current->next == nullptr) {
			cout << "Item not found" << endl;
			return;
		}
		Node* temp = current->next;
		current->next = current->next->next;
		delete temp;
	}
	void search(int value) {
		if (head == nullptr) {
			cout << "List is empty" << endl;
			return;
		}
		Node* current = head;
		while (current != nullptr) {
			if (current->data == value) {
				cout << "Item found" << endl;
				return;
			}
			current = current->next;
		}
		cout << "Item not found" << endl;
	}
	void display() {
		if (head == nullptr) {
			cout << "List is empty" << endl;
			return;
		}
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	void writeToFile(string filename) {
		ofstream file;
		file.open(filename);
		if (file.fail()) {
			cout << "Failed to open file" << endl;
			return;
		}
		Node* current = head;
		while (current != nullptr) {
			file << current->data << " ";
			current = current->next;
		}
		file.close();
	}
	void readFromFile(string filename) {
		ifstream file;
		file.open(filename);
		if (file.fail()) {
			cout << "Failed to open file" << endl;
			return;
		}
		int value;
		while (file >> value) {
			append(value);
		}
		file.close();
	}
	void clear() {
		Node* p, * p1;
		p = head;

		while (p != NULL) {
			p1 = p->next;

			delete p;
			p = p1;
		}
		head = NULL;
	}
	void result() {
		int sum = 0;
		int count = 0;
		if (head == nullptr) {
			cout << "List is empty" << endl;
			cout << "Result " << sum << endl;
			return;
		}
		Node* current = head;
		while (current != nullptr) {
			if ((current->data % 5 == 0) && (current->data > 0)) {
				sum += current->data;
			}
			current = current->next;
		}
		if (sum == 0) {
			cout << "no such elements\n";
		}
		cout << "Result " << sum << endl;
	}
};

int main() {
	LinkedList list;
	int choice;
	int number;
	string filename;
	while (true) {
		cout << "Menu:" << endl;
		cout << "1. Add an item" << endl;
		cout << "2. Delete an item" << endl;
		cout << "3. Search for an item" << endl;
		cout << "4. Display the list" << endl;
		cout << "5. Write the list to a file" << endl;
		cout << "6. Read the list from a file" << endl;
		cout << "7. Solution of task" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cin >> number;
			list.append(number);
			break;
		case 2:
			cin >> number;
			list.remove(number);
			break;
		case 3:
			cin >> number;
			list.search(number);
			break;
		case 4:
			list.display();
			break;
		case 5:
			list.writeToFile("list.txt");
			break;
		case 6:
			list.clear();
			list.readFromFile("list.txt");
			break;
		case 7:
			list.result();
			break;
		case 0:
			exit(1);
		}
	}
}