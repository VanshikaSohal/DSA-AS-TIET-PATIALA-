#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> st;
void reverse(string s) {
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        st.push(ch);
    }
}
string display() {
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }
    return reversed;
}
int main() {
    string s;
    cout << "Enter the string: " << endl;
    cin >> s;
    cout << endl;
    reverse(s);   
    string reversevalue = display();  
    cout << reversevalue << endl;
    return 0;
}

