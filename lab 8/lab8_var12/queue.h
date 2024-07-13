#pragma once
#include<cstdlib>
#include<iostream>
using namespace std;

struct Node {
    char info;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int maxSize;
    int size;
public:
    Queue(int size) {
        front = NULL;
        rear = NULL;
        maxSize = size;
        size = 0;
    }
    void enqueue(char c) {
        if (size == maxSize) {
            cout << "Queue is full, cannot add more elements." << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->info = c;
        newNode->next = NULL;
        if (front == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
            if (c == front->info) {
                cout << "Added element match with the first element of queue\n";
                size++;
                displayQueue();
                getQueueSize();
                return;
            }
        }
        size++;

    }
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty, cannot remove elements." << endl;
            return;
        }
        char c = front->info;
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
        cout << "Removed " << c << " from the queue." << endl;
    }
    void displayQueue() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current queue: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void getQueueSize() {
        cout << "Current queue size: " << size << endl;
    }
    void searchQueue() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        char c;
        cout << "Enter a character to search for: ";
        cin >> c;
        Node* temp = front;
        bool found = false;
        while (temp != NULL) {
            if (temp->info == c) {
                found = true;
            }
            temp = temp->next;
        }
        if (found) {
            cout << "Found " << c << " in the queue." << endl;
        }
        else {
            cout << "Could not find " << c << " in the queue." << endl;
        }
    }
};