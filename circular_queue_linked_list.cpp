#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;

    node(int n){
        data = n;
        next = NULL;
    }
};

struct node* front = 0;
struct node* rear = 0;

void add(int x){
    struct node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = x;
    new_node -> next = 0;
    if (rear == 0){
        front = rear = new_node;
        rear -> next = front;
    }
    else{
        rear -> next = new_node;
        rear = new_node;
        rear -> next = front;
    }
}

void del(){
    struct node* temp;
    temp = front;
    if(front == 0 && rear == 0){
        cout << "Queue Underflow\n";
    }
    else if(front == rear){
        front = rear = 0;
        free(temp);
    }
    else{
        front = front -> next;
        rear -> next = front;
        free(temp);
    }
}

void peek(){
    if(front == 0 && rear == 0){
        cout << "Queue Underflow\n";
    }
    else{
        cout << front -> data << endl;
    }
}
void display(){
    struct node *temp;
    temp = front;
    if(front == 0 && rear == 0){
        cout << "Queue Underflow\n";
    }
    else{
        while(temp -> next != front){
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << temp -> data << endl;
    }
}

int main(){
    
    cout << "Circular Queue implemented using Linked List\n";
    cout << "Enter your choice: \n";
    cout << "1. Add\n";
    cout << "2. Delete\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Exit\n\n";

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
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting the program.";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}
