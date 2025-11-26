#include <iostream>
using namespace std;
int distinctcount(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {     
                int temp = arr[j];        
                arr[j] = arr[j + 1];      
                arr[j + 1] = temp;        
            }
        }
    }
    int count = 1;  
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[i - 1]) {
            count++;
        }
    }
    cout << "Total distinct elements are: " << count << endl;
    return count;
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    distinctcount(arr, n);
    return 0;
}
