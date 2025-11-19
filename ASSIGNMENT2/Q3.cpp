#include <iostream>
using namespace std;
int missing(int arr[], int n) {
    int expectedsum = (n + 1) * (n + 2) / 2; 
    int actualsum = 0;
    for (int i = 0; i < n; i++)
        actualsum += arr[i];
    return expectedsum - actualsum;
}
int main() {
    int n;
    cout << "Enter the number of elements : " << endl;
    cin >> n;
    int arr[100]; 
    cout << "Enter elements of an array: " << endl;
    for (int i = 0; i < n; i++)
    cin >> arr[i];
    cout << "Missing Number is: " << missing(arr, n) << endl;
    return 0;
}

