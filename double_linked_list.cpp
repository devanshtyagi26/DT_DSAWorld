#include <iostream>
using namespace std;

class dNode {
public:
    int val;
    dNode* next;
    dNode* prev;

    dNode(int n){
        val = n;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(dNode* &head, int val) {
    dNode* block = new dNode(val);
    block->next = head;
    if (head) {
        head->prev = block;
    }
    head = block;
}

void insertPos(dNode* &head, int val, int pos) {
    dNode* temp = head;
    dNode* block = new dNode(val);

    for (int i = 0; i < pos - 1 && temp; ++i) {
        temp = temp->next;
    }

    if (temp) {
        block->next = temp->next;
        if (temp->next) {
            temp->next->prev = block;
        }
        temp->next = block;
        block->prev = temp;
    } else {
        cout << "Invalid position\n";
    }
}

void deleteFromHead(dNode* &head) {
    dNode* temp = head;
    if (head) {
        head = temp->next;
        if (head) {
            head->prev = nullptr;
        }
        delete temp;
    } else {
        cout << "List is empty\n";
    }
}

void deletePos(dNode* &head, int pos) {
    dNode* temp = head;

    for (int i = 0; i < pos - 1 && temp; ++i) {
        temp = temp->next;
    }

    if (temp && temp->next) {
        dNode* del = temp->next;
        temp->next = del->next;
        if (del->next) {
            del->next->prev = temp;
        }
        delete del;
    } else {
        cout << "Invalid position\n";
    }
}

void pointer(dNode* head, int x) {
    dNode* temp = head;
    while (temp != NULL) {
        if (temp->val == x) {
            cout << "Pointer: " << temp << endl;
            break;
        }
        temp = temp->next;
    }
}

void concatenate(dNode* &head1, dNode* &head2) {
    dNode* temp = head1;
    if (temp) {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
        if (head2) {
            head2->prev = temp;
        }
    } else {
        head1 = head2;
    }

    head2 = NULL;
}

void display(dNode* head) {
    dNode* block = head;
    while (block != NULL) {
        cout << block->val << " <-> ";
        block = block->next;
    }
    cout << "NULL\n";
}

int main() {
    dNode* list = new dNode(11);
    insertAtHead(list, 23);
    insertAtHead(list, 53);
    insertAtHead(list, 52);
    insertAtHead(list, 12);
    display(list);

    insertPos(list, 36, 2);
    display(list);

    deleteFromHead(list);
    display(list);

    deletePos(list, 3);
    display(list);

    pointer(list, 4);
    display(list);

    dNode* list2 = new dNode(223);
    insertAtHead(list2, 81);
    insertAtHead(list2, 231);
    display(list2);

    concatenate(list, list2);
    display(list);

    return 0;
}
