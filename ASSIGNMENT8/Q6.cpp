#include <iostream>
using namespace std;
void heapify(int heap[], int n, int i) {
    int maxindex = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && heap[l] > heap[maxindex]) 
	maxindex = l;
    if (r < n && heap[r] > heap[maxindex])
	maxindex = r;
    if (maxindex != i) {
        swap(heap[i], heap[maxindex]);
        heapify(heap, n, maxindex);
    }
}
void push(int heap[], int &n, int key) {
    heap[n++] = key;
    int i = n-1;
    while (i != 0 && heap[(i-1)/2] < heap[i]) {
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}
int pop(int heap[], int &n) {
    if (n <= 0) return -1;
    int maxVal = heap[0];
    heap[0] = heap[n-1];
    n--;
    heapify(heap, n, 0);
    return maxVal;
}
int main() {
    int heap[100];
    int n = 0;
    push(heap, n, 10);
    push(heap, n, 30);
    push(heap, n, 15);
    cout << "Max element popped: " << pop(heap, n) << endl;
    return 0;
}

