#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* link;

	Node(int n)
	{
		data = n;
		link = NULL;
	}
};

class Stack {
	Node* top;

public:
	Stack(){
        top = NULL;
        }

	void push(int data)
	{
		Node* temp = new Node(data);

		if (!temp) {
			cout << "\nStack Overflow";
			exit(1);
		}

		temp->data = data;
		temp->link = top;
		top = temp;
	}

	bool isEmpty()
	{
		return top == NULL;
	}

    void pop()
	{
		Node* temp;

		if (top == NULL) {
			cout << "\nStack Underflow" << endl;
			exit(1);
		}
		else {
			temp = top;
            cout << temp->data<<endl;
			top = top->link;
			free(temp);
		}
	}

	int peek()
	{
		if (!isEmpty())
			return top->data;
		else
			exit(1);
	}

	

	void display()
	{
		Node* temp;

		if (top == NULL) {
			cout << "\nStack Underflow";
			exit(1);
		}
		else {
			temp = top;
			while (temp != NULL) {
				cout << temp->data;
				temp = temp->link;
				if (temp != NULL)
					cout << " -> ";
			}
            cout <<endl;
		}
	}
};

int main()
{
	Stack s;

    cout << "Stack implemented using Linked List\n";


	int choice;
	while (true) {
        cout << "Enter your choice: \n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n\n";
        cout << "Choose: ";
		cin >> choice;

		switch (choice) {
		case 1:
			int data;
			cout << "Enter the element to push: ";
			cin >> data;
			s.push(data);
			break;
		case 2:
			s.pop();
			break;
		case 3:
			cout << "Top element is " << s.peek() << endl;
			break;
		case 4:
			s.display();
			break;
		default:
			cout << "Exiting the program.";
			return 0;
		}
	}

	return 0;
}
