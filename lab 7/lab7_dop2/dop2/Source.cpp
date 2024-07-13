#include <iostream>
#include <fstream>
#include<windows.h>
#include<string>

using namespace std;

struct Node { 
    int data; 
    Node* next; 
};

class Stack {
private:
    Node* top; 
public:
    Stack() { 
        top = NULL; 
    }

    void push(int val) { 
        Node* newNode = new Node; 
        newNode->data = val; 
        newNode->next = top; 
        top = newNode;
    }

    int pop() { 
        if (top == NULL) { 
            cout << "Stack is empty." << endl;
            return -1;
        }
        Node* tempNode = top; 
        int val = tempNode->data; 
        top = top->next;
        delete tempNode; 
        return val; 
    }

    int peek() {
        if (top == NULL) { 
            cout << "Stack is empty." << endl;
            return -1; 
        }
        return top->data; 
    }

    bool isEmpty() {
        return top == NULL;
    }

    void print() { 
        if (top == NULL) { 
            cout << "Stack is empty." << endl;
            return;
        }
        Node* tempNode = top;
        cout << "Stack: ";
        while (tempNode != NULL) { 
            cout << tempNode->data << " "; 
            tempNode = tempNode->next; 
        }
        cout << endl;
    }
};

int main() {
    ifstream fin("file.txt");
    if (!fin) { 
        cout << "Can not open file." << endl;
        return 1;
    }

    Stack s; 
    string line;
    int count = 0, pos = -1;
    int shortestLength = 999999;

    while (getline(fin,line)) { 
        int len = line.length(); 
        s.push(len); 
        count++;
        
        if (len < shortestLength) { 
            shortestLength = len;
            pos = count;
        }
        /*else if (len == shortestLength) {
            count++;
        }*/
        
    }

    fin.close(); 

    if (s.isEmpty()) { 
        cout << "Stack is empty." << endl;
    }
    else {
        s.print(); 
    }

    cout << "Last shortest string number: " << pos << ", length: " << shortestLength << endl;
    return 0;
}