#include <iostream>
using namespace std;

int const maxSize = 5;
int queue[maxSize];
int front = -1;
int rear = -1;

void add(int x) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else if (((rear + 1) % maxSize) == front) {
        cout << "Queue Overflow\n";
    } else {
        rear = (rear + 1) % maxSize;
        queue[rear] = x;
    }
}

void del() {
    if (front == -1 && rear == -1) {
        cout << "Queue Underflow\n";
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % maxSize;
    }
}

void display() {
    int i = front;
    if (front == -1 && rear == -1) {
        cout << "Queue Underflow\n";
    } else {
        cout << "[ ";
        while (i != (rear + 1) % maxSize) {
            cout << queue[i] << " ";
            i = (i + 1) % maxSize;
        }
        cout << "]\n";
    }
}

int main() {
    cout << "Circular Queue implemented using Arrays\n";
    cout << "Enter your choice: \n";
    cout << "1. Add\n";
    cout << "2. Delete\n";
    cout << "3. Display\n";
    cout << "4. Exit\n\n";

    int ch;
    while (true) {
        cout << "Choose: ";
        cin >> ch;
        int element;
        switch (ch) {
            case 1:
                cout << "Enter the element you want to enter: ";
                cin >> element;
                add(element);
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting the program.";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}
