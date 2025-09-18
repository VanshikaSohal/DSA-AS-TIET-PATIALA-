#include <iostream>
using namespace std;
#define MAX 100
int q1[MAX], f1 = -1, r1 = -1;
int q2[MAX], f2 = -1, r2 = -1;
int q3[MAX], f3 = -1, r3 = -1;
void enqueue(int q[], int &f, int &r, int x) {
    if (r == MAX - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (f == -1) f = 0;
    q[++r] = x;
}
int dequeue(int q[], int &f, int &r) {
    if (f == -1) {
        cout << "Queue Underflow\n";
        return -1;
    }
    int val = q[f];
    if (f == r) f = r = -1;
    else f++;
    return val;
}
int peek(int q[], int f, int r) {
    if (f == -1) return -1;
    return q[f];
}
bool isEmpty(int f) {
    return (f == -1);
}

int size(int f, int r) {
    if (f == -1) return 0;
    return (r - f + 1);
}
void pushtwo(int x) {
    enqueue(q2, f2, r2, x);
    while (!isEmpty(f1)) {
        enqueue(q2, f2, r2, dequeue(q1, f1, r1));
    }
    swap(q1, q2);
    swap(f1, f2);
    swap(r1, r2);
}
int poptwo() {
    if (isEmpty(f1)) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return dequeue(q1, f1, r1);
}
int toptwo() {
    if (isEmpty(f1)) {
        cout << "Stack is Empty\n";
        return -1;
    }
    return peek(q1, f1, r1);
}

bool emptytwo() {
    return isEmpty(f1);
}
void pushone(int x) {
    enqueue(q3, f3, r3, x);
    int s = size(f3, r3);
    for (int i = 0; i < s - 1; i++) {
        enqueue(q3, f3, r3, dequeue(q3, f3, r3));
    }
}
int popone() {
    if (isEmpty(f3)) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return dequeue(q3, f3, r3);
}
int topone() {
    if (isEmpty(f3)) {
        cout << "Stack is Empty\n";
        return -1;
    }
    return peek(q3, f3, r3);
}
bool emptyone() {
    return isEmpty(f3);
}
int main() {
    int methodchoice, choice, val;
    cout << "Choose implementation:\n";
    cout << "1. Stack using Two Queues\n";
    cout << "2. Stack using One Queue\n";
    cout << "Enter choice: ";
    cin >> methodchoice;
    if (methodchoice == 1) {
        do {
            cout << "\n--- Stack using Two Queues ---\n";
            cout << "1. Push\n2. Pop\n3. Top\n4. Is Empty\n5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    pushtwo(val);
                    break;
                case 2:
                    val = poptwo();
                    if (val != -1) cout << "Popped: " << val << endl;
                    break;
                case 3:
                    val = toptwo();
                    if (val != -1) cout << "Top element: " << val << endl;
                    break;
                case 4:
                    cout << (emptytwo() ? "Stack is Empty\n" : "Stack is not Empty\n");
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice";
            }
        } while (choice != 5);
    } 
    else if (methodchoice == 2) {
        do {
            cout << " Stack using One Queue ";
            cout << "1. Push\n2. Pop\n3. Top\n4. Is Empty\n5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    pushone(val);
                    break;
                case 2:
                    val = popone();
                    if (val != -1) cout << "Popped: " << val << endl;
                    break;
                case 3:
                    val = topone();
                    if (val != -1) cout << "Top element: " << val << endl;
                    break;
                case 4:
                    cout << (emptyone() ? "Stack is Empty\n" : "Stack is not Empty\n");
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice";
            }
        } while (choice != 5);
    } 
    else {
        cout << "Invalid method choice!";
    }
    return 0;
}

