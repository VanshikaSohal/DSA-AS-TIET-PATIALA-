#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 100;
char st[MAX_SIZE];
int top = -1;
void push(char c) {
    if (top >= MAX_SIZE - 1) {
        cout << "Stack overflow!" << endl;
    } else {
        st[++top] = c;
    }
}
char pop() {
    if (top < 0) {
        cout << "Stack underflow!" << endl;
        return '\0';
    } else {
        return st[top--];
    }
}
char peek() {
    if (top < 0)
        return '\0';
    return st[top];
}
bool empty() {
    return (top == -1);
}
int precedence(char op) {
    if(op == '^')
        return 3;
    if(op == '*' || op == '/')
        return 2;
    if(op == '+' || op == '-')
        return 1;
    return 0;
}
bool isoperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
string convert(string infix) {
    string postfix = "";
    top = -1; 
    for(char c : infix) {
        if(isalpha(c) || isdigit(c)) {
            postfix += c;
        }
        else if(c == '(') {
            push(c);
        }
        else if(c == ')') {
            while(!empty() && peek() != '(') {
                postfix += pop();
            }
            if(!empty())
			pop();
        }
        else if(isoperator(c)) {
            while(!empty() && (precedence(peek()) > precedence(c) || 
                  (precedence(peek()) == precedence(c) && c != '^'))) {
                postfix += pop();
            }
            push(c);
        }
    }
    while(!empty()) {
        postfix += pop();
    }
    return postfix;
}
int main() {
    string infix;
    while (true) {
        cout << "Enter infix : ";
        cin >> infix;
		getline(cin, infix); 
        if(infix == "exit") 
		break; 
        string postfix = convert(infix);
        cout << "Postfix: " << postfix << endl;
    }
    return 0;
}

