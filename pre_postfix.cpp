#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int prefixEval(string s) {
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (isdigit(s[i])) {
            st.push(s[i] - '0');
        } else {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
                default:
                    cout << "Invalid";
                    break;
            }
        }
    }
    return st.top();
}

int postfixEval(string s) {
    stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            st.push(s[i] - '0');
        } else {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
                default:
                    cout << "Invalid";
                    break;
            }
        }
    }
    return st.top();
}

int main() {
    cout << "Prefix and Postfix Evaluator\n";
    cout << "Choose your evaluator\n";
    cout << "1: Prefix\n";
    cout << "2: Postfix\n\n";
    int choice;
    cout << "Choose: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string str;
            cout << "Enter the Prefix Expression: ";
            cin >> str;
            cout << "Result: " << prefixEval(str) << endl;
            break;
        }
        case 2: {
            string str;
            cout << "Enter the Postfix Expression: ";
            cin >> str;
            cout << "Result: " << postfixEval(str) << endl;
            break;
        }
        default:
            cout << "Invalid Input";
            break;
    }

    return 0;
}