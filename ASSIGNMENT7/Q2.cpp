#include <iostream>
using namespace std;
void selectsort(int arr[], int n) {
    int start = 0;
	int end = n - 1;
    while (start < end) {
        int minpos = start;
        int maxpos = start;
        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minpos])
            minpos = i;
            if (arr[i] > arr[maxpos])
            maxpos = i;
        }
        int temp = arr[start];
        arr[start] = arr[minpos];
        arr[minpos] = temp;
        if (maxpos == start)
        maxpos = minpos;
        temp = arr[end];
        arr[end] = arr[maxpos];
        arr[maxpos] = temp;
        start++;
        end--;
    }
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    cin >> arr[i];
    selectsort(arr, n);
    cout << "Sorted array: ";
    display(arr, n);
    return 0;
}

