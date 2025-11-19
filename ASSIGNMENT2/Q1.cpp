#include <iostream>
using namespace std;
int binary(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; 
}
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 50;
    int res = binary(arr, size, target);
    if (res != -1)
        cout << "Element found at index: " << res << endl;
    else
        cout << "Element not found!" << endl;
    return 0;
}

