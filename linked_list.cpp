#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
    
        Node(int n){
            val = n;
            next = NULL;
        }
};

class DNode{
    public:
        int val;
        DNode* prev;
        Dnode* next;

        DNode(int n){
            val = n;
            prev = NULL;
            next = NULL;
        }
};

class DoublyLinkedList{
    public:
        DNode* head;
        DNode* tail;

        DoublyLinkedList(){
            head = NULL;
            tail = NULL;
        }

        void insertAtStart(int val){
            DNode* arr = new DNode(val);
            if(head == NULL){
                head == arr;
                tail = arr;
                return;
            }
            arr -> next = head;
            head -> prev = arr;
        }
}
void insertAtHead(Node* &head, int val){
    Node* arr = new Node(val);
    arr -> next = head;
    head = arr;
}

void insertAtTail(Node* &head, int val){
    Node* arr = new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp-> next = arr;
}

void insertRand(Node* &head, int val, int pos){
    Node* arr = new Node(val);
    Node* temp = head;
    for(int i = 0; i<pos-1; i++){
        temp = temp -> next;
    }
    arr->next = temp -> next;
    temp->next = arr;
}

void update(Node* &head, int k, int pos){
    Node* temp = head;
    for(int i = 0; i<pos; i++){
        temp = temp -> next;
    }
    temp->val = k;
}

void deleteAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    free(temp);

}

void deleteAtEnd(Node* &head){
    Node* temp = head;
    while(temp->next->next !=NULL){
        temp = temp->next;
    }
    Node* del = temp ->next;
    temp -> next = NULL;
    free(del);
}

void deleteRand(Node* &head, int pos){
    Node* temp = head;
    for(int i = 0; i<pos-1; i++){
        temp = temp->next;
    }
    Node* del = temp->next;
    temp->next = temp->next->next;
}
void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp -> val << " -> ";
        temp = temp -> next;
    }
    cout << "NULL";
}

int main(){
    Node* n = new Node(15);
    insertAtHead(n,4);
    insertAtHead(n,43);
    insertAtHead(n,42);
    insertAtHead(n,4345);
    insertAtTail(n,2);
    insertRand(n,6,4);
    update(n,300,1);
    deleteAtHead(n);
    deleteAtEnd(n);
    deleteRand(n,2);
    display(n);
    
    return 0;
}