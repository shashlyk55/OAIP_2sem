#include"queue.h"
#include<iostream>
#include<windows.h> 
#include <cstdlib>

using namespace std;


int main() {
    int maxSize;
    cout << "Enter the maximum size of the queue: ";
    cin >> maxSize;
    Queue q(maxSize);
    int choice;
    while (true) {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display queue" << endl;
        cout << "4. Get queue size" << endl;
        cout << "5. Search for character in queue" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            char c;
            cout << "Enter a character to add to the queue: ";
            cin >> c;
            q.enqueue(c);
            break;
        }
        case 2:
            q.dequeue();
            break;
        case 3:
            q.displayQueue();
            break;
        case 4:
            q.getQueueSize();
            break;
        case 5:
            q.searchQueue();
            break;
        case 6:
            exit(1);
        }
    }
}