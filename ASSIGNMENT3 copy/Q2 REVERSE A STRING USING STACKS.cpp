#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 100;
char st[MAX_SIZE];   
int top = -1;
void push(char element) {
    if (top >= MAX_SIZE - 1) {
        cout << "Stack overflow" << endl;
    } else {
        st[++top] = element;
    }
}
char pop() {
    if (top < 0) {
        cout << "Stack underflow" << endl;
        return '\0'; 
    } else {
        return st[top--];
    }
}
bool isempty() {
    return (top == -1);
}
string reversestring(string s) {
    for (int i = 0; i < (int)s.length(); i++) {
        push(s[i]);
    }
    string reversed = "";
    while (!isempty()) {
        reversed += pop();
    }
    return reversed;
}
int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);  
    string reversedval = reversestring(s);
    cout << "Reversed string: " << reversedval << endl;
    cin.get(); 
    return 0;
}

