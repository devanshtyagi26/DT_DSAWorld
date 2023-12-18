#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << "Inserted at the front: " << value << endl;
    }

    void insertRear(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Inserted at the rear: " << value << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from front.\n";
        } else {
            Node* temp = front;
            if (front == rear) {
                front = rear = nullptr;
            } else {
                front = front->next;
                front->prev = nullptr;
            }
            cout << "Deleted from the front: " << temp->data << endl;
            delete temp;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from rear.\n";
        } else {
            Node* temp = rear;
            if (front == rear) {
                front = rear = nullptr;
            } else {
                rear = rear->prev;
                rear->next = nullptr;
            }
            cout << "Deleted from the rear: " << temp->data << endl;
            delete temp;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
        } else {
            cout << "Deque elements: ";
            Node* current = front;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Deque deque;

    deque.insertFront(1);
    deque.insertFront(2);
    deque.insertRear(3);
    deque.display();

    deque.deleteFront();
    deque.deleteRear();
    deque.display();

    return 0;
}
