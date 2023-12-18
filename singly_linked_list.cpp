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
void insertAtHead(Node* &head, int val){
    Node* block = new Node(val);
    block -> next = head;
    head = block;
}
void insertPos(Node* head, int val, int pos){
    Node* temp = head;
    Node* block = new Node(val);
    for(int i = 0; i<pos-1; i++){
        temp = temp->next;
    }
    block->next = temp->next;
    temp -> next = block;
}

void deleteFromHead(Node* &head){
    Node* temp = head;
    Node* del = head;
    head = temp->next;
    free(del);
}

void deletePos(Node* &head, int pos){
    Node* temp = head;
    
    for(int i = 0; i<pos-1; i++){
        temp = temp->next;
    }

    Node* del = temp->next;
    temp->next = temp->next->next;
    free(del);
}

void pointer(Node* head, int x){
    Node* temp = head;
    while(temp !=NULL){
        if(temp->val == x){
            cout << "Pointer: " << temp << endl;
            break;
        }
        temp = temp -> next;
    }
    
}

void concatinate(Node* &head1, Node* &head2){
    Node* temp = head1;
    if (temp) {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    } else {
    
        head1 = head2;
    }

    head2 = NULL;
}

void display(Node* head){
    Node* block = head;
    while(block != NULL){
        cout << block->val << " -> ";
        block = block->next;
    }
    cout << "NULL\n";
}


int main(){
    Node* list = new Node(13);
    insertAtHead(list, 56);
    insertAtHead(list, 563);
    insertAtHead(list, 562);
    insertAtHead(list, 22);
    display(list);
    insertPos(list, 16, 1);
    display(list);
    deleteFromHead(list);
    display(list);
    deletePos(list, 2);
    display(list);
    pointer(list, 16);
    display(list);

    Node* list2 = new Node(23);
    insertAtHead(list2, 86);
    insertAtHead(list2, 521);
    display(list2);
    concatinate(list,list2);
    display(list);
    return 0;
}