#include <iostream>
using namespace std;
#define SIZE 100
class Queue {
    int arr[SIZE], front, rear;
public:
    Queue() { front = -1; rear = -1; }
    void enqueue(int x) {
        if (rear == SIZE - 1) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    void dequeue() {
        if (front == -1 || front > rear) return;
        front++;
    }
    int isEmpty() { return (front == -1 || front > rear); }
    int isFull() { return (rear == SIZE - 1); }
    void display() {
        if (front == -1 || front > rear) return;
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
    void peek() {
        if (front == -1 || front > rear) return;
        cout << arr[front] << endl;
    }
};
int main() {
    Queue q;
    int ch, val;
    do {
        cin >> ch;
        switch (ch) {
            case 1: cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: cout << q.isEmpty() << endl; break;
            case 4: cout << q.isFull() << endl; break;
            case 5: q.display(); break;
            case 6: q.peek(); break;
        }
    } while (ch != 0);
}

