#include <iostream>
using namespace std;
int missing(int arr[], int n) {
    int expectedSum = (n + 1) * (n + 2) / 2;
    int actualSum = 0;
    for (int i = 0; i < n; i++)
        actualSum += arr[i];
    return expectedSum - actualSum;
}
int usingbinarysearch(int low, int high, int A[], int n) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (A[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low + 1;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements of a sorted array:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Missing Number (using Sum method): " << missing(arr, n) << endl;
    int missingValue = usingbinarysearch(0, n - 1, arr, n);
    cout << "Missing Number (using Binary Search): " << missingValue << endl;
    return 0;
}
