//UNIQUE QUESTION
#include <iostream>
using namespace std;
#define SIZE 256
class Queue {
    char arr[SIZE]; int front, rear;
public:
    Queue() { front = -1; rear = -1; }
    void enqueue(char x) {
        if (rear == SIZE - 1) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    void dequeue() {
        if (front == -1 || front > rear) return;
        front++;
    }
    char frontVal() {
        if (front == -1 || front > rear) return '#';
        return arr[front];
    }
    int empty() { return (front == -1 || front > rear); }
};
int main() {
    string s; getline(cin, s);
    Queue q; int freq[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        freq[s[i]]++;
        q.enqueue(s[i]);
        while (!q.empty() && freq[q.frontVal()] > 1) q.dequeue();
        if (q.empty()) cout << -1 << " ";
        else cout << q.frontVal() << " ";
    }
}

