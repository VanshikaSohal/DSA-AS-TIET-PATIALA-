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
    int dequeue() {
        if (front == -1 || front > rear) return -1;
        return arr[front++];
    }
    int size() { return (front == -1 || front > rear) ? 0 : rear - front + 1; }
};
int main() {
    Queue q1, q2;
    int n, x; cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; q1.enqueue(x); }
    int half = n / 2;
    for (int i = 0; i < half; i++) q2.enqueue(q1.dequeue());
    while (q2.size() && q1.size()) {
        cout << q2.dequeue() << " ";
        cout << q1.dequeue() << " ";
    }
}

