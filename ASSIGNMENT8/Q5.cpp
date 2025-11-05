#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i) {
    int maxindex = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[maxindex])
	maxindex = l;
    if (r < n && arr[r] > arr[maxindex]) 
	maxindex = r;
    if (maxindex != i) {
        swap(arr[i], arr[maxindex]);
        heapify(arr, n, maxindex);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
	heapify(arr, n, i);
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Sorted array in ascending order: ";
    for (int i=0; i<n; i++) 
	cout << arr[i] << " ";
    cout << endl;
    return 0;
}

