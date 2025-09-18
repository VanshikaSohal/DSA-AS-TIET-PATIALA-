#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
int stack[MAX_SIZE];      
int top = -1;   
void push(int element) {
    if (top >= MAX_SIZE - 1) {
        cout << "Stack is full (Stack overflow)" << endl;
    } else {
        top++;
        stack[top] = element;
        cout << element << " pushed into the stack" << endl;
    }
}
void pop() {
    if (top < 0) {
        cout << "Stack is empty (Stack underflow)" << endl;
    } else {
        cout << stack[top] << " popped from the stack" << endl;
        top--;
    }
}
void display() {
    if (top < 0) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}
bool isEmpty() {
    return (top == -1);
}
bool isFull() {
    return (top == MAX_SIZE - 1);
}
void peek() {
    if (top >= 0) {
        cout << "Top element of stack is: " << stack[top] << endl;
    } else {
        cout << "No top element (Stack is empty)" << endl;
    }
}
int main() {
    int choice, value;
    do {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. isFull" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                if (isEmpty())
                    cout << "Stack is empty" << endl;
                else
                    cout << "Stack is not empty" << endl;
                break;
            case 5:
                if (isFull())
                    cout << "Stack is full" << endl;
                else
                    cout << "Stack is not full" << endl;
                break;
            case 6:
                peek();
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 7);
    return 0;
}

