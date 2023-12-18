#include <iostream>
using namespace std;
int top = -1;
int const n = 5;
int stack[n];

void push(){
    if(top == n-1){
        cout << "Stack Overflow\n";
        return;
    }
    else{
        int var;
        cout << "Enter the element to push: ";
        cin >> var;
        top++;
        stack[top] = var;
    }
}

void pop(){
    if(top == -1){
        cout << "Stack Underflow\n";
        return;
    }
    else{
        int var = stack[top];
        top--;
        cout << var<<endl;
    }

}

void peek(){
    if(top == -1){
        cout << "Stack Underflow\n";
        return;
    }
    else{
        cout <<"Top element is "<< stack[top]<<endl;
    }
}

void display(){
    cout << "[";
    for(int i = top; i>=0; i--){
        cout << stack[i] << " ";
    }
    cout << "]\n";
}
int main(){
    cout << "Stack implemented using Arrays\n";
    cout << "Enter your choice: \n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Exit\n\n";
    
    int ch;
    while(true){
        cout<<"Choose: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;

        default:
            ch =0;
            cout << "Exiting the program.";
            return 0;
        }    
    }
    return 0;
}