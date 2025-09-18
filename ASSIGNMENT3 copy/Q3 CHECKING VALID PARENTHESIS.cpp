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

bool matchpair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool balanced(string expr) {
	top=-1;
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (empty() || !matchpair(peek(), c)) {
                return false; 
            }
            pop(); 
        }
    }
	return empty();  
}

int main() {
	string expr;
	while(1){
    cout << "Enter expression: ";
    getline(cin, expr); 
    if (balanced(expr)) {
        cout << "Valid parentheses" << endl;
    } else {
        cout << "Invalid parentheses" << endl;
    }
}
    return 0;
}

