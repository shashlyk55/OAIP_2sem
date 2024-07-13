#pragma once
struct Stack
{
	int data;             
	Stack* head;		
	Stack* next;		 
};

void show(Stack* myStk);         
int pop(Stack* myStk);           
void push(int x, Stack* myStk); 
void separation(Stack* myStk);
//void clear(Stack* myStk);
void inFile(Stack*& myStk);
void outFile(Stack*& myStk);
void ToFile(Stack* myStk);
void clear(Stack* Stk);
void writeToFile(Stack* Stk);
void readFromFile(Stack* Stk);
