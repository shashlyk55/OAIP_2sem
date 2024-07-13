#include <iostream>
#include<fstream>
#include "myStack.h"
#include<Windows.h>
using namespace std;
void push(int x, Stack* myStk)  
{
	Stack* e = new Stack;    
	e->data = x;             
	e->next = myStk->head;   
	myStk->head = e;        
}
int pop(Stack* myStk)   
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               
	}
	else
	{
		Stack* e = myStk->head;   
		int a = myStk->head->data;   
		myStk->head = myStk->head->next; 
		delete e;                        
		return a;                        
	}
}
void show(Stack* myStk)    
{
	Stack* e = myStk->head;    
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

void separation(Stack* myStk) {
	Stack* Stk1 = new Stack;
	Stk1->head = NULL;
	Stack* Stk2 = new Stack;
	Stk2->head = NULL;

	Stack* e = myStk->head;
	Stack* s1, * s2;
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          
		if (a % 2 == 0) {
			Stack* s1 = new Stack;    
			s1->data = a;            
			s1->next = Stk1->head;  
			Stk1->head = s1;
		}
		if (a % 2 != 0) {
			Stack* s2 = new Stack;    
			s2->data = a;            
			s2->next = Stk2->head;   
			Stk2->head = s2;
		}
		e = e->next;
	}
	cout << "Стек четных чисел: ";
	show(Stk1);
	cout << endl;
	cout << "Стек нечетных чисел: ";
	show(Stk2);
	cout << endl;
}

//void clear(Stack* myStk) {
//		while (myStk->head != nullptr) {
//			Stack* temp = myStk->head;
//			myStk->head = myStk->head->next;
//			delete temp;
//		}
//}

void outFile(Stack*& myStk) {
	Stack buf;
	Stack* StkFromFile = new Stack;
	Stack* first = nullptr;
	
	ifstream fin("Stack.txt");
	if (fin.fail()) {
		cout << "\nОшибка открытия файла";
		exit(1);
	}
	
	while (fin >> buf.data) {
		//fin.read((char*)&buf, sizeof(Stack));
		push(buf.data, StkFromFile);
		cout << " " << buf.data;
	}
		
	cout << "-->NULL\n";
	fin.close();
	StkFromFile = first;
	cout << "Список считан из файла Stack.txt\n";
}


void ToFile(Stack* myStk) {
	ofstream outputFile("Stack.txt");
	if (!outputFile.is_open()) {
		cerr << "Не удалось создать файл Stack.txt" << endl;
		return;
	}

	Stack* current = myStk->head;
	while (current != nullptr) {
		outputFile << current->data << endl;
		current = current->next;
	}

	outputFile.close();
}

void clear(Stack* Stk) {
	Stack* p, * p1;
	p = Stk->head;

	while (p != NULL) {
		p1 = p->next;

		delete p;
		p = p1;
	}
	Stk->head = NULL;
}

void writeToFile(Stack* Stk) {
	ofstream file;
	file.open("stack.txt");
	if (file.fail()) {
		cout << "Failed to open file" << endl;
		return;
	}
	Stack* current =Stk->head;
	while (current != nullptr) {
		file << current->data << " ";
		current = current->next;
	}
	file.close();
}
void readFromFile(Stack* Stk) {
	ifstream file;
	file.open("stack.txt");
	if (file.fail()) {
		cout << "Failed to open file" << endl;
		return;
	}
	float value;
	while (file >> value) {
		push(value,Stk);
	}
	file.close();
}