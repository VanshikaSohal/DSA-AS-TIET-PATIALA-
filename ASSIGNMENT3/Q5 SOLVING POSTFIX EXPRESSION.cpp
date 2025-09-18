#include<iostream>
#include<string>
using namespace std;
const int MAX_SIZE = 100;
int st[MAX_SIZE];   
int top = -1;       
void push(int c) {
    if (top >= MAX_SIZE - 1) {
        cout << "Stack overflow" << endl;
    } else {
        st[++top] = c;
    }
}
int pop() {
    if (top < 0) {
        cout << "Stack underflow" << endl;
        return -1;
    } else {
        return st[top--];
    }
}
int peek() {
    if (top < 0) 
        return -1;
    return st[top];
}
bool empty() {
    return (top == -1);
}
int stringtoint(string s) {
    int num = 0;
    int sign = 1;
    int i = 0;
    if (s[0] == '-') {  
        sign = -1;
        i = 1;
    }
    for (; i < s.length(); i++) {
        num = num * 10 + (s[i] - '0');
    }
    return num * sign;
}
int solve(string tokens[], int n) {
    for(int i = 0; i < n; i++) {
        string ch = tokens[i];
        if(ch != "+" && ch != "-" && ch != "*" && ch != "/") {
            push(stringtoint(ch));
        }
        else {
            int b = pop();
            int a = pop();
            if(ch == "+") {
                push(a + b);
            }
            else if(ch == "-") {
                push(a - b);
            }
            else if(ch == "*") {
                push(a * b);
            }
            else if(ch == "/") {
                push(a / b);
            }
        }
    }
    return peek();
}
int split(string line, string tokens[]) {
    int n = 0;
    string temp = "";
    for(int i = 0; i <= line.length(); i++) {
        if(line[i] == ' ' || line[i] == '\0') {
            if(temp != "") {
                tokens[n++] = temp;
                temp = "";
            }
        } else {
            temp += line[i];
        }
    }
    return n;
}
int main() {
    string line;
    string tokens[MAX_SIZE];
    cout << "Enter postfix expression: ";
    getline(cin, line);
    int n = split(line, tokens);  
    int result = solve(tokens, n);
    cout << result << endl;
    cin.get();
    return 0;
}

