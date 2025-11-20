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

    bool empty() { return size() == 0; }

    int frontval() { return (front == -1 || front > rear) ? -1 : arr[front]; }
};
int main() {
    Queue q1, q2;
    int n, x; 
    cin >> n;
    for (int i = 0; i < n; i++) { 
        cin >> x; 
        q1.enqueue(x); 
    }
    int half = (n + 1) / 2;  // works for even & odd
    int secondhalf=n-half;
    for (int i = 0; i < half; i++) 
        q2.enqueue(q1.dequeue());
    int iterations = q2.size();
    for (int i = 0; i < iterations; i++) {
        q1.enqueue(q2.dequeue());    
        if (i<secondhalf)             
            q1.enqueue(q1.dequeue());
    }
    cout << "PRINTING VALUES: " << endl;
    while(!q1.empty()){
        cout << q1.frontval() << " , ";
        q1.dequeue();
    }
    return 0;
}
