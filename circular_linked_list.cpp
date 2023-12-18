#include <iostream>
using namespace std;

class cNode {
public:
    int val;
    cNode* next;

    cNode(int n) : val(n), next(nullptr) {}
};

void insertAtFront(cNode*& head, int val) {
    cNode* block = new cNode(val);
    if (head == nullptr) {
        head = block;
        head->next = head;
    } else {
        block->next = head->next;
        head->next = block;
    }
}

void insertAfterElement(cNode* head, int val, int element) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    cNode* temp = head;
    do {
        if (temp->val == element) {
            cNode* block = new cNode(val);
            block->next = temp->next;
            temp->next = block;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Element " << element << " not found in the list\n";
}

void insertAtBack(cNode*& head, int val) {
    cNode* block = new cNode(val);
    if (head == nullptr) {
        head = block;
        head->next = head;
    } else {
        block->next = head->next;
        head->next = block;
        head = block;
    }
}

void removeFromBack(cNode*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    cNode* temp = head;
    cNode* prev = nullptr;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        if (head->next == head) {
            head = nullptr;
        } else {
            prev->next = head->next;
            head = prev;
        }
    } else {
        prev->next = temp->next;
    }

    delete temp;
}


void removeFromFront(cNode*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    cNode* temp = head->next;
    if (temp == head) {
        head = nullptr;
    } else {
        head->next = temp->next;
    }

    delete temp;
}

void removeElement(cNode*& head, int val) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    cNode* temp = head;
    cNode* prev = nullptr;

    do {
        if (temp->val == val) {
            if (prev) {
                prev->next = temp->next;
                if (temp == head) {
                    head = prev;
                }
                delete temp;
                return;
            } else {
                removeFromFront(head);
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    cout << "Element " << val << " not found in the list\n";
}

cNode* search(cNode* head, int val) {
    if (head == nullptr) {
        return nullptr;
    }

    cNode* temp = head;
    do {
        if (temp->val == val) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);

    return nullptr;
}

void concatenate(cNode*& head1, cNode*& head2) {
    if (head1 == nullptr && head2 == nullptr) {
        cout << "Both lists are empty\n";
        return;
    }

    if (head1 == nullptr) {
        head1 = head2;
    } else if (head2 != nullptr) {
        cNode* temp1 = head1;
        while (temp1->next != head1) {
            temp1 = temp1->next;
        }

        cNode* temp2 = head2;
        while (temp2->next != head2) {
            temp2 = temp2->next;
        }

        temp1->next = head2;
        temp2->next = head1;
    }

    head2 = nullptr;
}


void display(cNode* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    cNode* block = head;
    do {
        cout << block->val << " -> ";
        block = block->next;
    } while (block != head);
    cout << "head\n";
}

int main() {
    cNode* list = nullptr;
    insertAtFront(list, 22);
    insertAtFront(list, 562);
    insertAtFront(list, 563);
    insertAtFront(list, 56);
    insertAtFront(list, 13);
    display(list);

    insertAfterElement(list, 16, 563);
    display(list);

    insertAtBack(list, 99);
    display(list);

    removeFromBack(list);
    display(list);

    removeFromFront(list);
    display(list);

    removeElement(list, 16);
    display(list);

    cNode* list2 = nullptr;
    insertAtFront(list2, 521);
    insertAtFront(list2, 86);
    insertAtFront(list2, 23);
    display(list2);

    concatenate(list, list2);
    display(list);

    return 0;
}
