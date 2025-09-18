#include <iostream>
using namespace std;
#define SIZE 100
class CQueue {
    int arr[SIZE], front, rear;
public:
    CQueue() { front = -1; rear = -1; }
    void enqueue(int x) {
        if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) return;
        if (front == -1) front = rear = 0;
        else rear = (rear + 1) % SIZE;
        arr[rear] = x;
    }
    void dequeue() {
        if (front == -1) return;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }
    int isEmpty() { return (front == -1); }
    int isFull() { return ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front); }
    void display() {
        if (front == -1) return;
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
    void peek() {
        if (front == -1) return;
        cout << arr[front] << endl;
    }
};
int main() {
    CQueue q;
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

